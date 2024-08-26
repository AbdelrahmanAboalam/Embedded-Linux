# Customize Image to run Qt App

## Prerequistes

- We should clone meta openembedded, meta raspberry and meta Qt5

```bash
git clone -b kirkstone https://github.com/agherzan/meta-raspberrypi.git
```
```bash
git clone -b kirkstone https://github.com/openembedded/meta-openembedded.git
```
```bash
git clone -b kirkstone https://github.com/meta-qt5/meta-qt5.git
```
## Our hierarchy
- We will make meta layer including 3 recipes one for image and distro one for package for App one for bsp

![Screenshot from 2024-08-26 20-44-38](https://github.com/user-attachments/assets/a542d841-891c-4785-9e03-9d1dc68049d1)

- To make our layer
```bash
bitbake-layers create-layer ../../meta-Aboalam
```

## Make our Env

- We will make our Env to set machine, our distro and layers

```bash
source oe-init-build-env build_rpi
```
 
## Adding layers to bblayers

![Screenshot from 2024-08-26 20-46-58](https://github.com/user-attachments/assets/2a5aeb9a-f3ce-4062-b65a-600792fb4de3)

```bash
BBLAYERS ?= " \
  /home/aboalam/yocto/poky/meta \
  /home/aboalam/yocto/poky/meta-poky \
  /home/aboalam/yocto/poky/meta-yocto-bsp \
  /home/aboalam/yocto/meta-raspberrypi \
  /home/aboalam/yocto/meta-openembedded/meta-oe \
  /home/aboalam/yocto/meta-openembedded/meta-python \
  /home/aboalam/yocto/meta-openembedded/meta-networking \
  /home/aboalam/yocto/meta-Aboalam \
  /home/aboalam/yocto/meta-openembedded/meta-gnome \
  /home/aboalam/yocto/meta-openembedded/meta-xfce \
  /home/aboalam/yocto/meta-openembedded/meta-multimedia \
  /home/aboalam/yocto/meta-qt5 \
  "
```

## local.conf

- We will set Machine and Distro

```bash
MACHINE ?= "raspberrypi3-64"
DISTRO ?= "Aboalam"
```

## In our Layer

- We will make our distro called Aboalam
![Screenshot from 2024-08-26 20-44-38](https://github.com/user-attachments/assets/a542d841-891c-4785-9e03-9d1dc68049d1)

```bash
include meta-poky/conf/distro/poky.conf

DISTRO = "Aboalam"
DISTRO_NAME = "Aboalam"
#DISTRO_VERSION = "3.4+snapshot-${METADATA_REVISION}"
DISTRO_VERSION = "4.0.20"
DISTRO_CODENAME = "kirkstone"

MAINTAINER = "abdoabo3lm@gmail.com"

Aboalam_DEFAULT_DISTRO_FEATURES = "largefile opengl ptest multiarch wayland vulkan ssh wifi qt5 x11"

DISTRO_FEATURES ?= "${DISTRO_FEATURES_DEFAULT} ${Aboalam_DEFAULT_DISTRO_FEATURES}"
```

## In bsp recipe

- We will add all our Apps and features that we want to our image

```bash
SAMMARY = "Custome Image Sato for RPI 3+b"
DESCRIPTION = "This Image maked by Aboalam"



LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


EXTRA_IMAGE_FEATURES ?= "debug-tweaks"


IMAGE_INSTALL:remove = "dropbear"

IMAGE_INSTALL:append = " python3 openssh bash systemd systemd-serialgetty \
 util-linux \
    bluez5 \
    i2c-tools \
    bridge-utils \
     pi-bluetooth "


IMAGE_INSTALL:append = " apt bash git"



#For Systemd
DISTRO_FEATURES:append = " systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = "systemd-compat-units"
IMAGE_INSTALL += " packagegroup-core-boot"
IMAGE_ROOTFS_EXTRA_SPACE = "5242880"
IMAGE_INSTALL:append = " x11vnc"



IMAGE_INSTALL:append = " openssh-sftp-server rsync"
IMAGE_INSTALL:append = "  python3-modules python3-misc python3-dev"

IMAGE_INSTALL:append = " \
    python3 \
    util-linux \
    bluez5 \
    i2c-tools \
    bridge-utils \
    hostapd \
    iptables \
    wpa-supplicant \
    pi-bluetooth \
    bluez5-testtools \
    udev-rules-rpi \
    linux-firmware \
    iw \
    kernel-modules \
    linux-firmware-ralink \
    linux-firmware-rtl8192ce \
    linux-firmware-rtl8192cu \
    linux-firmware-rtl8192su \
    linux-firmware-rpidistro-bcm43430 \
    linux-firmware-bcm43430 \
    connman \
    connman-client \
    dhcpcd \
    openssh \
    psplash \
    psplash-raspberrypi \
    coreutils \
"

DISTRO_FEATURES:append = " \
    bluez5 \
    bluetooth \
    wifi \
    pi-bluetooth \
    linux-firmware-bcm43430 \
    systemd \
    usrmerge \
    ipv4 \
"

MACHINE_FEATURES:append = " \
    bluetooth \
    wifi \
    vc4graphics \
"
XSERVER ?= "xserver-xorg \
            xf86-video-fbdev \
            xf86-video-modesetting \
            "
XSERVERCODECS ?= ""

RDEPENDS:${PN} = "\
    ${XSERVER} \
    ${XSERVERCODECS} \
    "
IMAGE_FEATURES:append = " \
    splash \
"
IMAGE_INSTALL:append = " xserver-xorg xf86-video-fbdev xf86-input-evdev xterm matchbox-wm"
```
## In pakages recipe

- We will add and build our Qt app


![Screenshot from 2024-08-26 21-00-49](https://github.com/user-attachments/assets/29d8cf8f-35f4-4b93-9fc5-09aab7f3fb25)

```bash
SAMMARY = "Custome Image Sato for RPI 3+b"
DESCRIPTION = "This Image maked by Aboalam"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://main.cpp \
           file://cppsignalsender.cpp \
           file://cppsignalsender.h \
           file://main.qml \
           file://images.png \
           file://CPPtoQml.pro \
           file://CPPtoQml.pro.user"

inherit qmake5
DEPENDS += "qtbase qttools"

S = "${WORKDIR}"

#QT configuration
IMAGE_INSTALL:append = " make cmake"
IMAGE_INSTALL:append = " qtbase-tools qtbase qtdeclarative qtimageformats qtmultimedia qtquickcontrols2 qtquickcontrols qtbase-plugins cinematicexperience liberation-fonts qtbase-dev curl wget userland >
DISTRO_FEATURES:append = " x11 opengl wayland"
PACKAGECONFIG_FONTS:pn-qtbase = " fontconfig"

do_compile() {
    oe_runmake -C ${B}
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/rbpiqt ${D}${bindir}
}

FILES_${PN} += "${bindir}/rbpiqt"
```
- In folder files we will add our src files of our project

## In aboalam-image recipe

- This recipe we will make it to run our core image in my case I used sato image

```bash
DESCRIPTION = "Image with Sato, a mobile environment and visual style for \
mobile devices. The image supports X11 with a Sato theme, Pimlico \
applications, and contains terminal, editor, and file manager."
HOMEPAGE = "https://www.yoctoproject.org/"

IMAGE_FEATURES += "splash package-management x11-base x11-sato ssh-server-dropbear hwcodecs"

LICENSE = "MIT"

LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


inherit core-image

TOOLCHAIN_HOST_TASK:append = " nativesdk-intltool nativesdk-glib-2.0"
TOOLCHAIN_HOST_TASK:remove:task-populate-sdk-ext = " nativesdk-intltool nativesdk-glib-2.0"

QB_MEM = '${@bb.utils.contains("DISTRO_FEATURES", "opengl", "-m 512", "-m 256", d)}'
QB_MEM:qemuarmv5 = "-m 256"
QB_MEM:qemumips = "-m 256"

IMAGE_FSTYPES = "tar.bz2 ext4 rpi-sdimg"

DL_DIR ?= "/home/aboalam/yocto/poky/build/downloads"


SSTATE_DIR ?= "/home/aboalam/yocto/poky/build/sstate-cache"

IMAGE_INSTALL:append = "  "
```
## Our Image is ready 
- we can find our image in env `yocto/poky/build_rpi/tmp-glibc/deploy/images/raspberrypi3-64`

```bash
ls | grep sdimg
```

![Screenshot from 2024-08-26 21-07-26](https://github.com/user-attachments/assets/dfeb840d-625c-4ab3-82c0-9e2cb95fa986)


- Now we will add our Image to SD card

```bash
sudo dd if=aboalam-image-raspberrypi3-64-20240825094957.rootfs.rpi-sdimg of=/dev/sdb bs=4M status=progress
sync
```

