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

IMAGE_FEATURES += "splash package-management"

IMAGE_INSTALL:append = " xserver-xorg xf86-video-fbdev xf86-input-evdev xterm matchbox-wm"

# IMAGE_FSTYPES = "tar.bz2 ext4 rpi-sdimg"