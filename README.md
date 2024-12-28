# STM32F4-REAL-TIME-AUDIO-PROCESSING
This project showcases real-time audio signal processing using an STM32 microcontroller, INMP44 microphone, and CS43L22 DAC for audio playback. Audio data is processed with an ARM DSP library FIR low-pass filter and then played back through headphones.

## Overview

- **Microphone**: INMP44 captures audio in PDM format.
- **STM32F407VGT6-DISC**: Performs data processing and manages communication with peripherals for audio output.
- **CS43L22**: CS43L22 DAC converts PCM to analog audio for playback through headphones.

## Hardware

- **INMP441**: MEMS microphone
- **STM32VGT6**: Microcontroller
- **CS43L22**: Stereo DAC
- **Headphones**

## Documentation

For more detailed information, refer to the following resources:

- [STM32- Reference Manual](https://www.st.com/resource/en/reference_manual/dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
- [STM32F407 Reference Schematic](https://www.st.com/resource/en/schematic_pack/mb997-f407vgt6-b02_schematic.pdf)
- [STM32- Datasheet](https://www.st.com/resource/en/datasheet/stm32f405rg.pdf)
- [STM32- Device Errata](https://www.st.com/resource/en/errata_sheet/es0182-stm32f405407xx-and-stm32f415417xx-device-errata-stmicroelectronics.pdf)
- [INMP44 Microphone Datasheet](https://www.alldatasheet.com/datasheet-pdf/pdf/1244625/ETC1/INMP441.html)
- [CS43L22 DAC Datasheet](https://www.cirrus.com/products/cs43l22/)
- [STM32 PDM2PCM Library](https://www.st.com/resource/en/user_manual/um2372-stm32cube-pdm2pcm-software-library-for-the-stm32f4f7h7-series-stmicroelectronics.pdf)
- [Application Notes](https://www.st.com/resource/en/application_note/dm00380469-interfacing-pdm-digital-microphones-using-stm32-mcus-and-mpus-stmicroelectronics.pdf)

## System Diagram
![audio-processing drawio](https://github.com/user-attachments/assets/9c9e549b-1fe5-43be-9551-0ae0f6dd29d2)



