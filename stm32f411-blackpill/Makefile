PROG_NAME = blinky

CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
CP = arm-none-eabi-objcopy
RM = rm -rf

INCDIR = -I./ \
         -I./app/inc \
		 -I./bsp/inc \
		 -I./hal/inc \
		 -I./stm32/inc

OBJDIR = build

DEPDIR = .deps

SRCS = main.c \
       app/src/blinky.c \
	   bsp/src/bsp.c \
	   bsp/src/startup.c \
	   hal/src/digital_io.c \
	   stm32/src/stm32_gpio.c \
	   stm32/src/stm32_rcc.c

OBJS = $(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
$(shell mkdir -p $(dir $(OBJS)) > /dev/null)

DEPS = $(patsubst %.c, $(DEPDIR)/%.d, $(SRCS))
$(shell mkdir -p $(dir $(DEPS)) > /dev/null)

CFLAGS = -g -mcpu=cortex-m4 -mthumb -O0 -Wall
CFLAGS += $(INCDIR)
DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d
LDFLAGS = -nostdlib -T bsp/stm32f411-rom.ld

all: $(PROG_NAME).elf $(PROG_NAME).bin

$(PROG_NAME).elf: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

$(PROG_NAME).bin: $(PROG_NAME).elf
	$(CP) -O binary $< $@

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d
	$(CC) -c $(CFLAGS) $(DEPFLAGS) $< -o $@

$(DEPS):

-include $(DEPS)

clean:
	$(RM) $(OBJDIR) $(DEPDIR) $(PROG_NAME).elf $(PROG_NAME).bin

flash:
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c init -c "reset halt" -c "flash write_image erase blinky.bin 0x08000000" -c exit