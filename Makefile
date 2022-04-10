PROG=USBasp
MMCU=attiny45
MCP=t45
FCPU=1200000

burn: main.hex
	avrdude -c $(PROG) -p $(MCP) -U flash:w:./main.hex

build: main.hex

main.hex: main.c interrupt.c
	avr-gcc -g -Os -mmcu=$(MMCU) -DF_CPU=$(FCPU) -c main.c interrupt.c
	avr-gcc -g -mmcu=$(MMCU) -o main.elf main.o interrupt.o
	avr-objcopy -j .text  -j .data -O ihex main.elf main.hex

clean:
	rm -f *.elf *.hex *.o
