#include <Wire.h>

#define XBOX_EEPROM_START   0x54
#define XBOX_EEPROM_SIZE     256

#define LED LED_BUILTIN

void setup(void)
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    Wire.begin();
}

void loop()
{
    if(Serial.available() > 0)
    {
        turnOnLED(LED)
        if (testConnection())
        {
            readEEPROM();
        }
    }
}

void readEEPROM()
{   
    int memorySection = 0
    if (testConnection()){
        while(address < XBOX_EEPROM_SIZE){
            turnOffLED(LED)
            Serial.write(sectionRead(memorySection));
            memorySection++;
        }
    }
}

void sectionRead(byte location)
{
    byte readedData = 0xFF;

    Wire.beginTransmission(XBOX_EEPROM_START);
    Wire.write(location);
    Wire.endTransmission();

    Wire.requestFrom(XBOX_EEPROM_START, (byte)0x01);

    if (Wire.available())
    {
        readedData = Wire.read()
    }

    return readedData
}

void testConnection()
{
    Wire.beginTransmission(XBOX_EEPROM_START);
    return Wire.endTransmission() == 0;
}

void turnOffLED(int pin)
{
    digitalWrite(pin, LOW)
}

void turnOnLED(int pin)
{
    digitalWrite(pin, HIGH)
}