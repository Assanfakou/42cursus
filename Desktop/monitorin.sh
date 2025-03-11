#!/bin/bash

# Get the session ID of the current user
SESSION_ID=$(loginctl | grep $(whoami) | awk '{print $1}')

# Start an infinite loop to monitor session lock status
while true; do
    # Check if the session is locked using the session ID
    SESSION_STATE=$(loginctl show $SESSION_ID --property=Locked --value)

    # If the session is locked, disable Bluetooth
    if [ "$SESSION_STATE" == "yes" ]; then
        ~/Desctop/lock_bluetooth.sh
    fi

    # Sleep for a few seconds before checking again
    sleep 5
done

