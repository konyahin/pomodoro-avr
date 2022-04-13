PROG=USBasp
MCU=attiny45
F_CPU=1000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I.
TARGET=pomodoro
SRCS=main.c interrupt.c music.c timer.c

build: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET).bin $(SRCS)
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET).bin $(TARGET).hex

burn: build
	avrdude -c $(PROG) -p $(MCU) -U flash:w:./$(TARGET).hex

clean:
	rm -f *.bin *.hex *.o
