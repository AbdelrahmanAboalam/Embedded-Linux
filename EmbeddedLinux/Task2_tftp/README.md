# How To use TFTP 

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

