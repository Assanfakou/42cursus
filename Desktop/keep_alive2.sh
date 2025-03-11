#!/bin/bash

while true; do
    dbus-send --session --dest=org.freedesktop.ScreenSaver \
              --type=method_call /org/freedesktop/ScreenSaver \
              org.freedesktop.ScreenSaver.SimulateUserActivity
    sleep 290
done

