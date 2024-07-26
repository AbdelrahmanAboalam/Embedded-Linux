# Creating kernel for vexpres-a9 and RPI

## For Vexpress

- First we want to make clone

```bash
git clone --depth=1 git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
```
- Then we will go into linux directory

- Now we will define our arch and cross compiler
```bash
export ARCH=arm
export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
```
-Seconde we will go to chose our target from 
```bash
ls arch/arm/configs/ | grep vexpress
```
![Screenshot from 2024-07-26 07-42-18](https://github.com/user-attachments/assets/50115916-fc0f-4aac-bb64-f6a04caa5806)

- Then we will make configrations for our target
```bash
make vexpress_defconfig
```
- After That we chose from menu config `XZ` for compression mode to creat zImage from `General setup`

```bash
make menuconfig
```
![Screenshot from 2024-07-26 07-46-55](https://github.com/user-attachments/assets/f2301c89-0558-481a-bacc-489f530c58b2)

- Now we can Build it

```bash
make
```
-After build you will see the zImage in
```bash
cd arch/arm/boot
```
![Screenshot from 2024-07-26 07-50-36](https://github.com/user-attachments/assets/e6ce4233-0a41-418f-8af1-e617e3a62b0d)

- And the dtb file in
```bash
cd arch/arm/boot/dts/arm
ls | grep vexpress
```
## For Raspberry
- First we want to make clone

```bash
git clone --depth=1 https://github.com/raspberrypi/linux
```
- Then we will go into linux directory

- Now we will define our arch and cross compiler of raspberry
```bash
export ARCH=arm
export CROSS_COMPILE=arm-linux-gnueabihf-
```
-Seconde we will go to chose our target from 
```bash
ls arch/arm/configs/ | grep bcm
```
![Screenshot from 2024-07-26 07-57-32](https://github.com/user-attachments/assets/e942d080-3ad6-4492-b1dc-b93a2394421e)

- Then we will make configrations for our target
```bash
make bcm2835_defconfig
```
- After That we chose from menu config `XZ` for compression mode to creat zImage from `General setup`

```bash
make menuconfig
```
![Screenshot from 2024-07-26 07-46-55](https://github.com/user-attachments/assets/f2301c89-0558-481a-bacc-489f530c58b2)

- We will enable devtmpfs and support initramfs from CONFIG_BLK_DEV_INITRD
![Screenshot from 2024-07-26 08-01-57](https://github.com/user-attachments/assets/774cf006-7116-46ec-8ff8-d03c64748881)

![Screenshot from 2024-07-26 08-02-47](https://github.com/user-attachments/assets/c648993e-05f1-4ea5-ae34-980d7a18e5dc)

- Now we can Build it

```bash
make
```
-After build you will see the zImage in
```bash
cd arch/arm/boot
```
- And you can find dtb in
```bash
cd arch/arm/boot/dts/broadcom
ls | grep bcm
```
![Screenshot from 2024-07-26 08-07-45](https://github.com/user-attachments/assets/ef318d36-119c-4a81-894c-a39e3a826d01)

- Now we want to collect our libs

```bash
 export INSTALL_MOD_PATH=/home/aboalam/Desktop/Modulas/
 make modules_install ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-
```
![Screenshot from 2024-07-26 08-10-17](https://github.com/user-attachments/assets/ba315b71-0db9-41ff-bb83-8f301e4016cf)





