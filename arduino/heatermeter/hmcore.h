// HeaterMeter Copyright 2011 Bryan Mayland <bmayland@capnbry.net> 
#ifndef __HMCORE_H__
#define __HMCORE_H__

//#define HEATERMETER_BUTTONLCD  // enable user interface buttons and LED
//#define HEATERMETER_WIRELESS_NETWORKING  // enable wifi interface
#define HEATERMETER_JEENODE  // Enable JeeLabs hardware build
#define HEATERMETER_SERIAL 115200 // enable serial interface
//#define HEATERMETER_RFM12  RF12_915MHZ  // enable RFM12B receiving (433MHZ|868MHZ|915MHZ)
//#define USE_EXTERNAL_VREF       // Using external 5V as reference to analog inputs
#define PIEZO_HZ 4000             // enable piezo buzzer at this frequency

#ifdef HEATERMETER_WIRELESS_NETWORKING
#define DFLASH_SERVING          // Serve web pages out of dflash
#endif

#ifdef HEATERMETER_BUTTONLCD
#include "ShiftRegLCD.h"
#endif /* HEATERMETER_BUTTONLCD */
#include "hmmenus.h"

#include "grillpid.h"

//#ifdef HEATERMETER_JEENODE
#define PIN_ANALOG_PORT 1
//#else
// Analog Pins
// Number in the comment is physical pin on ATMega328
#define PIN_PIT     5       // 28
#define PIN_FOOD1   4       // 27
#define PIN_FOOD2   3       // 26
#define PIN_AMB     2       // 25
#define PIN_BUTTONS 0       // 23
//#endif /* HEATERMETER_JEENODE */

// Digital Output Pins
#define PIN_SERIALRX     0  // 2 Can not be changed
#define PIN_SERIALTX     1  // 3 Can not be changed
#define PIN_INTERRUPT    2  // 4

//#ifdef HEATERMETER_JEENODE
#define PIN_MOTOR_PORT   1
//#else
#define PIN_BLOWER       3  // 5
//#endif /* HEATERMETER_JEENODE */

#ifdef HEATERMETER_BUTTONLCD
#define PIN_LCD_CLK      4  // 6
#define PIN_LCD_BACKLGHT 5  // 11
#define PIN_LCD_DATA     8  // 14
#endif /* HEATERMETER_BUTTONLCD */

#define PIN_ALARM        6  // 12
#define PIN_SOFTRESET    7  // 13 DataFlash SS on WiShield
#define PIN_WIRELESS_LED 9  // 15
#define PIN_SPI_SS      10  // 16
#define PIN_SPI_MOSI    11  // 17 Can not be changed
#define PIN_SPI_MISO    12  // 18 Can not be changed
#define PIN_SPI_SCK     13  // 19 Can not be changed

void hmcoreSetup(void);
void hmcoreLoop(void);

#ifdef HEATERMETER_BUTTONLCD
void updateDisplay(void);
void lcdprint_P(const prog_char *p, const boolean doClear);
#endif /* HEATERMETER_BUTTONLCD */

void eepromLoadConfig(boolean forceDefault);
void storeSetPoint(int sp);
void storeProbeName(unsigned char probeIndex, const char *name);
void loadProbeName(unsigned char probeIndex);
void storeProbeOffset(unsigned char probeIndex, int offset);
void storeProbeAlarmOn(unsigned char probeIndex, boolean isHigh, boolean value);
void storeProbeAlarmVal(unsigned char probeIndex, boolean isHigh, int value);
void storeMaxFanSpeed(unsigned char maxFanSpeed);

#define LIDPARAM_OFFSET 0
#define LIDPARAM_DURATION 1
#define LIDPARAM_ACTIVE 2
void storeLidParam(unsigned char idx, int val);

extern GrillPid pid;
#ifdef HEATERMETER_BUTTONLCD
extern ShiftRegLCD lcd;
#endif /* HEATERMETER_BUTTONLCD */

#endif /* __HMCORE_H__ */
