LDS = kernel.ld
CC = gcc
LD = ld

CFLAGS = -ffreestanding -fshort-wchar
LDFLAGS = -T $(LDS) -static -Bsymbolic -nostdlib

SRCDIR := src
OBJDIR := lib
BUILDDIR = bin


rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.c)          
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

UEFIFLAGS= -I/usr/include/efi -I/usr/include/efi/x86_64 -I/usr/include/efi/protocol -I./src

all: 
	rm -f bin/kernel.elf
	$(CC) $(CFLAGS) $(UEFIFLAGS)  -fno-stack-protector -fpic  -mno-red-zone -DHAVE_USE_MS_ABI -c -o src/kernel.o src/kernel.c
	$(LD) $(LDFLAGS) -znocombreloc -L /usr/lib  src/kernel.o lib/entry.o -o bin/kernel.elf -lefi -lgnuefi
	rm -f src/kernel.o

# all: kernel

kernel: all
#kernel: $(OBJS) link

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@
	
link:
	@ echo !==== LINKING
	$(LD) $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $(OBJS) lib/entry.o

setup:
	@mkdir $(BUILDDIR)
	@mkdir $(SRCDIR)
	@mkdir $(OBJDIR)
