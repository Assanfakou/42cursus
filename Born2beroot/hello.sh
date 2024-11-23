#!/bin/bash

arch=$(uname -a)
echo "Architecture: $arch"

pro=$(grep "physical id" /proc/cpuinfo | wc -l)

echo "CPU physical : $pro"

vpro=$(grep "processor" /proc/cpuinfo | wc -l)

echo "vCPU : $vpro"

memused=$(free -m | grep "Mem" | awk '{print $3}')

memorytotal=$(free -m | grep "Mem" | awk '{print $2}')

percentage=$(free -m | grep "Mem" | awk '{printf"%.2f", ($3/$2)*100}')

echo "Memory Usage: $memused/$memorytotal"MB" ($percentage%)"

Diskuse=$(df -m | grep "/dev/" | grep -v  "/boot" | awk '{memoryuse += $3} END {print memoryuse}')

Disktotal=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{memorytotal += $2} END {printf ("%.fGB"), memorytotal/1024}')
percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{per += $2} {prs += $3} END {printf("%d%%"), prs/per * 100}')
echo "Disk Usage: $Diskuse/$Disktotal ($percent)"


