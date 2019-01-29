#!/bin/bash
if [ "$1" == "" ] 
then
echo "Usage: ./pginscript.sh [network]"
echo "example: ./pingscript.sh 192.168.0"
else
for x in `seq 1 254`; do
ping -c 1 $1.$x | grep "64 bytes" | cut -d" " -f4 | sed 's/.$//' | tee -a ip.list
done
fi

