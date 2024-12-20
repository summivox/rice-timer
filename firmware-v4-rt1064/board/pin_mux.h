/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief 
 *
 */
void InitPinsSys(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void InitPinsSdram(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void InitPinsSd(void);

#define INITPINSFRONTPANEL_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK 0x20000000U /*!< GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function: affected bits mask */
#define INITPINSFRONTPANEL_IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK 0x04000000U /*!< GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function: affected bits mask */

/* GPIO_AD_B1_12 (coord H12), NEOPIXEL */
/* Routed pin properties */
#define PINS_FRONT_PANEL_NEOPIXEL_PERIPHERAL                             FLEXIO3   /*!< Peripheral name */
#define PINS_FRONT_PANEL_NEOPIXEL_SIGNAL                                      IO   /*!< Signal name */
#define PINS_FRONT_PANEL_NEOPIXEL_CHANNEL                                    12U   /*!< Signal channel */
#define PINS_FRONT_PANEL_NEOPIXEL_PIN_NAME                         GPIO_AD_B1_12   /*!< Routed pin name */
#define PINS_FRONT_PANEL_NEOPIXEL_LABEL                               "NEOPIXEL"   /*!< Label */
#define PINS_FRONT_PANEL_NEOPIXEL_NAME                                "NEOPIXEL"   /*!< Identifier */
#define PINS_FRONT_PANEL_NEOPIXEL_DIRECTION             kPIN_MUX_DirectionOutput   /*!< Direction */

/* GPIO_AD_B1_13 (coord H11), BUTTON_A */
/* Routed pin properties */
#define PINS_FRONT_PANEL_BUTTON_A_PERIPHERAL                               GPIO1   /*!< Peripheral name */
#define PINS_FRONT_PANEL_BUTTON_A_SIGNAL                                 gpio_io   /*!< Signal name */
#define PINS_FRONT_PANEL_BUTTON_A_CHANNEL                                    29U   /*!< Signal channel */
#define PINS_FRONT_PANEL_BUTTON_A_PIN_NAME                         GPIO_AD_B1_13   /*!< Routed pin name */
#define PINS_FRONT_PANEL_BUTTON_A_LABEL                               "BUTTON_A"   /*!< Label */
#define PINS_FRONT_PANEL_BUTTON_A_NAME                                "BUTTON_A"   /*!< Identifier */
#define PINS_FRONT_PANEL_BUTTON_A_DIRECTION              kPIN_MUX_DirectionInput   /*!< Direction */

/* Symbols to be used with GPIO driver */
#define PINS_FRONT_PANEL_BUTTON_A_GPIO                                     GPIO1   /*!< GPIO peripheral base pointer */
#define PINS_FRONT_PANEL_BUTTON_A_GPIO_PIN                                   29U   /*!< GPIO pin number */
#define PINS_FRONT_PANEL_BUTTON_A_GPIO_PIN_MASK                      (1U << 29U)   /*!< GPIO pin mask */
#define PINS_FRONT_PANEL_BUTTON_A_PORT                                     GPIO1   /*!< PORT peripheral base pointer */
#define PINS_FRONT_PANEL_BUTTON_A_PIN                                        29U   /*!< PORT pin number */
#define PINS_FRONT_PANEL_BUTTON_A_PIN_MASK                           (1U << 29U)   /*!< PORT pin mask */

/* GPIO_B1_10 (coord B13), BUTTON_B */
/* Routed pin properties */
#define PINS_FRONT_PANEL_BUTTON_B_PERIPHERAL                               GPIO2   /*!< Peripheral name */
#define PINS_FRONT_PANEL_BUTTON_B_SIGNAL                                 gpio_io   /*!< Signal name */
#define PINS_FRONT_PANEL_BUTTON_B_CHANNEL                                    26U   /*!< Signal channel */
#define PINS_FRONT_PANEL_BUTTON_B_PIN_NAME                            GPIO_B1_10   /*!< Routed pin name */
#define PINS_FRONT_PANEL_BUTTON_B_LABEL                               "BUTTON_B"   /*!< Label */
#define PINS_FRONT_PANEL_BUTTON_B_NAME                                "BUTTON_B"   /*!< Identifier */
#define PINS_FRONT_PANEL_BUTTON_B_DIRECTION              kPIN_MUX_DirectionInput   /*!< Direction */

/* Symbols to be used with GPIO driver */
#define PINS_FRONT_PANEL_BUTTON_B_GPIO                                     GPIO2   /*!< GPIO peripheral base pointer */
#define PINS_FRONT_PANEL_BUTTON_B_GPIO_PIN                                   26U   /*!< GPIO pin number */
#define PINS_FRONT_PANEL_BUTTON_B_GPIO_PIN_MASK                      (1U << 26U)   /*!< GPIO pin mask */
#define PINS_FRONT_PANEL_BUTTON_B_PORT                                     GPIO2   /*!< PORT peripheral base pointer */
#define PINS_FRONT_PANEL_BUTTON_B_PIN                                        26U   /*!< PORT pin number */
#define PINS_FRONT_PANEL_BUTTON_B_PIN_MASK                           (1U << 26U)   /*!< PORT pin mask */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void InitPinsFrontPanel(void);

/* GPIO_AD_B1_04 (coord L12), IMU_INT */
/* Routed pin properties */
#define PINS_IMU_IMU_INT_PERIPHERAL                                         GPT2   /*!< Peripheral name */
#define PINS_IMU_IMU_INT_SIGNAL                                      gpt_capture   /*!< Signal name */
#define PINS_IMU_IMU_INT_CHANNEL                                              2U   /*!< Signal channel */
#define PINS_IMU_IMU_INT_PIN_NAME                                  GPIO_AD_B1_04   /*!< Routed pin name */
#define PINS_IMU_IMU_INT_LABEL                                         "IMU_INT"   /*!< Label */
#define PINS_IMU_IMU_INT_NAME                                          "IMU_INT"   /*!< Identifier */

/* GPIO_B1_04 (coord E12), IMU_CS */
/* Routed pin properties */
#define PINS_IMU_IMU_CS_PERIPHERAL                                        LPSPI4   /*!< Peripheral name */
#define PINS_IMU_IMU_CS_SIGNAL                                              PCS0   /*!< Signal name */
#define PINS_IMU_IMU_CS_PIN_NAME                                      GPIO_B1_04   /*!< Routed pin name */
#define PINS_IMU_IMU_CS_LABEL                                           "IMU_CS"   /*!< Label */
#define PINS_IMU_IMU_CS_NAME                                            "IMU_CS"   /*!< Identifier */
#define PINS_IMU_IMU_CS_DIRECTION                       kPIN_MUX_DirectionOutput   /*!< Direction */

/* GPIO_B1_07 (coord B12), IMU_CLK */
/* Routed pin properties */
#define PINS_IMU_IMU_CLK_PERIPHERAL                                       LPSPI4   /*!< Peripheral name */
#define PINS_IMU_IMU_CLK_SIGNAL                                              SCK   /*!< Signal name */
#define PINS_IMU_IMU_CLK_PIN_NAME                                     GPIO_B1_07   /*!< Routed pin name */
#define PINS_IMU_IMU_CLK_LABEL                                         "IMU_CLK"   /*!< Label */
#define PINS_IMU_IMU_CLK_NAME                                          "IMU_CLK"   /*!< Identifier */
#define PINS_IMU_IMU_CLK_DIRECTION                      kPIN_MUX_DirectionOutput   /*!< Direction */

/* GPIO_B1_05 (coord D12), IMU_MISO */
/* Routed pin properties */
#define PINS_IMU_IMU_MISO_PERIPHERAL                                      LPSPI4   /*!< Peripheral name */
#define PINS_IMU_IMU_MISO_SIGNAL                                             SDI   /*!< Signal name */
#define PINS_IMU_IMU_MISO_PIN_NAME                                    GPIO_B1_05   /*!< Routed pin name */
#define PINS_IMU_IMU_MISO_LABEL                                       "IMU_MISO"   /*!< Label */
#define PINS_IMU_IMU_MISO_NAME                                        "IMU_MISO"   /*!< Identifier */
#define PINS_IMU_IMU_MISO_DIRECTION                      kPIN_MUX_DirectionInput   /*!< Direction */

/* GPIO_B1_06 (coord C12), IMU_MOSI */
/* Routed pin properties */
#define PINS_IMU_IMU_MOSI_PERIPHERAL                                      LPSPI4   /*!< Peripheral name */
#define PINS_IMU_IMU_MOSI_SIGNAL                                             SDO   /*!< Signal name */
#define PINS_IMU_IMU_MOSI_PIN_NAME                                    GPIO_B1_06   /*!< Routed pin name */
#define PINS_IMU_IMU_MOSI_LABEL                                       "IMU_MOSI"   /*!< Label */
#define PINS_IMU_IMU_MOSI_NAME                                        "IMU_MOSI"   /*!< Identifier */
#define PINS_IMU_IMU_MOSI_DIRECTION                     kPIN_MUX_DirectionOutput   /*!< Direction */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void InitPinsImu(void);

#define INITPINSGPS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK 0x020000U /*!< GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function: affected bits mask */

/* GPIO_AD_B1_00 (coord J11), GPS_ANT_SENSE */
/* Routed pin properties */
#define PINS_GPS_GPS_ANT_SENSE_PERIPHERAL                                   ADC1   /*!< Peripheral name */
#define PINS_GPS_GPS_ANT_SENSE_SIGNAL                                         IN   /*!< Signal name */
#define PINS_GPS_GPS_ANT_SENSE_CHANNEL                                        5U   /*!< Signal channel */
#define PINS_GPS_GPS_ANT_SENSE_PIN_NAME                            GPIO_AD_B1_00   /*!< Routed pin name */
#define PINS_GPS_GPS_ANT_SENSE_LABEL                             "GPS_ANT_SENSE"   /*!< Label */
#define PINS_GPS_GPS_ANT_SENSE_NAME                              "GPS_ANT_SENSE"   /*!< Identifier */

/* GPIO_AD_B1_01 (coord K11), GPS_ANT_SEL */
/* Routed pin properties */
#define PINS_GPS_GPS_ANT_SEL_PERIPHERAL                                    GPIO1   /*!< Peripheral name */
#define PINS_GPS_GPS_ANT_SEL_SIGNAL                                      gpio_io   /*!< Signal name */
#define PINS_GPS_GPS_ANT_SEL_CHANNEL                                         17U   /*!< Signal channel */
#define PINS_GPS_GPS_ANT_SEL_PIN_NAME                              GPIO_AD_B1_01   /*!< Routed pin name */
#define PINS_GPS_GPS_ANT_SEL_LABEL                                 "GPS_ANT_SEL"   /*!< Label */
#define PINS_GPS_GPS_ANT_SEL_NAME                                  "GPS_ANT_SEL"   /*!< Identifier */
#define PINS_GPS_GPS_ANT_SEL_DIRECTION                  kPIN_MUX_DirectionOutput   /*!< Direction */

/* Symbols to be used with GPIO driver */
#define PINS_GPS_GPS_ANT_SEL_GPIO                                          GPIO1   /*!< GPIO peripheral base pointer */
#define PINS_GPS_GPS_ANT_SEL_GPIO_PIN                                        17U   /*!< GPIO pin number */
#define PINS_GPS_GPS_ANT_SEL_GPIO_PIN_MASK                           (1U << 17U)   /*!< GPIO pin mask */
#define PINS_GPS_GPS_ANT_SEL_PORT                                          GPIO1   /*!< PORT peripheral base pointer */
#define PINS_GPS_GPS_ANT_SEL_PIN                                             17U   /*!< PORT pin number */
#define PINS_GPS_GPS_ANT_SEL_PIN_MASK                                (1U << 17U)   /*!< PORT pin mask */

/* GPIO_AD_B1_03 (coord M12), GPS_PPS */
/* Routed pin properties */
#define PINS_GPS_GPS_PPS_PERIPHERAL                                         GPT2   /*!< Peripheral name */
#define PINS_GPS_GPS_PPS_SIGNAL                                      gpt_capture   /*!< Signal name */
#define PINS_GPS_GPS_PPS_CHANNEL                                              1U   /*!< Signal channel */
#define PINS_GPS_GPS_PPS_PIN_NAME                                  GPIO_AD_B1_03   /*!< Routed pin name */
#define PINS_GPS_GPS_PPS_LABEL                                         "GPS_PPS"   /*!< Label */
#define PINS_GPS_GPS_PPS_NAME                                          "GPS_PPS"   /*!< Identifier */

/* GPIO_AD_B1_10 (coord L13), UART_TO_GPS */
/* Routed pin properties */
#define PINS_GPS_UART_TO_GPS_PERIPHERAL                                  LPUART8   /*!< Peripheral name */
#define PINS_GPS_UART_TO_GPS_SIGNAL                                           TX   /*!< Signal name */
#define PINS_GPS_UART_TO_GPS_PIN_NAME                              GPIO_AD_B1_10   /*!< Routed pin name */
#define PINS_GPS_UART_TO_GPS_LABEL                                 "UART_TO_GPS"   /*!< Label */
#define PINS_GPS_UART_TO_GPS_NAME                                  "UART_TO_GPS"   /*!< Identifier */

/* GPIO_AD_B1_11 (coord J13), UART_FROM_GPS */
/* Routed pin properties */
#define PINS_GPS_UART_FROM_GPS_PERIPHERAL                                LPUART8   /*!< Peripheral name */
#define PINS_GPS_UART_FROM_GPS_SIGNAL                                         RX   /*!< Signal name */
#define PINS_GPS_UART_FROM_GPS_PIN_NAME                            GPIO_AD_B1_11   /*!< Routed pin name */
#define PINS_GPS_UART_FROM_GPS_LABEL                             "UART_FROM_GPS"   /*!< Label */
#define PINS_GPS_UART_FROM_GPS_NAME                              "UART_FROM_GPS"   /*!< Identifier */

/* GPIO_AD_B1_07 (coord K10), GPS_I2C_SCL */
/* Routed pin properties */
#define PINS_GPS_GPS_I2C_SCL_PERIPHERAL                                   LPI2C3   /*!< Peripheral name */
#define PINS_GPS_GPS_I2C_SCL_SIGNAL                                          SCL   /*!< Signal name */
#define PINS_GPS_GPS_I2C_SCL_PIN_NAME                              GPIO_AD_B1_07   /*!< Routed pin name */
#define PINS_GPS_GPS_I2C_SCL_LABEL                                 "GPS_I2C_SCL"   /*!< Label */
#define PINS_GPS_GPS_I2C_SCL_NAME                                  "GPS_I2C_SCL"   /*!< Identifier */

/* GPIO_AD_B1_06 (coord J12), GPS_I2C_SDA */
/* Routed pin properties */
#define PINS_GPS_GPS_I2C_SDA_PERIPHERAL                                   LPI2C3   /*!< Peripheral name */
#define PINS_GPS_GPS_I2C_SDA_SIGNAL                                          SDA   /*!< Signal name */
#define PINS_GPS_GPS_I2C_SDA_PIN_NAME                              GPIO_AD_B1_06   /*!< Routed pin name */
#define PINS_GPS_GPS_I2C_SDA_LABEL                                 "GPS_I2C_SDA"   /*!< Label */
#define PINS_GPS_GPS_I2C_SDA_NAME                                  "GPS_I2C_SDA"   /*!< Identifier */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void InitPinsGps(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void InitPinsCan(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void InitPinsDebug(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/