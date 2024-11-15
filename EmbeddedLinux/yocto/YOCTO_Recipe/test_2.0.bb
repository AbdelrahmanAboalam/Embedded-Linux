SAMMARY = "My Summary"
DESCRIPTION = "Demo To write recipe"



LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


# SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"
# SRCREV="720c663c5fd7246b4b42c5205d74db7d9784b5b2"


FILESPATH:append = " :${THISDIR}:"
SRC_URI = "file://main.c"


do_compile () {
    ${CC} ${CFLAGS} -static ${WORKDIR}/main.c -o ${B}/myapp
}


do_install() {
    mkdir -p ${D}${bindir}
    cp ${B}/myapp ${D}${bindir}
}