#ifndef MULTI_THREAD_H_
#define MULTI_THREAD_H_
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>

int my_socket(void);

void my_perror(char* str);

void my_bind(int sock_fd);

void my_listen(int sock_fd);

void my_accept();
#endif


