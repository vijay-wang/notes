#! /bin/bash

rm include lib -rf

mkdir include lib

gcc -c -g avl.c -fpic

gcc -shared -o libavl.so avl.o

rm avl.o

mv libavl.so lib

cp avl.h include

sudo cp ./lib/libavl.so /usr/lib

gcc main.c -g -L./lib -I./include -lavl -o app
