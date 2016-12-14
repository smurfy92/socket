#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>

int		main(int argc, char **argv)
{
	int sock;
	struct hostent *host;
	struct sockaddr_in sin = {0};

	if (argv[1])
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);
		host = gethostbyname("localhost");
		if (host == NULL)
			printf("host is null\n");
		sin.sin_addr.s_addr =*((unsigned long *)host->h_addr_list[0]);
		sin.sin_port = htons(8888);
		sin.sin_family = AF_INET;
		if (connect(sock, ((struct sockaddr*)&sin), sizeof(struct sockaddr)) == -1)
			perror("socket");
		else
		{
			if (send(sock, (void *)argv[1], strlen(argv[1]) + 1, MSG_OOB) == -1)
				printf("send error\n");
			else
				printf("send ok\n");
		}
	}
}