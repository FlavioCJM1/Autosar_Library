#Target to build the program
all:
# Compile main.c
	arm-none-eabi-gcc -c startup.c -o startup.o -mcpu=cortex-m0plus
	arm-none-eabi-gcc -c main.c -o main.o -mcpu=cortex-m0plus
# link to generate main.elf
	arm-none-eabi-gcc main.o startup.o -o main.elf -nostdlib -mcpu=cortex-m0plus -Tlinker.ld -Wl,-Map=main.map

# Target to flash the mcu	
flash :
	openocd -f board/st_nucleo_g0.cfg -c "program main.elf verify reset" -c shutdown

# target to open a connection with the mcu   
open :
	openocd -f board/st_nucleo_g0.cfg