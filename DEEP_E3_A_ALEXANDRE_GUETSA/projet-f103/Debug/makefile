################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include lib/middleware/MIDI/subdir.mk
-include lib/middleware/subdir.mk
-include lib/hal/src/Legacy/subdir.mk
-include lib/hal/src/subdir.mk
-include lib/bsp/trace/subdir.mk
-include lib/bsp/tft_pcd8544/subdir.mk
-include lib/bsp/tft_ili9341/subdir.mk
-include lib/bsp/lcd2x16/subdir.mk
-include lib/bsp/ir/subdir.mk
-include lib/bsp/iks01a1/lsm6ds3/subdir.mk
-include lib/bsp/iks01a1/lsm6ds0/subdir.mk
-include lib/bsp/iks01a1/lps25hb/subdir.mk
-include lib/bsp/iks01a1/lps22hb/subdir.mk
-include lib/bsp/iks01a1/lis3mdl/subdir.mk
-include lib/bsp/iks01a1/hts221/subdir.mk
-include lib/bsp/iks01a1/subdir.mk
-include lib/bsp/epaper/Fonts/subdir.mk
-include lib/bsp/epaper/subdir.mk
-include lib/bsp/dac_mcp4921/subdir.mk
-include lib/bsp/bmp180/subdir.mk
-include lib/bsp/VL53L0X/subdir.mk
-include lib/bsp/SERVO/subdir.mk
-include lib/bsp/NFC03A1/lib_nfc/lib_pcd/subdir.mk
-include lib/bsp/NFC03A1/lib_nfc/lib_NDEF/subdir.mk
-include lib/bsp/NFC03A1/lib_nfc/common/subdir.mk
-include lib/bsp/NFC03A1/CR95HF/subdir.mk
-include lib/bsp/NFC03A1/subdir.mk
-include lib/bsp/MatrixLed/subdir.mk
-include lib/bsp/MatrixKeyboard/subdir.mk
-include lib/bsp/MPU6050/subdir.mk
-include lib/bsp/MLX90614/subdir.mk
-include lib/bsp/MCP23S17/subdir.mk
-include lib/bsp/MCP23017/subdir.mk
-include lib/bsp/HC05/subdir.mk
-include lib/bsp/HC-SR04/subdir.mk
-include lib/bsp/GPS/subdir.mk
-include lib/bsp/GPRS/subdir.mk
-include lib/bsp/FingerprintReader/subdir.mk
-include lib/bsp/ESP8266/subdir.mk
-include lib/bsp/DriverLed_STP16CP05/subdir.mk
-include lib/bsp/DS1307/subdir.mk
-include lib/bsp/DHT11/subdir.mk
-include lib/bsp/CapacitiveKeyboard/subdir.mk
-include lib/bsp/BH1750FVI/subdir.mk
-include lib/bsp/APDS9960/subdir.mk
-include lib/bsp/subdir.mk
-include lib/subdir.mk
-include appli/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: projet-f103.elf

# Tool invocations
projet-f103.elf: $(OBJS) $(USER_OBJS) ..\lib\LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -u_printf_float -specs=rdimon.specs -T"../lib/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "projet-f103.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "projet-f103.elf" "projet-f103.bin"
	arm-none-eabi-size "projet-f103.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
