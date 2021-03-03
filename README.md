# Yet Another Custom Kernel Compatible with UEFI
## Description
This is a working project. Main purpose is practicing C language and OS implementation and some tool chain usage. This project is inspired by this [Youtube Channel](https://www.youtube.com/watch?v=mpPbKEeWIHU&list=PLxN4E629pPnJxCQCLy7E0SQY_zuumOVyZ). This project can work on both qemu or real-HW, but UEFI support is necessary.

## Prerequest

```
$ sudo apt install build-essential mtools qemu-kvm qemu virt-manager virt-viewer libvirt-bin
```

## Usage
**Virtual Machine**
1. Clone this repository
```
$ git clone https://github.com/twngbm/uefi_os
$ cd uefi_os
```

2. Compile source and build image for qemu
```
$ make
```

3. Run with qemu
```
$ make run
```

**Dev-board with uefi**
1. Compile source and copy all needed file into a directory, default is ./USB
```
$ make usb
```
2. Copy all file in that directory to a FAT32 usb-stick, and plugin into a computer which has UEFI.

3. Select the usb as boot device.


## Reference
[Absurdponcho/PonchoOS](https://github.com/Absurdponcho/PonchoOS/tree/main)
