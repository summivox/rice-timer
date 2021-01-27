#include <optional>
#include <string>
#include "fmt/core.h"
#include "sys/stat.h"

#include "driver/sdmmc_host.h"
#include "driver/spi_common.h"
#include "esp_vfs_fat.h"
#include "freertos/FreeRTOS.h"
#include "sdmmc_cmd.h"

#include "can.hpp"
#include "capture_manager.hpp"
#include "common.hpp"
#include "gps.hpp"
#include "logger.hpp"
#include "pps.hpp"
#include "ui/view.hpp"

namespace {

constexpr char TAG[] = "main";
constexpr int kSdCardMaxFreqKhz = 20'000;
constexpr int kI2cMaxFreqHz = 400'000;

constexpr gpio_num_t kLedPin = GPIO_NUM_13;

}  // namespace

sdmmc_card_t* g_sdcard{};
esp_err_t SetupFileSystemSpi() {
  sdmmc_host_t host_config = SDSPI_HOST_DEFAULT();
  host_config.slot = HSPI_HOST;
  host_config.max_freq_khz = kSdCardMaxFreqKhz;

  sdspi_device_config_t io_config = SDSPI_DEVICE_CONFIG_DEFAULT();
  io_config.gpio_cs = GPIO_NUM_33;

  esp_vfs_fat_mount_config_t mount_config{
      .format_if_mount_failed = false,
      .max_files = 4,
      .allocation_unit_size = CONFIG_WL_SECTOR_SIZE,
  };

  spi_bus_config_t bus_cfg = {
      .mosi_io_num = 18,
      .miso_io_num = 19,
      .sclk_io_num = 5,
      .quadwp_io_num = -1,
      .quadhd_io_num = -1,
      .max_transfer_sz = 0,
      .flags = 0,
      .intr_flags = 0,
  };
  TRY(spi_bus_initialize(HSPI_HOST, &bus_cfg, HSPI_HOST));
  TRY(esp_vfs_fat_sdspi_mount(
      CONFIG_MOUNT_ROOT, &host_config, &io_config, &mount_config, &g_sdcard));
  return ESP_OK;
}
esp_err_t SetupFileSystemSdio() {
  sdmmc_host_t host_config = SDMMC_HOST_DEFAULT();
  sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
  slot_config.width = 4;
#if 0
  gpio_set_pull_mode(GPIO_NUM_15, GPIO_PULLUP_ONLY);   // CMD, needed in 4- and 1- line modes
  gpio_set_pull_mode(GPIO_NUM_2, GPIO_PULLUP_ONLY);    // D0, needed in 4- and 1-line modes
  gpio_set_pull_mode(GPIO_NUM_4, GPIO_PULLUP_ONLY);    // D1, needed in 4-line mode only
  gpio_set_pull_mode(GPIO_NUM_12, GPIO_PULLUP_ONLY);   // D2, needed in 4-line mode only
  gpio_set_pull_mode(GPIO_NUM_13, GPIO_PULLUP_ONLY);   // D3, needed in 4- and 1-line modes
#endif

  esp_vfs_fat_mount_config_t mount_config{
      .format_if_mount_failed = false,
      .max_files = 4,
      .allocation_unit_size = CONFIG_WL_SECTOR_SIZE,
  };
  TRY(esp_vfs_fat_sdmmc_mount(
      CONFIG_MOUNT_ROOT, &host_config, &slot_config, &mount_config, &g_sdcard));
  return ESP_OK;
}

esp_err_t SetupFileSystem() {
  if (CONFIG_SD_CARD_4BIT) {
    TRY(SetupFileSystemSdio());
  } else {
    TRY(SetupFileSystemSpi());
  }
  sdmmc_card_print_info(stdout, g_sdcard);
  FILE* ftest;
  ftest = fopen(CONFIG_MOUNT_ROOT "/test.txt", "w");
  fputs("12345", ftest);
  fclose(ftest);
  ftest = fopen(CONFIG_MOUNT_ROOT "/test.txt", "r");
  static char buf[100] = {};
  fgets(buf, 100, ftest);
  ESP_LOGW(TAG, "read: %s", buf);
  TRY(mkdir(CONFIG_MOUNT_ROOT "/ghi", 0777) == 0 || errno == EEXIST ? ESP_OK : ESP_FAIL);
  TRY(mkdir(CONFIG_MOUNT_ROOT "/ghi/jkl", 0777) == 0 || errno == EEXIST ? ESP_OK : ESP_FAIL);
  return ESP_OK;
}

TaskHandle_t g_main_task{};
void MainTask(void* /* unused */) {
  vTaskDelay(pdMS_TO_TICKS(2000));  // let monitor connect

  heap_caps_print_heap_info(MALLOC_CAP_8BIT);
  CHECK_OK(SetupFileSystem());

  CHECK_OK(LoggerInit());
  // CHECK_OK(PpsInit());
  // CHECK_OK(GpsInit());
  CHECK_OK(CanInit());
  CHECK_OK(ui::ViewInit());

  CHECK_OK(LoggerStart());
  // CHECK_OK(PpsStart());
  // CHECK_OK(GpsStart());
  CHECK_OK(CanStart());
  CHECK_OK(ui::ViewStart());

  vTaskDelete(nullptr);
}

#define LOG_WATER_MARK(name, task) \
  ESP_LOGI("canary", name ": %d", (task) ? uxTaskGetStackHighWaterMark((task)) : -1)

TaskHandle_t g_canary_task{};
void CanaryTask(void* /*unused*/) {
  // gpio_pad_select_gpio(kLedPin);
  // gpio_set_direction(kLedPin, GPIO_MODE_OUTPUT);

  bool led_state = false;
  TickType_t last_wake_tick = xTaskGetTickCount();
  while (true) {
    led_state = !led_state;
    // gpio_set_level(kLedPin, led_state);
    static int k = 9;
    if (++k == 10) {
      k = 0;
      LOG_WATER_MARK("canary", g_canary_task);
      LOG_WATER_MARK("logger", g_logger_task);
      LOG_WATER_MARK("pps", g_pps_task);
      LOG_WATER_MARK("gps", g_gps_task);
      LOG_WATER_MARK("can", g_can_task);
      LOG_WATER_MARK("ui/view", ui::g_view_task);
    }
    vTaskDelayUntil(&last_wake_tick, pdMS_TO_TICKS(1000));
  }
}

extern "C" void app_main(void) {
  esp_log_level_set(TAG, ESP_LOG_INFO);
  esp_log_level_set("canary", ESP_LOG_INFO);

#if 0
  Serial.begin(kConsoleBaudHz);
  Wire.begin(23, 22, kI2cMaxFreqHz);
  Wire.begin(25, 26, kI2cMaxFreqHz);
#endif

  xTaskCreatePinnedToCore(CanaryTask,
                          "canary",
                          2560,
                          /*arg*/ nullptr,
                          configMAX_PRIORITIES - 2,
                          &g_canary_task,
                          PRO_CPU_NUM);
  xTaskCreatePinnedToCore(
      MainTask, "main", 4096, /*arg*/ nullptr, configMAX_PRIORITIES - 1, &g_main_task, APP_CPU_NUM);
}
