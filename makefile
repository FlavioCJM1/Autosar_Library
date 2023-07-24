#Target to build the program
all:
# Compile main.c
	arm-none-eabi-gcc -c startup.c -o Build/startup.o -mcpu=cortex-m0plus
	arm-none-eabi-gcc -c main.c -o Build/main.o -mcpu=cortex-m0plus
# link to generate main.elf
	arm-none-eabi-gcc Build/main.o Build/startup.o -o Build/main.elf -nostdlib -mcpu=cortex-m0plus -Tlinker.ld -Wl,-Map=main.map

# Target to flash the mcu	
flash :
	openocd -f board/st_nucleo_g0.cfg -c "program main.elf verify reset" -c shutdown

# target to open a connection with the mcu   
open :
	openocd -f board/st_nucleo_g0.cfg

lint:
	mkdir -p Build/checks
	cppcheck --addon=misra.json --suppressions-list=.msupress $(LNFLAGS) Autosar

#Linter ccpcheck flags
LNFLAGS  = --inline-suppr       # comments to suppress lint warnings
LNFLAGS += --quiet              # spit only useful information
LNFLAGS += --std=c99            # check against C11
LNFLAGS += --template=gcc       # display warning gcc style
LNFLAGS += --force              # evaluate all the #if sentences
LNFLAGS += --platform=unix32    # lint againt a unix32 platform, but we are using arm32
LNFLAGS += --cppcheck-build-dir=Build/checks