#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int sock;
	int csock;
	char buffer[1024];
	struct hostent *host;
	struct sockaddr_in sin = {0};
	struct sockaddr_in csin = {0};
	socklen_t sinsize = sizeof(csin);


	sock = socket(AF_INET, SOCK_STREAM, 0);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	if (bind (sock, ((struct sockaddr*)&sin), sizeof(struct sockaddr)) == -1)
	{
		perror("bind()");
		exit(errno);
	}
	if (listen(sock, 5) == -1)
	{
		perror("listen()");
		exit(errno);
	}

	while (42)
	{
		csock = accept(sock, ((struct sockaddr*)&csin), &sinsize);
		if (csock == -1)
		{
			printf("accept pas ok \n");
			perror("accept()");
			exit(errno);
		}
		if (recv(csock, buffer, sizeof(buffer), MSG_WAITALL) == -1)
		{
			perror("recv");
			printf("error recv\n");
		}
		else
		{
			printf("recv -> %s\n", buffer);
		}
	}
	return (0);
}