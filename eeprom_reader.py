from sys import argv
from serial import Serial
from os import system, path


SENT_PARAMETERS = len(argv) - 1
print(SENT_PARAMETERS)
PORT = argv[1] if SENT_PARAMETERS == 1 else 'COM3'
FILE_NAME = argv[2] if SENT_PARAMETERS > 1 else 'EEPROM.bin'
EEPROM_SIZE = 256
SAVED_FILE_SIZE = 0
saved_data = b''

if not ('.bin' or '.BIN') in FILE_NAME:
    FILE_NAME += '.bin'

if path.isfile(FILE_NAME):
    print(FILE_NAME + ' exists, use other name or move file')

try:
    serial_connection = Serial(
        port=PORT,
        baudrate=9600,
        timeout=.3,
        rtscts=True
    )
except:
    print('Could not open port ' + PORT)
    exit()

while SAVED_FILE_SIZE != EEPROM_SIZE:
    data = serial_connection.readline()
    print(data)
    saved_data += data 
    SAVED_FILE_SIZE += len(data)
    print(SAVED_FILE_SIZE)


file = open(FILE_NAME, 'wb')
file.write(saved_data)
file.close()



system('pause')
