#!/bin/bash


bashrc_file="$HOME/.bashrc"

if [ -f "$bashrc_file" ]; then
 


    echo "export hello=\$(hostname)" >> "$bashrc_file"
    echo "local=\$(whoami)" >> "$bashrc_file"

   
    gnome-terminal &
else
    echo "Error: does not exist."

fi

