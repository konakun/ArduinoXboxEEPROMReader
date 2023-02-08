from sys import argv
from serial import Serial
from os import system


PORT = argv[1]
SENT_PARAMETERS = len(argv) - 1
FILE_NAME = argv[2] if SENT_PARAMETERS > 1 else 'EEPROM.bin'
EEPROM_SIZE = 256
SAVED_FILE_SIZE = 0
saved_data = b''

if not ('.bin' or '.BIN') in FILE_NAME:
    FILE_NAME += '.bin'

try:
    serial_connection = Serial(
        port=PORT,
        baudrate=9600,
        timeout=5,
        rtscts=True
    )
except:
    print('Could not open port ' + PORT)
    exit()

while SAVED_FILE_SIZE != EEPROM_SIZE:
    text_entry = input()
    
    data = bytes(text_entry, "ascii")
    print(data)
    print(len(data))
    saved_data += data 
    SAVED_FILE_SIZE += len(data)
    serial_connection.write(data)

system('pause')
