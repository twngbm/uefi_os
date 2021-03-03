LDS := kernel.ld
CC := gcc
LD := ld

CFLAGS := -ffreestanding -fshort-wchar -Wall
LDFLAGS := -T $(LDS) -t -static -Bsymbolic -nostdlib -znocombreloc -L /usr/lib

SRCDIR := src
OBJDIR := lib
BUILDDIR := bin

SRC = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)



all: $(OBJS)
	@ echo !==== LINKING
	@-mkdir $(BUILDDIR)
	$(LD) $(LDFLAGS) -o $(BUILDDIR)/kernel.elf $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@-mkdir $(OBJDIR)
	@ echo !==== COMPILING $^
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@rm -r -f $(BUILDDIR)	
	@rm -r -f $(OBJDIR)
