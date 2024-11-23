#!/bin/bash

arch=$(uname -a)
echo "Architecture: $arch"

pro=$(grep "physical id" /proc/cpuinfo | wc -l)

echo "CPU physical : $pro"

vpro=$(grep "processor" /proc/cpuinfo | wc -l)

echo "vCPU : $vpro"

mem=$(free -m | grep "Mem" | awk '{print $3}')

echo "Memory Usage: $mem"
