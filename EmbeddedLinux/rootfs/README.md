# Run kernel with rootfs

I will be continue description

From busy box

![Screenshot from 2024-07-26 08-41-03](https://github.com/user-attachments/assets/64550cc5-c646-430f-93c9-7e83d81c166e)

- rcS

```bash
#!/bin/sh
# mount a filesystem of type `proc` to /proc
mount -t proc nodev /proc
# mount a filesystem of type `sysfs` to /sys
mount -t sysfs nodev /sys
# mount devtmpfs if you forget to configure it in Kernel menuconfig
#there is two options uncomment one of them  
mount -t devtmpfs devtempfs /dev
```

- inittab

```bash
::sysinit:/etc/init.d/rcS
ttyAMA0::askfirst:-/bin/sh
::restart:/sbin/init
```
- After run it in Qemu and make changes in bootargs

![Screenshot from 2024-07-24 14-01-30](https://github.com/user-attachments/assets/2bd27deb-05c2-425a-80b2-d77f895810df)


