#!/bin/sh
set -x

gcc  -I. -c main.c  
gcc  -I. -c add.c  
gcc  main.o add.o -o aaa
