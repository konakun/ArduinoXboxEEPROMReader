#include <Wire.h>
#include <EEPROM.h>    
 
#define EEPROM_ADDRESS   0x54  //Address of Xbox EEPROM is 0x54
#define XBOX_EEPROM_SIZE 256   //Xbox EEPROM is 256 bytes

int address = 0;
byte tempRead = 0;
boolean receivedData = false;
 
void setup(void)
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  getEEPROM();
  
}
 
void loop()
{
  if(Serial.available() > 0) {
    tempRead = Serial.read(); //Expects only one byte sent from PC
    receivedData = true;
    getEEPROM();
  }
}

void getEEPROM()
{
  bool xboxDetected = testEEPROM(EEPROM_ADDRESS);
  if(xboxDetected) {
    address = 0;
    while(address < XBOX_EEPROM_SIZE) {
      Serial.write(readEEPROM(EEPROM_ADDRESS, address)); //Send Xbox EEPROM to PC
      address++;
    }
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    Serial.print("EEPROM NOT FOUND!\0");
  }   
}

int testEEPROM(byte deviceaddress)
{
  Wire.beginTransmission(deviceaddress);
  return Wire.endTransmission() == 0;
}

byte readEEPROM(byte deviceaddress, byte eeaddress ) 
{
  byte rdata = 0xFF;

  //Set address on EEPROM to read
  Wire.beginTransmission(deviceaddress);
  Wire.write(eeaddress); 
  Wire.endTransmission();
 
  Wire.requestFrom(deviceaddress,(byte)0x01);
 
  if (Wire.available())
    rdata = Wire.read();
 
  return rdata;
}
