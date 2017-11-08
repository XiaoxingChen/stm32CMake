TARGET = main
OBJS = main.o
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCP = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m3 -mthumb -nostartfiles -g
LFLAGS = -T stm32-linux.ld
CPFLAGS = -Obinary
TARGET_ELF = $(TARGET).elf
TARGET_BIN = $(TARGET).bin

$(TARGET_BIN):$(TARGET_ELF)
	$(OBJCP) $(CPFLAGS) $< $@

$(TARGET_ELF):$(OBJS)
	$(LD) $(LFLAGS) -o  $@ $<
    
$(OBJS):main.c
	$(CC) $(CFLAGS) $< $(LFLAGS) -o $@
clean:
	rm -f $(TARGET) *.o


