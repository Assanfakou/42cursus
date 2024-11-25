#!/bin/bash

arch=$(uname -a)
echo "#Architecture: $arch"

pro=$(grep "physical id" /proc/cpuinfo | wc -l)

echo "#CPU physical : $pro"

vpro=$(grep "processor" /proc/cpuinfo | wc -l)

echo "#vCPU : $vpro"

memused=$(free -m | grep "Mem" | awk '{print $3}')

memorytotal=$(free -m | grep "Mem" | awk '{print $2}')

percentage=$(free -m | grep "Mem" | awk '{printf"%.2f", ($3/$2)*100}')

echo "#Memory Usage: $memused/$memorytotal"MB" ($percentage%)"

Diskuse=$(df -m | grep "/dev/" | grep -v  "/boot" | awk '{memoryuse += $3} END {print memoryuse}')

Disktotal=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{memorytotal += $2} END {printf ("%.fGB"), memorytotal/1024}')
percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{per += $2} {prs += $3} END {printf("%d%%"), prs/per * 100}')
echo "#Disk Usage: $Diskuse/$Disktotal ($percent)"
cpuload=$(vmstat 1 2 | tail -1 | awk '{print $15}')
echo "#CPU louad: $cpuload%"
reboot=$(uptime -s | awk -F: '{print $1 ":" $2}')
echo "#Last boot: $reboot"
lvmuse=$(lsblk | grep -q lvm && echo yes || echo no)
echo "#LVM : $lvmuse"
tcp=$(ss -ta | grep ESTAB | wc -l)
echo "#TCP : $tcp ESTABLISHED"
user=$(users | wc -w)
echo "#User log : $user"
ip=$(hostname -I | awk '{print $1}')
macadd=$(ip link | grep "link/ether" | awk '{print $2}')
echo "#Network : IP $ip ($macadd)"
