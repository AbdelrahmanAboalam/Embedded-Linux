# Yocto Intro and Build

- [Installing](https://github.com/Aboalam15/Embedded-Linux/tree/main/EmbeddedLinux/yocto/yocto_intro#installing) - [Building](https://github.com/Aboalam15/Embedded-Linux/tree/main/EmbeddedLinux/yocto/yocto_intro#building)

## Installing

- Required for build
```bash
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint3 xterm
```
```bash
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio  python3 python3-pip python3-pexpect
```
- Then download poky
```bash
git clone -b dunfell git://git.yoctoproject.org/poky.git
```
- Then we want to change the branch to kirkstone
```bash
git switch kirkstone
```

## Building
- Then we want to make environment to build
```bash
cd poky
source oe-init-build-env
```
 **Note** `you should run it every time you open new terminal to setup the Variables`

- Now we will chosse our target and make some configurations
```bash
cd build/conf
nano local.conf
```
- ```bash
  MACHINE ??= "qemux86-64"

  BB_NUMBER_THREADS ?= "8"
  PARALLEL_MAKE ?= "-j 8"
  ```
  1- `MACHINE ??= "qemux86-64"` That for target
  2- `BB_NUMBER_THREADS ?= "8"` That to give it for build 8 thread
  3- `PARALLEL_MAKE ?= "-j 8"`used to specify the 8 parallel jobs to run when invoking the make command during the build process.
- Now we can build our image
```bash
bitbake core-image-minimal
```
`It will take around 3 hours`

- Now you can rum your Image
```bash
runqemu qemux86-64 nographic
```
![Screenshot from 2024-08-06 22-36-34](https://github.com/user-attachments/assets/c61dd52a-a629-4bf9-91aa-3bf67cef4a8c)


