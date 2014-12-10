#include "application.h"
#include "TMP006.h"


uint8_t sensor1 = 0x40; // I2C address of TMP006, can be 0x40-0x47
uint16_t samples = TMP006_CFG_8SAMPLE; // # of samples per reading, can be 1/2/4/8/16

TMP006 tmp;

void setup()
{
    Serial.begin(9600);
    while (!Serial.available())  // Wait here until the user presses ENTER
        SPARK_WLAN_Loop();        // in the Serial Terminal. Call the BG Tasks

    // Begin tmp006 measuring
    tmp.begin();
    Serial.println("TMP006 Example");
}

void loop()
{
    float object_temp = tmp.readObjTempC();
    Serial.print("Object Temperature: ");
    Serial.print(object_temp); Serial.println("*C");

    float sensor_temp = tmp.readDieTempC();
    Serial.print("Sensor Temperature: ");
    Serial.print(sensor_temp); Serial.println("*C");

    delay(2000); // delay 1 second for every 4 samples per reading
}