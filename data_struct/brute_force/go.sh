#! /bin/bash

rm include lib -rf

mkdir include lib

gcc -c brute_force.c -fpic

gcc -shared -o libbrute_force.so brute_force.o

rm brute_force.o

mv libbrute_force.so lib

cp brute_force.h include

gcc main.c -L./lib -I./include -lbrute_force -o app
