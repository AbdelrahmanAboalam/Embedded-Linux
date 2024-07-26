# How To use TFTP & Script for Qemu to run it

- First we want to install TFTP in our x86

```bash
sudo apt install tftpd-hpa
```
- Then we will make some changes in configrations to make our server to send and receive
```bash
sudo nano /etc/defalut/tftpd-hpa
```
- We will change `TFTP_OPTIONS` from `--secure` to `--secure --create`

![Screenshot from 2024-07-26 07-08-32](https://github.com/user-attachments/assets/4da8ec0f-02f5-44b5-abb0-c3028b62c16a)

- After that we want to restart tftp

```bash
systemctl restart tftpd-hpa.service 
```
- Then we will put any thing want to share to server in this directory `/sev/tftp`

 - After you put that you want to change owner of the `/srv/tftp` to tftp:tftp
```bash
sudo chown tftp:tftp /srv/tftp
```
## In Qemu

- We will run command to get files from my server
- First we want to set Ip of server (from my laptop `ifconfig`)
- Seconde we run this command to get file and loaded it in address
```bash
tftp $kernel_addr_r zImage
```
![Screenshot from 2024-07-22 00-30-49](https://github.com/user-attachments/assets/0d6b84f9-b19f-4867-9c0a-e35beb820c31)


## To make script for run it in Qemu

- We will write script in U-boot commands The main features is:-
1. To check if There SD card or no
2. Checking for ZImage and dtp file
3. If any of them not found it will be get it from serve


```bash
mmc dev 0
setenv serverip 192.168.100.1
if mmc rescan; then
    echo "SD card detected. Checking for zImage and .dtb..."

    if fatls mmc 0:1 /zImage; then
        echo "zImage found on SD card."

        fatload mmc 0:1 $kernel_addr_r /zImage
        echo "zImage loaded to $kernel_addr_r"

        if fatls mmc 0:1 /file.dtb; then
            echo ".dtb file found on SD card."

            fatload mmc 0:1 $fdt_addr_r /file.dtb
            echo ".dtb loaded to $fdt_addr_r"

        else
            echo ".dtb file not found on SD card. Downloading from TFTP..."

            tftp $fdt_addr_r file.dtb
            echo ".dtb downloaded via TFTP to $fdt_addr_r"
        fi

    else
        echo "zImage not found on SD card. Downloading from TFTP..."

        tftp $kernel_addr_r zImage
        echo "zImage downloaded via TFTP to $kernel_addr_r"

        if tftp $fdt_addr_r file.dtb; then
            echo ".dtb downloaded via TFTP to $fdt_addr_r"
        else
            echo ".dtb download failed via TFTP. Please check the server or file."
        fi
    fi

else
    echo "SD card not detected. Downloading zImage and .dtb via TFTP..."

    tftp $kernel_addr_r zImage
    echo "zImage downloaded via TFTP to $kernel_addr_r"

    tftp $fdt_addr_r file.dtb
    echo ".dtb downloaded via TFTP to $fdt_addr_r"
fi
```
- After that we will change type of script to can run it in U-boot

```bash
mkimage -T script -n "Script" -C none -d myscript.txt scriptingboot
```
- Then in Qemu we will change bootcmd to

```bash
fatload mmc 0:1 0x60003000 scriptingboot; source 0x60003000
```
- Now when you run it again it will run script in booting

![Screenshot from 2024-07-22 02-03-28](https://github.com/user-attachments/assets/5aaff396-52b4-419c-8bc9-10fc4d0b0414)
