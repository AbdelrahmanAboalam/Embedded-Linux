# Run kernel with rootfs


- From busy box
- You can check how to generate rootfs from [busybox](https://github.com/Aboalam15/Embedded-Linux/blob/main/Tools/Busy_Box/README.md)
- 
![Screenshot from 2024-07-26 08-41-03](https://github.com/user-attachments/assets/64550cc5-c646-430f-93c9-7e83d81c166e)

- Now we will make /etc/init.d/rcS to run it when go throw init process

```bash
#!/bin/sh
# mount a filesystem of type `proc` to /proc
mount -t proc nodev /proc
# mount a filesystem of type `sysfs` to /sys
mount -t sysfs nodev /sys
# mount devtmpfs if you forget to configure it in Kernel menuconfig
#there is two options uncomment one of them  
mount -t devtmpfs devtempfs /dev
```
- You want to make it excutable

```bash
chmod +x rcS
```

- Now we want to make inittab to run rcS

```bash
::sysinit:/etc/init.d/rcS
ttyAMA0::askfirst:-/bin/sh
::restart:/sbin/init
```
- Moving rootfs to SD card in Ext4 partition
- After That we will open Qemu

```bash
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0,script=no -kernel u-boot -sd ~/Desktop/sdcard/sd.img
```
- Then we will want to load zImage and .dtp file in memory

```bash
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
```
- Now we want to initialize our init in bootargs

```bash
setenv bootargs console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init
```
- Then now we can run our kernal by

```bash
bootz $kernel_addr_r zImage - $fdt_addr_r
```
![Screenshot from 2024-07-24 14-01-30](https://github.com/user-attachments/assets/2bd27deb-05c2-425a-80b2-d77f895810df)


