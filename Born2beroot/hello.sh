#!/bin/bash

arch=$(uname -a)

pro=$(grep "physical id" /proc/cpuinfo | wc -l)

vpro=$(grep "processor" /proc/cpuinfo | wc -l)

memused=$(free -m | grep "Mem" | awk '{print $3}')

memorytotal=$(free -m | grep "Mem" | awk '{print $2}')

percentage=$(free -m | grep "Mem" | awk '{printf"%.2f", ($3/$2)*100}')

Diskuse=$(df -m | grep "/dev/" | grep -v  "/boot" | awk '{memoryuse += $3} END {print memoryuse}')

Disktotal=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{memorytotal += $2} END {printf ("%.fGB"), memorytotal/1024}')
percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{per += $2} {prs += $3} END {printf("%d%%"), prs/per * 100}')
cpuload=$(vmstat 1 2 | tail -1 | awk '{print $15}')
reboot=$(uptime -s | awk -F: '{print $1 ":" $2}')
lvmuse=$(lsblk | grep -q lvm && echo yes || echo no)
tcp=$(ss -ta | grep ESTAB | wc -l)
user=$(users | wc -w)
ip=$(hostname -I | awk '{print $1}')
macadd=$(ip link | grep "link/ether" | awk '{print $2}')

echo"   Architecture: $arch
	CPU phisical: $pro
	vCPU : $vpro
	Memory Usage: $memused/$memorytotal"MB" ($percentage%)
	Disque Usage: $Diskuse/$Disktotal ($percent)
	CPU load: $cpuload%
	Last boot: $reboot
	LVM : $lvmuse
	TCP : $tcp ESTABLISHED
	User log : $user
	Network : IP $ip ($macadd)"
