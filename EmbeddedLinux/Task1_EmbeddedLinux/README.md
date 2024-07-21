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



- Now we will run U-boot using Qemu
```bash
sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -net nic -net tap,ifname=tap0,script=no -kernel u-boot -sd ~/Desktop/sdcard/sd.img
```

## In qemu we will give it IP

- We will set the variable environment to qemu in ipaddr
```bash
setenv ipaddr 192.168.100.10
```
- Then we try to ping
- ```bash
ping 192.168.100.1
```
