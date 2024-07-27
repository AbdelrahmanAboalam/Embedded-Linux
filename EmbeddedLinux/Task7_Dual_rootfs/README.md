## Initramfs for run Kernel from ram

**Description**:- we want to make initramfs to run kernel from RAM and choose from it where I want to run partition  or 

- First we want to make 3 partitions in our SD

- Open Disks and then slect your sd card and then select resize

![Screenshot from 2024-07-26 20-19-45](https://github.com/user-attachments/assets/33207109-abc1-452e-9a62-da4a40ade6cd)

- Then select the size and type for new partition called rootfs2

- Now we have 2 partitions for rootfs we want add our root file system from [busybox](https://github.com/Aboalam15/Embedded-Linux/blob/main/Tools/Busy_Box/README.md)

- Now we will write our script for chose from where I will boot

```bash
#!/bin/bash
while true; do
    echo "Choose the root filesystem to boot:"
    echo "1) RootFS1"
    echo "2) RootFS2"
    read -p "Enter choice [1-2]: " choice

    case "$choice" in
        1)
            ROOTFS="/mnt/rootfs1"
            break
            ;;
        2)
            ROOTFS="/mnt/rootfs2"
            break
            ;;
        *)
            echo "Invalid choice, please try again."
            ;;
    esac
done
```

- This script waiting from user 1 or 2 to select which partition will run
- And it will be with rootfs files

- Then we will compress files in rootfs to make it an image

```bash
cd ~/rootfs
find . | cpio -H newc -ov --owner root:root > ../initramfs.cpio
cd ..
gzip initramfs.cpio
mkimage -A arm -O linux -T ramdisk -d initramfs.cpio.gz uRamdisk
```
![Screenshot from 2024-07-26 20-33-23](https://github.com/user-attachments/assets/07867be2-e6b7-4345-915e-863d02f091dc)

- Then we will copy our image to boot partition

- **In Qemu**

```bash
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0,script=no -kernel u-boot -sd ~/Desktop/sdcard/sd.img
```
- Now we will set address for initramfs and load our images

```bash
setenv initramfs 0x67000000
fatload mmc 0:1 $kernel_addr_r zImage
fatload mmc 0:1 $fdt_addr_r vexpress-v2p-ca9.dtb
fatload mmc 0:1 $initramfs uRamdisk
```
- And the bootargs

```bash
setenv bootargs console=ttyAMA0 rdinit=/bin/sh
```

- Then we will put our 
- Now we can run our kernal

```bash
bootz $kernel_addr_r $initramfs $fdt_addr_r
```
- Now it will run kernal and you will see the shell

- After that we want to mount some directories

```bash
mount -t devtmpfs dev /dev
mkdir mnt/rootfs1
mkdir mnt/rootfs2

mount -t ext4 /dev/mmcblk0p2 /mnt/rootfs1
mount -t ext4 /dev/mmcblk0p3 /mnt/rootfs2
```
- After that you can run script and select which part you want

![Screenshot from 2024-07-26 21-46-20](https://github.com/user-attachments/assets/d14576a2-aa16-4809-a5e9-8b93533862ff)


