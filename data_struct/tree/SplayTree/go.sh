#! /bin/bash

rm include lib -rf

mkdir include lib

gcc -g -c SplayTree.c -fpic

gcc -shared -o libSplayTree.so SplayTree.o

rm SplayTree.o

mv libSplayTree.so lib

cp SplayTree.h include

cp ./lib/libSplayTree.so /usr/lib

gcc -g main.c -L./lib -I./include -lSplayTree -o app
