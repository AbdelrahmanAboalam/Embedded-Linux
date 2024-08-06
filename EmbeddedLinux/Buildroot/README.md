# BuildRoot

- [Installing](https://github.com/Aboalam15/Embedded-Linux/blob/main/EmbeddedLinux/Buildroot/README.md#installing) / [Add Package](https://github.com/Aboalam15/Embedded-Linux/edit/main/EmbeddedLinux/Buildroot/README.md#adding-package-to-buildroot)
## Installing
- Required Library
```bash
sudo apt install sed make binutils gcc g++ bash patch \
gzip bzip2 perl tar cpio python unzip rsync wget libncurses-dev
```
- Downloading
```bash
git clone https://github.com/buildroot/buildroot.git
```
* If you have error in clone try this
```bash
git config --global http.postBuffer 524288000 ; git clone --depth 1 https://github.com/buildroot/buildroot.git
```
- To list targets
```bash
make list-defconfigs
```
- For Qemu
```bash
make qemu_arm_vexpress_defconfig
```
- Now we will make configuration
```bash
make menuconfig
```
- Init procecss to System V or System D or Busybox init
- Now we Will build
```bash
make 2>&1 | tee build.log
```
`It will take around 3 hours `

- Now your Image is ready to run
```bash
cd output/images/
./start-qemu.sh
```
![Screenshot from 2024-08-06 21-39-30](https://github.com/user-attachments/assets/b80e8568-505c-491b-b0c0-804ef32cb617)

# Adding Package to buildroot

- First we will go to make dir for our package
```bash
mkdir Thread
cd Thraed
touch app.cpp  app.mk  Config.in  Makefile
```
- Then we will write our code in app.cpp
```cpp
#include <iostream>
#include <thread>

void thread1() {
    std::cout << "Hello, You are in thread 1" << std::endl;
}
void thread2() {
    std::cout << "Hello, You are in thread 2" << std::endl;
}
void thread3() {
    std::cout << "Hello, You are in thread 3" << std::endl;
}


int main() {
    // Create three threads
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);


    t1.join();
    t2.join();
    t3.join();

    return 0;
}
```
- Then we will make Makefile
```make
.PHONY: clean
.PHONY: app

Demoapp: app.cpp
    $(CC) -o '$@' '$<'

clean:
    -rm app
```
- Now we will inform buildroot how to build pakage in `Config.in`
```txt
config BR2_PACKAGE_APP
    bool "APP"
    help
        app package.
```
- Now we will write the markdown
```Makefile
################################################################################
#
# app package  Abdelrahman Aboalam
#
################################################################################

APP_VERSION = 1.0
APP_SITE = package/app/src
APP_SITE_METHOD = local# Other methods like git,wget,scp,file etc. are also available.

define APP_BUILD_CMDS
    $(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D)
endef

define APP_INSTALL_TARGET_CMDS
    $(INSTALL) -D -m 0755 $(@D)/app  $(TARGET_DIR)/usr/bin
endef

$(eval $(generic-package))
```

- Then we go to choose where we will add our package from Config.in in package dir
```bash
cd ..
vim Config.in
```
![Screenshot from 2024-08-06 22-05-53](https://github.com/user-attachments/assets/5a4b04c9-bb0f-40ac-9c9f-ce4034187a74)

## Now we will see it in menuconfig

```bash
cd ../..
make menuconfig
```
![Screenshot from 2024-08-06 12-06-47](https://github.com/user-attachments/assets/8a1a3673-334a-4f6d-bc53-1d54a01e88d3)

- And if you search for pakage you will see it
  
![Screenshot from 2024-08-06 12-06-25](https://github.com/user-attachments/assets/35c11769-6126-4780-873e-d963ad9a4a99)


