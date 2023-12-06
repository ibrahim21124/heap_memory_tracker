#! /bin/bash
cd make
make clean > log.txt
make >> log.txt
echo "Output Generated"
cd ../bin
./app.out