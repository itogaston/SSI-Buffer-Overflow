#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/random.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>

char input[1048];

int main(){

	int socket_server,socket_client,i;
	int clientsize;
	struct sockaddr_in server,client;

	socket_server = socket(AF_INET, SOCK_STREAM, 0);
	bzero((char *)&server,sizeof(server));

	server.sin_family = AF_INET; //asignamos a la estructura
	server.sin_port = htons(80);
	server.sin_addr.s_addr = INADDR_ANY;

	if(bind(socket_server, (struct sockaddr *)&server, sizeof(server)) >= 0){

		struct ifreq ifr;
		size_t if_name_len=strlen("eth0");

		if (if_name_len<sizeof(ifr.ifr_name)) {
			memcpy(ifr.ifr_name,"eth0",if_name_len);
			ifr.ifr_name[if_name_len]=0;
		}

		ioctl(socket_server,SIOCGIFADDR,&ifr);

		struct sockaddr_in* ipaddr = (struct sockaddr_in*)&ifr.ifr_addr;
		printf("I have a web on %s protected by password.\n",inet_ntoa(ipaddr->sin_addr));

		listen(socket_server, 3);

		clientsize=sizeof(client);

		while(1==1){
			

			socket_client = accept(socket_server,(struct sockaddr *)&client,&clientsize);

			if(socket_client >= 0){

				memset(input,0,sizeof(input));

				recv(socket_client, input,1000,0);
				char buffer [2000];
  				int cx = snprintf ( buffer, 100, "input %s", input );
				send(socket_client, buffer,strlen(buffer), 0);

				printf("socket cli %d", socket_client);
				if(strncmp("GET /",input,5) != 0){

					send(socket_client, bad,strlen(bad), 0);

				}else{

					if(strstr(input,response) == NULL){

						send(socket_client, header,strlen(header), 0);

					} else {

						send(socket_client, ni,strlen(ni), 0);
						send(socket_client,flagstr,strlen(flagstr),0);
						send(socket_client,"\r\n",2,0);

					}

				}

				close(socket_client);

			}

		}

	}
	close(socket_server);
	exit(0);

}
