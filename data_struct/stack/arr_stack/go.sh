#! /bin/bash
rm include lib -rf

gcc -c arr_stack.c

ar rcs libarr_stack.a arr_stack.o

rm arr_stack.o

mkdir include lib

mv libarr_stack.a lib

cp arr_stack.h include

gcc main.c -I./include -L./lib -larr_stack -o app
