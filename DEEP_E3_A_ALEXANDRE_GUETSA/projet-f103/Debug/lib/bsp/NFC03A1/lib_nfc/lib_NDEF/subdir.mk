################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.c \
../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.c 

OBJS += \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.o \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.o 

C_DEPS += \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_95HF_wrapper.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_AAR.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Email.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Geo.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_MyApp.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_SMS.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Text.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_URI.d \
./lib/bsp/NFC03A1/lib_nfc/lib_NDEF/lib_NDEF_Vcard.d 


# Each subdirectory must supply rules for building sources it contributes
lib/bsp/NFC03A1/lib_nfc/lib_NDEF/%.o: ../lib/bsp/NFC03A1/lib_nfc/lib_NDEF/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/MIDI" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/VL53L0X" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MPU6050" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/Common" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/hts221" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lis3mdl" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lps22hb" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lps25hb" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lsm6ds0" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lsm6ds3" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/tft_ili9341" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/tft_pcd8544" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MCP23S17" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/hal/inc" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/Common" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/lcd2x16" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MLX90614" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MatrixKeyboard" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MatrixLed" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/CMSIS/core" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/CMSIS/device" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/FatFs" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/FatFs/src" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/FatFs/src/drivers" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqu�/Projet Electronique embarqu�/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/appli"  -Og -g3 -Wall -Wextra -Wconversion -fmessage-length=0 -ffunction-sections -fdata-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


