























.build/uno/Servo/Servo.o : /Applications/Arduino.app/Contents/Resources/Java/libraries/Servo/Servo.cpp
	@echo [93mServo/Servo.cpp[0m
	@mkdir -p .build/uno/Servo
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/libraries/Servo/Servo.cpp
include .build/uno/Servo/Servo.d



.build/uno/Servo/libServo.a : .build/uno/Servo/Servo.o
	@echo [92mLinking libServo.a[0m
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-ar rcs $@ $^







.build/uno/Wire/utility/twi.o : /Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility/twi.c
	@echo [93mWire/utility/twi.c[0m
	@mkdir -p .build/uno/Wire/utility
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility/twi.c
include .build/uno/Wire/utility/twi.d






.build/uno/Wire/Wire.o : /Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/Wire.cpp
	@echo [93mWire/Wire.cpp[0m
	@mkdir -p .build/uno/Wire
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/Wire.cpp
include .build/uno/Wire/Wire.d



.build/uno/Wire/libWire.a : .build/uno/Wire/utility/twi.o .build/uno/Wire/Wire.o
	@echo [92mLinking libWire.a[0m
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-ar rcs $@ $^







.build/uno/arduino/WInterrupts.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/WInterrupts.c
	@echo [93marduino/WInterrupts.c[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/WInterrupts.c
include .build/uno/arduino/WInterrupts.d

.build/uno/arduino/wiring.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring.c
	@echo [93marduino/wiring.c[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring.c
include .build/uno/arduino/wiring.d

.build/uno/arduino/wiring_analog.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_analog.c
	@echo [93marduino/wiring_analog.c[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_analog.c
include .build/uno/arduino/wiring_analog.d

.build/uno/arduino/wiring_digital.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_digital.c
	@echo [93marduino/wiring_digital.c[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_digital.c
include .build/uno/arduino/wiring_digital.d

.build/uno/arduino/wiring_pulse.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_pulse.c
	@echo [93marduino/wiring_pulse.c[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_pulse.c
include .build/uno/arduino/wiring_pulse.d

.build/uno/arduino/wiring_shift.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_shift.c
	@echo [93marduino/wiring_shift.c[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/wiring_shift.c
include .build/uno/arduino/wiring_shift.d






.build/uno/arduino/CDC.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/CDC.cpp
	@echo [93marduino/CDC.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/CDC.cpp
include .build/uno/arduino/CDC.d

.build/uno/arduino/HardwareSerial.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/HardwareSerial.cpp
	@echo [93marduino/HardwareSerial.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/HardwareSerial.cpp
include .build/uno/arduino/HardwareSerial.d

.build/uno/arduino/HID.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/HID.cpp
	@echo [93marduino/HID.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/HID.cpp
include .build/uno/arduino/HID.d

.build/uno/arduino/IPAddress.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/IPAddress.cpp
	@echo [93marduino/IPAddress.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/IPAddress.cpp
include .build/uno/arduino/IPAddress.d

.build/uno/arduino/main.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/main.cpp
	@echo [93marduino/main.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/main.cpp
include .build/uno/arduino/main.d

.build/uno/arduino/new.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/new.cpp
	@echo [93marduino/new.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/new.cpp
include .build/uno/arduino/new.d

.build/uno/arduino/Print.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/Print.cpp
	@echo [93marduino/Print.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/Print.cpp
include .build/uno/arduino/Print.d

.build/uno/arduino/Stream.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/Stream.cpp
	@echo [93marduino/Stream.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/Stream.cpp
include .build/uno/arduino/Stream.d

.build/uno/arduino/Tone.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/Tone.cpp
	@echo [93marduino/Tone.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/Tone.cpp
include .build/uno/arduino/Tone.d

.build/uno/arduino/USBCore.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/USBCore.cpp
	@echo [93marduino/USBCore.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/USBCore.cpp
include .build/uno/arduino/USBCore.d

.build/uno/arduino/WMath.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/WMath.cpp
	@echo [93marduino/WMath.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/WMath.cpp
include .build/uno/arduino/WMath.d

.build/uno/arduino/WString.o : /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/WString.cpp
	@echo [93marduino/WString.cpp[0m
	@mkdir -p .build/uno/arduino
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino/WString.cpp
include .build/uno/arduino/WString.d



.build/uno/arduino/libarduino.a : .build/uno/arduino/WInterrupts.o .build/uno/arduino/wiring.o .build/uno/arduino/wiring_analog.o .build/uno/arduino/wiring_digital.o .build/uno/arduino/wiring_pulse.o .build/uno/arduino/wiring_shift.o .build/uno/arduino/CDC.o .build/uno/arduino/HardwareSerial.o .build/uno/arduino/HID.o .build/uno/arduino/IPAddress.o .build/uno/arduino/main.o .build/uno/arduino/new.o .build/uno/arduino/Print.o .build/uno/arduino/Stream.o .build/uno/arduino/Tone.o .build/uno/arduino/USBCore.o .build/uno/arduino/WMath.o .build/uno/arduino/WString.o
	@echo [92mLinking libarduino.a[0m
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-ar rcs $@ $^















.build/uno/src/sketch.o : .build/uno/src/sketch.cpp
	@echo [93msrc/sketch.cpp[0m
	@mkdir -p .build/uno/src
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-g++ -mmcu=atmega328p -ffunction-sections -fdata-sections -g -Os -w -DF_CPU=16000000L -DARDUINO=100 -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/variants/standard -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Servo -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire -I/Applications/Arduino.app/Contents/Resources/Java/libraries/Wire/utility -I/Applications/Arduino.app/Contents/Resources/Java/hardware/arduino/cores/arduino -fno-exceptions -iquote src  -o $@ -c .build/uno/src/sketch.cpp
include .build/uno/src/sketch.d







.build/uno/firmware.elf : .build/uno/src/sketch.o .build/uno/Servo/libServo.a .build/uno/Wire/libWire.a .build/uno/arduino/libarduino.a
	@echo [92mLinking firmware.elf[0m
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-gcc -Os -Wl,--gc-sections -mmcu=atmega328p -o $@ $^ -lm


.build/uno/firmware.hex : .build/uno/firmware.elf
	@echo [92mConverting to firmware.hex[0m
	@/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-objcopy -O ihex -R .eeprom $^ $@

include .build/uno/src/dependencies.d .build/uno/arduino/dependencies.d .build/uno/Servo/dependencies.d .build/uno/Wire/dependencies.d

all : .build/uno/firmware.hex
	@true

