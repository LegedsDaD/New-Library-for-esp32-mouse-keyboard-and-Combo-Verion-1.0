#ifndef DEBUG_H
#define DEBUG_H


#include <Arduino.h>


#ifndef HID_DEBUG
#define HID_DEBUG 0
#endif


#if HID_DEBUG
#define HID_DBG_PRINTLN(x) Serial.println(x)
#define HID_DBG_PRINT(x) Serial.print(x)
#else
#define HID_DBG_PRINTLN(x)
#define HID_DBG_PRINT(x)
#endif


#endif // DEBUG_H
