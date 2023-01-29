
## Arduino Xbox EEPROM Reader
This project is based on [ExtraordinayBen](https://github.com/ExtraordinaryBen)/[DuinoBox](https://github.com/ExtraordinaryBen/DuinoBoX) and contains some arduino code from his project.

Instead of saving the EEPROM into arduino memory it sends to the PC as serial messages, and a simple python script saves as an eeprom file.
___
**Wiring**
|Arduino Uno|Xbox LPC|
|--|--|
|SDA - A4| SDA - 14  |
|SCL - A5 | SCL - 13 |
|GND - GND| GND - 2/12 |

___
TODO:

 - [ ] Upload progress.
 - [ ] A more optimized and functional python script.
 - [ ] GUI Based app for eeprom reading/saving.
 - [ ] Simplify and rewrite arduino code.
