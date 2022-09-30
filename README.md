# maon

The maon (most annoying order notifier) makes sure you get notified for each new order placed in your shop.

## Hardware
The maon is based on a toy police siren I found on the street and an esp8266 which was laying around in the office.
For more information on the hardware check out my [project on hackaday.io](https://hackaday.io/project/183079-maon).

## Software
To develop the firmware the [Arduino core for ESP8266](https://github.com/esp8266/Arduino) is used.  
Building and flashing is done with help of [makeEspArduino](https://github.com/plerup/makeEspArduino).

## Yeah nice, but what it is doing?
Well rather simple...   
After boot the maon connects to the configured wifi.
When the connection is established it fetches the order list from the shop via the webservice API described [here](https://devdocs.prestashop.com/1.7/webservice/).  
Then it will compare the highest order id that was fetched from the server, with the localy stored id. If the local id is the same it means no new order is present.
But if the fetched id is higher then the local one, we got a new order!
For this case the transistor will be switched "on" and thus the siren will receive power.
The new id will also be saved locally.

After 10 seconds the siren will be stopped, the storage access will be finished and the wifi connection will be closed.
Then the maon goes to sleep for 1 minute, just to start all over again afterwards.

## What shop?
Currently only shops based on [PrestaShop](https://www.prestashop.com) are supported.

## How to configure?
In the `Makefile.config` the configuration is done.
The first section is for wifi configuration and the second for the shop API.  
  
!!! Attention: never make the config file public, as it holds sensitive information !!!
