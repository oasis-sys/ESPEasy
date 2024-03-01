# OASIS Gateway development set

## For Developers

### Start Develop

1. Fork repo on Github. Link to original repo: https://github.com/oasis-sys/ESPEasy
2. Clone repo on local PC by using the command:

       git clone git@github.com:<your_github_user>/ESPEasy.git

3. Build command:

       pio run -e oasis_ESP32

### ESP32 to Low Cost RF connections

Pin Name \ # | ESP32 | Devkit | STM32 | UART(TTL)
:--- | :---: | :---: | :---: | :---:
RxD 2 | GPIO16 | 6(RX2) | 8 | UART_Tx
TxD 2 | GPIO17 | 7(TX2) | 9 | UART_Rx
Mode | GPIO4 | 5(D4) | 7 | UART_CTS

UART(TTL) -- suppose to be used like similator of Low Cost RF Stack

STM32 -- MCU of Low Cost RF Stack

Devkit -- ESP32 Devkit V1 board (see in Useful Links #1)

ESP32 -- WROOM32 Wi-Fi module

### OASIS Gateway files

1. src/_P200_OasisGateway.ino
2. src/src/PluginStructs/P200_data_struct.cpp
3. src/src/PluginStructs/P200_data_struct.h

## Useful links:
1. [ESP32 Devkit pinout](https://circuitstate.com/wp-content/uploads/2022/12/ESP32-DevKit-V1-Pinout-r0.1-CIRCUITSTATE-Electronics.pdf)
2. [ESP32 WROOM32 Dataheet](https://www.elecrow.com/download/esp_wroom_32_datasheet_en.pdf)
