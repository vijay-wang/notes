#include "multi_thread.h"

//初始化一个套接字

void my_perror(char* str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int my_socket(void)
{
	int sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(sock_fd) my_perror("socket"); 
	return sock_fd;
}

void my_bind(int sock_fd)
{
	//初始化struct sockeaddr 结构体
	struct sockaddr_in bind_addr;
	memset(&bind_addr,0,(size_t)sizeof(bind_addr));
	bind_addr.sin_family = AF_INET;
	bind_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind_addr.sin_port = htons(3000);

	//绑定struct sockaddr_in 结构体
	int bind_ret = bind(sock_fd,(const struct sockaddr*)&bind_addr,sizeof(bind_addr));
	if(bind_ret)	my_perror("bind");
}


void my_listen(int sock_fd)
{
	if(listen(sock_fd,511)) my_perror("listen");
}

void my_accept()
{

	accept();

}

while()
{

}


int main()
{

	return 0;
}
