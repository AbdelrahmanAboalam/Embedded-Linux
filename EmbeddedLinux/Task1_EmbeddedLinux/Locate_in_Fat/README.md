# Run Script in qemu during booting

We want to wirte script to load images in memory and convert it to binary as image to can run it in qemu and we will put it in memory to run it

- First we write script using U-boot commands to load the files from SD to our memory (you can know more about u-boot commands here [Link](https://hub.digi.com/dp/path=/support/asset/u-boot-reference-manual/)
```bash
if mmc dev; then
    fatload mmc 0:1 0x60002000 zImage
    fatload mmc 0:1 0x60002500 file.dtp
elif ping 192.168.100.1; then
    echo "load from network"
else
    echo "No Option"
fi

setenv loadbootsc no
saveenv
```
1. `mmc dev` using to check if there SD card
2. `fatload` using to load file called `zImage` from SD card and put it in address '0x60002000'
3. If we didn't find SD try to ping to my from network

- Now we have script as .txt we want to convert it to can running in u-boot so we will using `mkimage`

```bash
mkimage -T script -n "Script" -C none -d myscript.txt scriptingboot
```
1. `-T script` type of file is script not Image
2. `-C none` not compressed
3. Then we will put the input `-d myscript.txt` and outputfile `scriptingboot`
- After you run this command you well se the header of file and new file generated
  ![makeimage](https://github.com/user-attachments/assets/50a7790e-f000-415a-bb80-c5b885bc68d2)

## In qemu

- First step we will run qemu
```bash
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0,script=no -kernel u-boot -sd ~/Desktop/sdcard/sd.img
```
- Then we will add the script in varenv `bootcmd` to run it during booting
```bash
editenv bootcmd
echo Aboalam; fatload mmc 0:1 0x60003000 scriptingboot; source 0x60003000
```
![addscript](https://github.com/user-attachments/assets/b23be5bd-a035-4af2-9218-6eb27fb17044)

- After runing the qemu again and check every address you will see the file loaded in memory
```bash
md 0x60002000
```
![load_in_mmc](https://github.com/user-attachments/assets/2dea22f5-a859-4d94-bb2d-7d37cb38c28c)


