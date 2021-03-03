OSNAME=UEFI_OS.IMG
BUILDDIR=Image/
USBDIR=USB/
GNUEFI=./gnu-efi/
GNUEFI_BOOTLOADER_BIN=./gnu-efi/x86_64/bootloader/main.efi
OVMF=./OVMFbin/
KERNEL=./kernel/
KERNEL_BIN=./kernel/bin/kernel.elf
KERNEL_SUPPORT=./kernel/support/

QEMU_MEMORYSIZE=256M

RED='\033[0;31m'
NC='\033[0m'

all: $(BUILDDIR)/$(OSNAME)


$(BUILDDIR)/$(OSNAME): $(GNUEFI_BOOTLOADER_BIN) $(KERNEL_BIN) $(KERNEL_SUPPORT)
	@echo "\033[0;31m Build Image \033[0m"
	@-mkdir $(BUILDDIR)
	@rm -f $(BUILDDIR)/$(OSNAME)
	dd if=/dev/zero of=$(BUILDDIR)/$(OSNAME) bs=512 count=93750
	mformat -i $(BUILDDIR)/$(OSNAME) -f 1440 ::
	mmd -i $(BUILDDIR)/$(OSNAME) ::/EFI
	mmd -i $(BUILDDIR)/$(OSNAME) ::/EFI/BOOT
	mcopy -i $(BUILDDIR)/$(OSNAME) $(GNUEFI_BOOTLOADER_BIN) ::/EFI/BOOT/BOOTX64.EFI
	mcopy -i $(BUILDDIR)/$(OSNAME) $(OVMF)/startup.nsh ::
	mcopy -i $(BUILDDIR)/$(OSNAME) $(KERNEL_BIN) ::
	for file in $(KERNEL_SUPPORT)/*;do mcopy -i $(BUILDDIR)/$(OSNAME) $${file} :: ;done

$(GNUEFI_BOOTLOADER_BIN): $(GNUEFI)/bootloader/*
	@echo "\033[0;31m Build UEFI Bootloader \033[0m"
	cd $(GNUEFI) && make && make bootloader

$(KERNEL_BIN): $(KERNEL)/src/* $(KERNEL)/support/*
	@echo "\033[0;31m Build Kernel \033[0m"
	cd $(KERNEL) && make

usb: $(GNUEFI_BOOTLOADER_BIN) $(KERNEL_BIN) $(KERNEL_SUPPORT)
	@echo "\033[0;31m Make USB Bootable Directiory \033[0m"
	@rm -f -r $(USBDIR)
	@mkdir $(USBDIR)
	@mkdir $(USBDIR)/EFI
	@mkdir $(USBDIR)/EFI/BOOT
	cp $(GNUEFI_BOOTLOADER_BIN) $(USBDIR)/EFI/BOOT/BOOTX64.EFI
	cp $(OVMF)/startup.nsh $(USBDIR)/
	cp $(KERNEL_BIN) $(USBDIR)/
	for file in $(KERNEL_SUPPORT)/*;do cp $${file} $(USBDIR)/ ;done

clean:
	@echo "\033[0;31m Cleanup \033[0m"
	@rm -f -r $(BUILDDIR)
	@rm -f -r $(USBDIR)
	cd $(GNUEFI) && make bootloader clean && make clean
	cd $(KERNEL) && make clean
	
run:
	qemu-system-x86_64 -drive file=$(BUILDDIR)/$(OSNAME) -m $(QEMU_MEMORYSIZE) -cpu qemu64 -drive if=pflash,format=raw,unit=0,file="$(OVMF)/OVMF_CODE-pure-efi.fd",readonly=on -drive if=pflash,format=raw,unit=1,file="$(OVMF)/OVMF_VARS-pure-efi.fd" -net none -vga std
