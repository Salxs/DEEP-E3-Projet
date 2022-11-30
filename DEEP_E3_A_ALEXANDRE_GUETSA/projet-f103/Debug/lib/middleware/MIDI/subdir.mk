################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lib/middleware/MIDI/midi.c \
../lib/middleware/MIDI/usb_device.c \
../lib/middleware/MIDI/usbd_conf.c \
../lib/middleware/MIDI/usbd_core.c \
../lib/middleware/MIDI/usbd_ctlreq.c \
../lib/middleware/MIDI/usbd_desc.c \
../lib/middleware/MIDI/usbd_ioreq.c \
../lib/middleware/MIDI/usbd_midi.c \
../lib/middleware/MIDI/usbd_midi_if.c 

OBJS += \
./lib/middleware/MIDI/midi.o \
./lib/middleware/MIDI/usb_device.o \
./lib/middleware/MIDI/usbd_conf.o \
./lib/middleware/MIDI/usbd_core.o \
./lib/middleware/MIDI/usbd_ctlreq.o \
./lib/middleware/MIDI/usbd_desc.o \
./lib/middleware/MIDI/usbd_ioreq.o \
./lib/middleware/MIDI/usbd_midi.o \
./lib/middleware/MIDI/usbd_midi_if.o 

C_DEPS += \
./lib/middleware/MIDI/midi.d \
./lib/middleware/MIDI/usb_device.d \
./lib/middleware/MIDI/usbd_conf.d \
./lib/middleware/MIDI/usbd_core.d \
./lib/middleware/MIDI/usbd_ctlreq.d \
./lib/middleware/MIDI/usbd_desc.d \
./lib/middleware/MIDI/usbd_ioreq.d \
./lib/middleware/MIDI/usbd_midi.d \
./lib/middleware/MIDI/usbd_midi_if.d 


# Each subdirectory must supply rules for building sources it contributes
lib/middleware/MIDI/%.o: ../lib/middleware/MIDI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/MIDI" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/VL53L0X" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MPU6050" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/Common" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/hts221" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lis3mdl" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lps22hb" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lps25hb" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lsm6ds0" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/iks01a1/lsm6ds3" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/tft_ili9341" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/tft_pcd8544" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MCP23S17" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/hal/inc" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/Common" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/lcd2x16" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MLX90614" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MatrixKeyboard" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/bsp/MatrixLed" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/CMSIS/core" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/CMSIS/device" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/FatFs" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/FatFs/src" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/lib/middleware/FatFs/src/drivers" -I"C:/Users/Salxs/Documents/ESEO/Cours/Electronique_embarqué/Projet Electronique embarqué/STM32_Workspace/DEEP_E3_A_ALEXANDRE_GUETSA/projet-f103/appli"  -Og -g3 -Wall -Wextra -Wconversion -fmessage-length=0 -ffunction-sections -fdata-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


