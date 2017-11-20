// *** Jan Willem Kooi
// Telemetric system for RC planes
// Measures air pressure to calculate altitude and battery voltage
// and sends it via HC-12 (433Mhz) to RC pilot
// Arduino Pro-Mini - ATMega 328 (5V, 16Mhz)
// Programmer AVR ISP
// Transmitter site to put in RC plane
//
// release notes
// 5 mrt 2017: combination HC12 + BMP180 sketches
// 23 mrt 2017: added EasyTransfer
// 26 jun 2017: test notepad++

//HC-12 messenger send/receive
//autor Tom Heylen tomtomheylen.com

//BMP180 Compiled by Leo Nutz
//  www.ALTDuino.de


//*** BMP180
#include <Wire.h>

#define ADDRESS_SENSOR 0x77                 // Sensor address

int16_t  ac1, ac2, ac3, b1, b2, mb, mc, md; // Store sensor PROM values from BMP180
uint16_t ac4, ac5, ac6;                     // Store sensor PROM values from BMP180
// Ultra Low Power       OSS = 0, OSD =  5ms
// Standard              OSS = 1, OSD =  8ms
// High                  OSS = 2, OSD = 14ms
// Ultra High Resolution OSS = 3, OSD = 26ms
const uint8_t oss = 2;                      // Set oversampling setting
const uint8_t osd = 14;                     // with corresponding oversampling delay

float T, P;                                 // Set global variables for temperature and pressure

//*** HC-12
#include <SoftwareSerial.h>
SoftwareSerial hc12Serial(2, 3); //RX = D2, TX = D3, SET = D4

//*** EasyTransfer
#include <EasyTransfer.h>

//create object
EasyTransfer ET;                              // The TX is sending 7 to 8 times per second

struct SEND_DATA_STRUCTURE {
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  uint16_t battery = 0;           // battery status in mV
  int32_t temperature = 0;        // airtemperatD2ure in celsius
  float pressure = 0;             // pressure in

};

//give a name to the group of data
SEND_DATA_STRUCTURE rcData;

//** hardware
#define batteryPin 0            // connection to measure battery voltage


