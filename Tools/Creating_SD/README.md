# Creating Virtual SD

- First we want to creat file called sd.img
```bash
touch sd.img
```
- Second we want to give the SD size by full it with Zeros
```bash
dd if=/dev/zero of=sd.img bs=1M count=1024
```

- Third we will make partitions and type of them by using
```bash
cfdisk sd.img
```
- We will select `dos`
![sd1](https://github.com/user-attachments/assets/41d8b88e-af08-48dd-9fcb-7c7cd7099d7a)
- From `new` we will add partition size let say 500M then `primary`
- From `type` we will select `FAT16` 
- We will make anther partition and type will be `Linux` as a `ext4`
- And then make `Bootable` for FAT16
- Then make write and yes

![sd3](https://github.com/user-attachments/assets/ea7d33c4-b169-4e34-bdba-b8886022879e)

- Now we want to make it run in our device and give them loops
```bash
losetup -f --show --partscan sd.img
```
