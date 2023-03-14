#include <Wire.h>

#define XBOX_EEPROM_START   0x54
#define XBOX_EEPROM_SIZE     256

#define LED 13

void setup(void)
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    Wire.begin();
}

void loop()
{
    if(true)
    {
        turnOnLED(LED);
        if (testConnection())
        {
            Serial.print("Test Connection");
            delay(1000);
            readEEPROM();
        }
    }
}

void readEEPROM()
{   
    int memorySection = 0;
    if (testConnection()){
        while(memorySection < XBOX_EEPROM_SIZE){
            Serial.write(memorySection);
            turnOffLED(LED);
            delay(1000);
            Serial.write(readEEPROM(XBOX_EEPROM_START, memorySection));
            delay(1000);
            memorySection++;
        }
    }
}

byte readEEPROM(byte deviceaddress, byte eeaddress) 
{
  turnOnLED(LED);
  
  byte rdata = 0xFF;

  //Set address on EEPROM to read
  Wire.beginTransmission(deviceaddress);
  Wire.write(eeaddress); 
  Wire.endTransmission();
 
  Wire.requestFrom(deviceaddress,(byte)0x01);
 
  if (Wire.available())
    rdata = Wire.read();

  Serial.write(rdata);
  
  return rdata;
}

bool testConnection()
{
    Wire.beginTransmission(XBOX_EEPROM_START);
    return Wire.endTransmission() == 0;
}

void turnOffLED(int pin)
{
    digitalWrite(pin, LOW);
}

void turnOnLED(int pin)
{
    digitalWrite(pin, HIGH);
}