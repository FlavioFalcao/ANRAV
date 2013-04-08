default:
	avr-g++ -L./lib -I./include -I./newlibs -L./newlibs -Wall -DF_CPU=16000000UL -Os -mmcu=atmega328p -o main.elf ANRAV.cpp -larduino
	avr-objcopy -O ihex -R .eeprom main.elf out.hex
upload:
	avrdude -c arduino -p m328p -b 57600 -P /dev/ttyUSB0 -U flash:w:out.hex

all: default upload
