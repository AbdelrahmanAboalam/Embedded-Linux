# How to locate kernel by creating file(extlinux)

- First we want to make dirctory in sd card called extlinx
- And inside it we make file called extlinux.conf and we will write inside it

```bash
DEFAULT myext
LABEL myext
	KERNEL ../zImage
	FDT ../vexpress-v2p-ca9.dtb
```
- `zImage` is the kernal in sd card and want to load it in kernal address
- `vexpress-v2p-ca9.dtb` is the configs of our target wnat to load it in ftd address

- Then in qemu we will run the commadn do run it
```bash
bootflow scan
```
![Screenshot from 2024-07-22 13-21-30](https://github.com/user-attachments/assets/b9e97a9c-69e0-4467-848c-4c624d3b221f)

