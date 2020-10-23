#! /bin/bash

rm lib include -rf

mkdir lib include

gcc queue.c -c

ar rcs libqueue.a queue.o

mv libqueue.a lib

cp queue.h include

rm queue.o

gcc main.c -L./lib -I./include -lqueue -o app
