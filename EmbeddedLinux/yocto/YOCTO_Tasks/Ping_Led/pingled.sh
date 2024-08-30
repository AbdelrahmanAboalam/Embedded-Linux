#!/bin/bash


LED_RED_PIN=2
LED_GREEN_PIN=3


if [ -z "$1" ]; then
    echo "Usage: $0 <IP_ADDRESS>"
    exit 1
fi


IP_ADDRESS="$1"


setup_gpio() {
    echo "$LED_RED_PIN" > /sys/class/gpio/export
    echo "$LED_GREEN_PIN" > /sys/class/gpio/export
    echo "out" > /sys/class/gpio/gpio$LED_RED_PIN/direction
    echo "out" > /sys/class/gpio/gpio$LED_GREEN_PIN/direction
}


cleanup_gpio() {
    echo "$LED_RED_PIN" > /sys/class/gpio/unexport
    echo "$LED_GREEN_PIN" > /sys/class/gpio/unexport
}


control_leds() {
    if ping -c 1 "$IP_ADDRESS" > /dev/null 2>&1; then
        echo "1" > /sys/class/gpio/gpio$LED_GREEN_PIN/value
        echo "0" > /sys/class/gpio/gpio$LED_RED_PIN/value
    else
        echo "0" > /sys/class/gpio/gpio$LED_GREEN_PIN/value
        echo "1" > /sys/class/gpio/gpio$LED_RED_PIN/value
    fi
}


main() {
    setup_gpio

    while true; do
        control_leds
        sleep 10  
    done
}


trap cleanup_gpio EXIT

main

