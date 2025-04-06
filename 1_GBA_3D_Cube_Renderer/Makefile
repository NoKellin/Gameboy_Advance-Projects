#
# Makefile for first.gba
#
DEVKITARM := C:/devkitPro/devkitARM/
GBAFIX := C:/devkitPro/tools/bin/gbafix
PATH := $(DEVKITARM)/bin:$(PATH)

# --- Project details -------------------------------------------------

PROJ    := 3DRenderer
TARGET  := $(PROJ)
BUILD_DIR := build

SOURCES := $(wildcard source/*.c)
HEADERS := $(wildcard include/*.h)

OBJS    := $(SOURCES:source/%.c=$(BUILD_DIR)/%.o)

# --- Build defines ---------------------------------------------------

PREFIX  := $(DEVKITARM)/bin/arm-none-eabi-
CC     := $(PREFIX)gcc
LD      := $(PREFIX)gcc
OBJCOPY := $(PREFIX)objcopy

ARCH    := -mthumb-interwork -mthumb
SPECS   := -specs=gba.specs

CFLAGS  := $(ARCH) -O2 -Wall -fno-strict-aliasing -Iinclude
LDFLAGS := $(ARCH) $(SPECS)


.PHONY : make clean

# --- Build -----------------------------------------------------------
# Build process starts here!
make: $(BUILD_DIR)/$(TARGET).gba

# Strip and fix header (step 3,4)
$(BUILD_DIR)/$(TARGET).gba : $(BUILD_DIR)/$(TARGET).elf
	@$(OBJCOPY) -v -O binary $< $@
	-@$(GBAFIX) $@

# Link (step 2)
$(BUILD_DIR)/$(TARGET).elf : $(OBJS)
	@$(LD) $^ $(LDFLAGS) -o $@

# Compile (step 1)
$(BUILD_DIR)/%.o : source/%.c $(HEADERS)
	@$(CC) -c $< $(CFLAGS) -o $@

# --- Clean -----------------------------------------------------------
clean : 
	-del -f /q $(BUILD_DIR)/*.gba $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.o

#EOF