-include ../Makefile.config

# variables for makeEspArduino makefile
ESP_ROOT      = ../../Arduino-ESP8266
UPLOAD_PORT   = /dev/ttyUSB0
ESPTOOL       = ../../Arduino-ESP8266/tools/esptool/esptool.py

# variables for usb connection
USB_PORT     ?= /dev/ttyUSB0
USB_SPEED     = 115200

# set CPU frequency
F_CPU 				= 160000000L

BUILD_EXTRA_FLAGS += -DWIFI_SSID=\"$(WIFI_SSID)\" 	\
										 -DWIFI_PASW=\"$(WIFI_PASW)\"   \
										 -DSERVER_URL=\"$(SERVER_URL)\" \
										 -DSERVER_PORT=$(SERVER_PORT) 	\
										 -DSERVER_API_KEY=\"$(SERVER_API_KEY)\"

include ../../makeEspArduino/makeEspArduino.mk

usb:
	$(MAKE) flash
	minicom --color=on -l -D $(USB_PORT) -b $(USB_SPEED)
	clear

usblog:
	minicom --color=on -l -D $(USB_PORT) -b $(USB_SPEED)
	clear
