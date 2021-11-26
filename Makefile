GIT_MAKE    = "git@github.com:plerup/makeEspArduino.git"
GIT_ESP8266 = "git@github.com:esp8266/Arduino.git"

# Commit to checkout at
COM_MAKE    = "f30b6fe"

RED = '\033[0;31m'
YEL = '\033[1;33m'
GRN = '\033[0;32m'
ORG = '\033[0;33m'
RST = '\033[0m'

TARGETS := usb usblog clean erase test

SHELL = bash

PWD = 'pwd'

$(TARGETS): src


src:
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TARGETS) src

env-clean:
	@echo -e ${ORG}Cleaning enviroment...${RST}
	rm -rf ../Arduino-ESP8266
	rm -rf ../makeEspArduino
	@echo -e ${GRN}Done cleaning${RST}

env-pull:
	@echo -e ${ORG}Getting enviroment ... ${RST}
	@if [ -d ../Arduino-ESP8266 ] ; then                                      \
		echo -e ${YEL}Pulling Arduino-ESP8266 from $(GIT_ESP8266) ...${RST} ;   \
		cd ../Arduino-ESP8266 ;                                                 \
		git pull origin master ;                                                \
		git submodule update ;                                                  \
	else                                                                      \
		echo -e ${RED}Installing Arduino-ESP8266 ... ${RST} ;                   \
		cd .. ;                                                                 \
		git clone $(GIT_ESP8266) Arduino-ESP8266 ;                              \
		cd Arduino-ESP8266 ;                                                    \
		git submodule update --init ;                                           \
		cd tools ;                                                              \
		python get.py ;                                                         \
	fi ;
	@if [ -d ../makeEspArduino ] ; then                                       \
		echo -e ${YEL}Pulling makeEspArduino from $(GIT_MAKE) ... ${RST} ;      \
		cd ../makeEspArduino ;                                                  \
		git pull origin master ;                                                \
    git checkout $(COM_MAKE) ;                                              \
	else                                                                      \
		echo -e ${RED}Installing makeEspArduino .. ${RST} ;                     \
		cd .. ;                                                                 \
		git clone $(GIT_MAKE) ;                                                 \
    git checkout $(COM_MAKE) ;                                              \
	fi ;
	@echo -e ${GRN}Done with installation/pulling ${RST}


help:
	@echo
	@echo	"usage: make <option>"
	@echo
	@echo "option:"
	@echo "  usb            >Build and flash firmware"
	@echo "  usblog         >Start logging over serial connection"
	@echo "  env-pull       >Install/Update build enviroment"
	@echo "  env-clean      >Clean the build enviroment"
	@echo
	@$(MAKE) -C src_code help
