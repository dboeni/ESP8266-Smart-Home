#ifndef _ESP8266_with_DHT22_H_
#define _ESP8266_with_DHT22_H_
#include "Arduino.h"
#include "secrets.h"

//#define CFG_DEBUG

/*===================================================================================================================*/
/* Select device which this SW will be built for */
/*===================================================================================================================*/
#define cThermostat  0
#define cS20         1
#define CFG_DEVICE   cThermostat

/*===================================================================================================================*/
/* Configuration */
/*===================================================================================================================*/
#if (CFG_DEVICE == cThermostat)
#define SENSOR_UPDATE_INTERVAL      20000 /* 20s in milliseconds -> time between reading sensor */
#define MQTT_RECONNECT_TIME         20000
#define CFG_MQTT_CLIENT             true
#define CFG_HTTP_UPDATE             true
#define CFG_SPIFFS                  true
#define CFG_OTA                     true
#define CFG_DISPLAY                 true
#define CFG_SENSOR                  true
#define CFG_ROTARY_ENCODER          true
#define CFG_HEATING_CONTROL         true
#elif (CFG_DEVICE == cS20)
#define MQTT_RECONNECT_TIME         20000
#define CFG_MQTT_CLIENT             true
#define CFG_HTTP_UPDATE             true
#define CFG_SPIFFS                  true
#define CFG_OTA                     true
#define CFG_DISPLAY                 false
#define CFG_SENSOR                  false
#define CFG_ROTARY_ENCODER          false
#define CFG_HEATING_CONTROL         false
#endif /* CFG_DEVICE */



/*===================================================================================================================*/
/* GPIO config */
/*===================================================================================================================*/
#if CFG_DEVICE == cThermostat
#define dhtPin              2 /* sensor */
#define sdaPin              4 /* I�C */
#define sclPin              5 /* I�C */
#define encoderPin1        12 /* rotary left/right */
#define encoderPin2        13 /* rotary left/right */
#define encoderSwitchPin   14 /* push button switch */
#define relayPin           16 /* relay control */
#elif CFG_DEVICE == cS20
#define relayPin           12 /* relay control */
#define togglePin           0 /* pin connected to HW button to toggle relay */
#define ledPin             13 /* drive LED */
#endif

/*===================================================================================================================*/
/* defines */
/*===================================================================================================================*/
/* WiFi */
#define wifiConnectTime   30   /*  try to connect to WiFi at startup for x seconds */

#if CFG_SENSOR
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#endif

/* display */
#if CFG_DISPLAY == true
#define drawTempYOffset       16
#define drawTargetTempYOffset 0
#define drawHeating drawXbm(0,drawTempYOffset,myThermo_width,myThermo_height,myThermo)
#endif

#if CFG_ROTARY_ENCODER
#define rotLeft              -1
#define rotRight              1
#define rotInit               0
#define tempStep              5
#define displayTemp           0
#define displayHumid          1
#define switchDebounceTime  250
#endif

#if CFG_MQTT_CLIENT
#if CFG_DEVICE == cThermostat
#define MQTT_MAIN_TOPIC "/heating/"
#elif CFG_DEVICE == cS20
#define MQTT_MAIN_TOPIC "/sonoff/"
#else
#error "no mqtt main topic defined for this device"
#endif /* CFG_DEVICE */
#endif /* CFG_MQTT_CLIENT */

#endif /* _ESP8266_with_DHT22_H_ */
