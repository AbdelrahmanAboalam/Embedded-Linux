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
IMAGE_INSTALL:append = " qtbase-tools qtbase qtdeclarative qtimageformats qtmultimedia qtquickcontrols2 qtquickcontrols qtbase-plugins cinematicexperience liberation-fonts qtbase-dev curl wget userland gstreamer1.0-plugins-bad qtsvg"
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
