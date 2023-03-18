[![Build Status](https://img.shields.io/badge/USEFUL%20ELECTRONICS-YOUTUBE-red)](https://www.youtube.com/user/wardzx1)

# Sponsors

### PCBWay
Tutorial Series Sponsor PCBWay Website. You can get extra free coupons using the link below:

[<img src="https://github.com/UsefulElectronics/esp32s3-gc9a01-lvgl/blob/main/banner/banner(320x100).gif">](https://www.pcbway.com/setinvite.aspx?inviteid=582640)

### Fixaj
E22900T22D Module purchase link:
https://shop.fixaj.com/e22-900t22d-7km-menzilli-900mhz-sx1262-lora-modulu
[<img src="https://github.com/UsefulElectronics/stm32-freertos-e22-lora/blob/main/banner/cropped-fixaj-logo-1.png">](https://shop.fixaj.com/e22-900t22d-7km-menzilli-900mhz-sx1262-lora-modulu)
***


# STM32 E22900T22D LoRa Module Interface and Range Test
***

### [Tutorial Link](https://youtu.be/fPgSf5HOfO8) On [![Build Status](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/wardzx1) 

In this tutorial, two STM32 micro-controllers are exchanging data witlessly over LoRa using E22900T22D module that is interfaced over UART. The MCUs are exchaning dummy data to toggle onboard LED as an indication for ongoing wireless communication.

Outdoor wireless mid-range (around 1000m) communication test was also conducted where no packet loss over LoRa was observed.

E22900T22D Module which uses SX1262, parameters configuration, its interface packets are discussed in details. FreeRTOS is integrated in the firmware to make handling the system much easier. Circular buffer algorithm is implemented to store data packets in the RAM before processing them. 

![Circuit Diagram](https://github.com/UsefulElectronics/stm32-freertos-e22-lora/blob/main/circuit%20diagram/circuit%20diagram.PNG)
***