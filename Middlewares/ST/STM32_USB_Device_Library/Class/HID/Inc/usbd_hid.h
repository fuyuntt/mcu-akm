/**
  ******************************************************************************
  * @file    usbd_hid.h
  * @author  MCD Application Team
  * @brief   Header file for the usbd_hid_core.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                      www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USB_HID_H
#define __USB_HID_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include  "usbd_ioreq.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_HID
  * @brief This file is the Header file for usbd_hid.c
  * @{
  */


/** @defgroup USBD_HID_Exported_Defines
  * @{
  */

/* 键盘端点 */
#define HID_KB_EPIN_ADDR                              0x81U
#define HID_KB_EPIN_SIZE                              0x08U
#define HID_KB_EPOUT_ADDR                             0x01U
#define HID_KB_EPOUT_SIZE                             0x08U

/* 鼠标端点 */
#define HID_MOUSE_EPIN_ADDR                           0x82U
#define HID_MOUSE_EPIN_SIZE                           0x04U

/* 控制键鼠端点 */
#define HID_CKB_EPOUT_ADDR                              0x03U
#define HID_CKB_EPOUT_SIZE                              0x08U
#define HID_CMO_EPOUT_ADDR                              0x04U
#define HID_CMO_EPOUT_SIZE                              0x04U

#define USB_HID_CONFIG_DESC_SIZ                    98U
#define USB_HID_DESC_SIZ                           9U
#define USB_KB_OFF_HID_DESC                        18U
#define USB_MOUSE_OFF_HID_DESC                     50U
#define USB_CUSTOM_OFF_HID_DESC                    75U

/* 鼠标报告描述符大小 */
#define HID_MOUSE_REPORT_DESC_SIZE                 54U
/* 键盘报告描述符大小 */
#define HID_KB_REPORT_DESC_SIZE                    63U
/* 控制报告描述符大小 */
#define HID_CUSTOM_REPORT_DESC_SIZE                20U

#define HID_DESCRIPTOR_TYPE                        0x21U
#define HID_REPORT_DESC                            0x22U

#ifndef HID_HS_BINTERVAL
#define HID_HS_BINTERVAL                           0x07U
#endif /* HID_HS_BINTERVAL */

#ifndef HID_FS_BINTERVAL
#define HID_FS_BINTERVAL                           0x0AU
#endif /* HID_FS_BINTERVAL */

#define HID_REQ_SET_PROTOCOL                       0x0BU
#define HID_REQ_GET_PROTOCOL                       0x03U

#define HID_REQ_SET_IDLE                           0x0AU
#define HID_REQ_GET_IDLE                           0x02U

#define HID_REQ_SET_REPORT                         0x09U
#define HID_REQ_GET_REPORT                         0x01U
/**
  * @}
  */


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
typedef enum {
    HID_IDLE = 0,
    HID_BUSY,
} HID_StateTypeDef;


typedef struct {
    uint32_t Protocol;
    uint32_t IdleState;
    uint32_t AltSetting;
    HID_StateTypeDef state;
} USBD_HID_HandleTypeDef;
/**
  * @}
  */



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */

extern USBD_ClassTypeDef USBD_HID;
#define USBD_HID_CLASS &USBD_HID
/**
  * @}
  */

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */
uint8_t USBD_HID_TransmitReport(USBD_HandleTypeDef *pdev, uint8_t epAddr, uint8_t *report, uint16_t len);

uint32_t USBD_HID_GetPollingInterval(USBD_HandleTypeDef *pdev);

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* __USB_HID_H */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
