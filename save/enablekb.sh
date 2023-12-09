#!/bin/bash

# GS_toggle_touchpad.sh
# - toggle the touchpad on and off

# Gabriel Staples
# Written: 2 Apr. 2018 
# Updated: 12 Sept. 2019 

# References:
# - https://askubuntu.com/a/874865/327339
# - https://askubuntu.com/questions/844151/enable-disable-touchpad/1109515#1109515 <-- my own ans!

# Search for id number of "TouchPad" OR "Touchpad" in `xinput` list; manually type `xinput` to see all your devices
read TouchPadDeviceId <<< $( xinput | sed -nre '/TouchPad|Touchpad/s/.*id=([0-9]*).*/\1/p' ) 

state=$( xinput list-props "Synaptics TM3096-001" | grep "Device Enabled" | grep -o "[01]$" )

echo "TouchPadDeviceId = Synaptics TM3096-001"
echo "state = $state"

if [ "$state" -eq '1' ];then
    sudo xinput disable "Synaptics TM3096-001"
    #sudo xinput --set-prop "Synaptics TM3096-001" "Device Disabled" 0
    #zenity --info --text "Touchpad DISABLED" --timeout=0
    sudo notify-send "Touchpad DISABLED" --expire-time=5
    # Next line required only if using imwheel to fix slow scroll speed in Chrome, for ex; see here: 
    # https://askubuntu.com/a/991680/327339
    # imwheel -b "4 5"
else
    sudo xinput enable "Synaptics TM3096-001"
    sudo synclient touchpadoff=0
    #sudo xinput --set-prop "Synaptics TM3096-001" "Device Enabled" 1
    sudo notify-send "Touchpad ENABLED" --expire-time=5
    #zenity --info --text "Touchpad ENABLED" --timeout=0
    # Next line required only if using imwheel to fix slow scroll speed in Chrome, for ex; see here: 
    # https://askubuntu.com/a/991680/327339
    # killall imwheel
fi
