#! /bin/bash

rm include lib -rf

mkdir include lib

gcc -g -c kmp.c -fpic

gcc -shared -o libkmp.so kmp.o

rm kmp.o

mv libkmp.so lib

cp ./lib/libkmp.so /usr/lib

gcc main.c -L./lib -I./include -lkmp -o app 
