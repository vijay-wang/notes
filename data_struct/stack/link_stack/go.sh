#! /bin/bash

rm include lib -rf

mkdir include lib

gcc -c link_stack.c

ar rcs liblink_stack.a link_stack.o

mv liblink_stack.a lib

rm link_stack.o

cp link_stack.h include

gcc main.c -L./lib -I./include -llink_stack -o app
