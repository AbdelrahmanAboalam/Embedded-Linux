SAMMARY = "Script to ping led with IP to control leds"
DESCRIPTION = "This recipe include bash script to run it"



LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"


FILESPATH:append = " :${THISDIR}/files:"
SRC_URI += "file://pingled.sh"

# S = "${WORKDIR}/src"
# D = "${WORKDIR}/Dest"

# RDEPENDS_${PN} += "bash"


do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/pingled.sh ${D}${bindir}/
}