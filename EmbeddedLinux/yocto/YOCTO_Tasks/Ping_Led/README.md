# Make Image to RPI adding ping led APP

## Prerequistes

- We should clone meta openembedded and meta raspberry
```bash
git clone -b kirkstone https://github.com/agherzan/meta-raspberrypi.git
```
```bash
git clone -b kirkstone https://github.com/openembedded/meta-openembedded.git
```

## Our environment

- We will make new env
```bash
source oe-init-build-env rpi
```
![Screenshot from 2024-08-26 19-22-13](https://github.com/user-attachments/assets/4a9aef15-c61c-4130-8cbf-1c9a579b5907)

- We will add our layers to `rpi/conf/bblayers.conf`

```bash
BBLAYERS ?= " \
  /home/aboalam/yocto/poky/meta \
  /home/aboalam/yocto/poky/meta-poky \
  /home/aboalam/yocto/poky/meta-yocto-bsp \
  /home/aboalam/yocto/meta-raspberrypi \
  /home/aboalam/yocto/meta-Abdo \
  /home/aboalam/yocto/meta-openembedded/meta-oe \
  /home/aboalam/yocto/meta-openembedded/meta-python \
  /home/aboalam/yocto/meta-openembedded/meta-networking \
  "
```
![Screenshot from 2024-08-26 19-24-07](https://github.com/user-attachments/assets/a4d28eb5-8d00-47e6-9123-f0cfa8f62682)

# Creating our distro

- The hierarchy of distro is `meta-Abdo/cond/distro/Aboalam.conf

![Screenshot from 2024-08-26 19-27-31](https://github.com/user-attachments/assets/f90620b0-b1a8-4a6c-b11b-c13ba66779d9)

```bash
include meta-poky/conf/distro/poky.conf

DISTRO = "Aboalam"
DISTRO_NAME = "Almaza"
#DISTRO_VERSION = "3.4+snapshot-${METADATA_REVISION}"
DISTRO_VERSION = "4.0.20"
DISTRO_CODENAME = "kirkstone"

MAINTAINER = "abdoabo3lm@gmail.com"
```
## Recipe 
- We will create pingled recipe add to it our app

![Screenshot from 2024-08-26 19-27-31](https://github.com/user-attachments/assets/f90620b0-b1a8-4a6c-b11b-c13ba66779d9)

- In recipe

```bash
SAMMARY = "Script to ping led with IP to control leds"
DESCRIPTION = "This recipe include bash script to run it"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

FILESPATH:append = " :${THISDIR}/files:"
SRC_URI += "file://pingled.sh"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/pingled.sh ${D}${bindir}/
}
```
## Our app

```bash
#!/bin/bash


LED_RED_PIN=2
LED_GREEN_PIN=3


if [ -z "$1" ]; then
    echo "Usage: $0 <IP_ADDRESS>"
    exit 1
fi


IP_ADDRESS="$1"


setup_gpio() {
    echo "$LED_RED_PIN" > /sys/class/gpio/export
    echo "$LED_GREEN_PIN" > /sys/class/gpio/export
    echo "out" > /sys/class/gpio/gpio$LED_RED_PIN/direction
    echo "out" > /sys/class/gpio/gpio$LED_GREEN_PIN/direction
}


cleanup_gpio() {
    echo "$LED_RED_PIN" > /sys/class/gpio/unexport
    echo "$LED_GREEN_PIN" > /sys/class/gpio/unexport
}

control_leds() {
    if ping -c 1 "$IP_ADDRESS" > /dev/null 2>&1; then
        echo "1" > /sys/class/gpio/gpio$LED_GREEN_PIN/value
        echo "0" > /sys/class/gpio/gpio$LED_RED_PIN/value
    else
        echo "0" > /sys/class/gpio/gpio$LED_GREEN_PIN/value
        echo "1" > /sys/class/gpio/gpio$LED_RED_PIN/value
    fi
}
main() {
    setup_gpio

    while true; do
        control_leds
        sleep 10  
    done
}
trap cleanup_gpio EXIT
main
```

## We will add our packages to local.conf

- We will change our Machine

```bash
MACHINE ?= "raspberrypi3-64"
```

- We will add our Distro
```bash
DISTRO ?= "Aboalam"
```
- We will add old downloads

```bash
DL_DIR ?= "/home/aboalam/yocto/poky/build/downloads"
SSTATE_DIR ?= "/home/aboalam/yocto/poky/build/sstate-cache"
```
- We will add our packages that want to download
```bash
XTRA_IMAGE_FEATURES ?= "debug-tweaks"

IMAGE_FSTYPES = "tar.bz2 ext4 rpi-sdimg"

IMAGE_INSTALL:remove = "dropbear"

IMAGE_INSTALL:append = " python3 openssh bash systemd systemd-serialgetty \
 util-linux \
    bluez5 \
    i2c-tools \
    bridge-utils \
     pi-bluetooth "

IMAGE_INSTALL:append = " apt bash git"


DISTRO_FEATURES:append = " \
    bluez5 \
    bluetooth \
    wifi \
    pi-bluetooth \
    linux-firmware-bcm43455 \
    systemd \
    usrmerge \
    ipv4 \
"

DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = "systemd-compat-units"

MACHINE_FEATURES:append = " \
    bluetooth \
    wifi \
"

IMAGE_INSTALL += "pingled"
```

## Our Image
- We will find our image in `yocto/poky/rpi/tmp-glibc/deploy/images/raspberrypi3-64`

```bash
ls yocto/poky/rpi/tmp-glibc/deploy/images/raspberrypi3-64 | grep sdimg
```

![Screenshot from 2024-08-26 20-02-59](https://github.com/user-attachments/assets/98ac0a66-9b5b-45fb-b020-c10b1999cbb9)

