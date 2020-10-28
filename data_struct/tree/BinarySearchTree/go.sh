#! /bin/bash

rm lib include -rf

mkdir lib include

gcc  -c -g binary_search_tree.c -fpic

gcc -shared -o libbinary_search_tree.so binary_search_tree.o 

rm  binary_search_tree.o

mv  libbinary_search_tree.so lib

sudo cp ./lib/libbinary_search_tree.so /usr/lib

cp  binary_search_tree.h include

gcc -g main.c -L./lib -I./include -lbinary_search_tree -o app

