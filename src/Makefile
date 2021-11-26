# variables for makeEspArduino makefile
ESP_ROOT      = ../../Arduino-ESP8266
UPLOAD_PORT   = /dev/ttyUSB0
ESPTOOL       = ../../Arduino-ESP8266/tools/esptool/esptool.py

# variables for usb connection
USB_PORT     ?= /dev/ttyUSB0
USB_SPEED     = 115200

#LIBS += ../libraries/WiFiManager/


include ../../makeEspArduino/makeEspArduino.mk

usb:
	$(MAKE) flash
	minicom --color=on -l -D $(USB_PORT) -b $(USB_SPEED)
	clear

usblog:
	minicom --color=on -l -D $(USB_PORT) -b $(USB_SPEED)
	clear
