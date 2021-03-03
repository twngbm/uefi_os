## Make Bootloader
```
$ cd gnu-efi
$ make
$ make bootloader
```

## Make Kernel
```
$ cd kernel
$ make
```

## Copy file to USB
```
$ cp gnu-efi/x86_64/bootloader/main.efi fs:/EFI/BOOT/BOOTX64.EFI
$ cp kernel/bin/kernel.elf fs:/
$ cp kernel/bin/zap-light16.psf fs:/
```