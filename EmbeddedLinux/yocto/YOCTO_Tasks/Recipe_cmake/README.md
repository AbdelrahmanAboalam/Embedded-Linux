# How to write recipe

**Description**

- The recipe is the file that write some configs to tell bitbake what you want during building
- Now we well write simple recipe to fetch app from github and compile it then moving it under usr/bin


##  Recibe.bb

- The hierarchical of our recipe is under your `layer Dir` under `recipes-name Dir` undr `meta-name`

![Screenshot from 2024-08-16 12-43-31](https://github.com/user-attachments/assets/29d5e1ae-34dc-4829-877b-c1e335f3aa08)


1- Now we wil write headr of recipe
```bash
SAMMARY = "My Summary"
DESCRIPTION = "Demo To write recipe"
```
- That to define our recipe

2- Then we will write our license
- We will use MIT license and we need to applay check sum to it

```bash
cd poky/meta/files/common-licenses/
md5sum MIT
```
![Screenshot from 2024-08-16 12-27-14](https://github.com/user-attachments/assets/6961e092-f8f8-413e-980d-ec15bdd4e65b)

- After that we can add our license in recipe
```bash
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/files/common-licenses/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
```
- We can use license CLOSEED and we if use it we won't to make check sum

3- Now we want to fetch the app from git hub 

- **Schema** of git it is `git://<repo-URL without https>;protocol=https;branch=main`
- We need to add source version that is tha last commit in repo
```bash
SRC_URI = "git://github.com/FadyKhalil/DemoApp.git;protocol=https;branch=main"
SRCREV="720c663c5fd7246b4b42c5205d74db7d9784b5b2"
```

4- Now we will define how we can use cmake to creat Makefile

- We will define cmake as dependans in this recipe

```bash
DEPENDS = "cmake"
```
- Now we will inherit cmake class to use it in building
 ```bash
inherit cmake
```
- We also want to make dirs to compatable with cmake

 ```bash
S = "${WORKDIR}/git"
B = "${WORKDIR}/build"
D = "${WORKDIR}/image"
```

- Now we will run cmake in do_configure to create Makefile before compiling stage

```bash
do_configure(){
  cmake -S ${S} -B ${B} -DCMAKE_EXE_LINKER_FLAGS="-static" -DCMAKE_SHARED_LINKER_FLAGS="-static"
}
```
5- Now we will compile it and install app in /usr/bin

- Note in recipe we use `oe_runmake` instead of make
- `B` is the Directory where I want to build my app  
```bash
do_compile() {
     oe_runmake -C ${B}
}
```
- `D` is the distnation of exe files
- `bindire` is act as `/usr/bin`
```bash
do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${B}/calculator ${D}${bindir}/
}
```

![Screenshot from 2024-08-16 14-57-57](https://github.com/user-attachments/assets/4a526d89-aa65-45ba-bac1-00717860dc92)


