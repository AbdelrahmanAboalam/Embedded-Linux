# For Adding tap and ping to it

- First we want to creat a script to configure tap and give to it IP
```bash
#!/bin/bash

TAP_IF="tap0"

ip link delete $TAP_IF 2>/dev/null
ip tuntap add dev $TAP_IF mode tap
sudo ip addr add 192.168.100.1/24 dev $TAP_IF
sudo ip link set $TAP_IF up
```
- Second we will run script 
```bash
sudo ./script.sh
```
- Now we will check the ip
```bash
ifconfig
```
![ifconfig](https://github.com/user-attachments/assets/1e0c1bd8-09e3-4edb-850c-c946d892813c)


- Now we will run U-boot using Qemusudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0,script=no -kernel u-boot -sd ~/Desktop/sdcard/sd.img

```bash
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0,script=no -kernel u-boot -sd ~/Desktop/sdcard/sd.img
```

## In qemu we will give it IP

- We will set the variable environment to qemu in ipaddr
```bash
setenv ipaddr 192.168.100.10
```
- Then we try to ping
```bash
ping 192.168.100.1
```
![ping](https://github.com/user-attachments/assets/149d8101-4913-41af-ae0b-480ff95e98b1)
