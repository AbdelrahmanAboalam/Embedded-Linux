## rootfs from Busy Box

- We use busybox to make root file systems

- First we want to download busybox

```bash
git clone https://github.com/mirror/busybox.git
```
- If cancelled during download try this commands

```bash
git config --global http.postBuffer 1048576000
git clone --depth 1 https://github.com/mirror/busybox.git
```
- Then we will define our Cross compiler and Arch

```bash
export ARCH=arm
export CROSS_COMPILE=x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-
```
- Then we will make our configrations

```bash
make menuconfig
```
- We can slect if we want libraries static or dinamic from sittings

- Then we will build it

```bash
make
```

- You may find error and you can solve it by - Change Var in file from y to n

```bash
vim .config
```
- Then find `CONFIG-TC=y` and edit it to `CONFIG-TC=n`
- After that you can rebuild

- To collect files you can run this command
```bash
make install
```
- You will find it in file called _install

- You can move files to rootfs directory

```bash
rsync -av ~/busybox/_install/* ~/rootfs/
```
![Screenshot from 2024-07-26 23-27-01](https://github.com/user-attachments/assets/5e76f751-542a-4061-822c-70b943b8f23b)


- If you want to collect modules (lib)

```bash 
export INSTALL_MOD_PATH=/home/aboalam/Desktop/Modulas/
make modules_install ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf
```

- After that you will see the all modules collected in lib dirctory like that

![Screenshot from 2024-07-26 23-24-26](https://github.com/user-attachments/assets/3ce25031-f72f-4957-bf50-3491d149bdc6)

- Now we want to make directories in rootfs

```bash
mkdir boot dev etc home mnt proc root srv sys
```

- Then we will make our init

```bash
mkdir etc/init.d
touch etc/init.d/rcS
```

- We will write rcS and chancge permission to make excutable

```bash
#!/bin/sh

mount -t proc nodev /proc

mount -t sysfs nodev /sys

mount -t devtmpfs devtempfs /dev
```
