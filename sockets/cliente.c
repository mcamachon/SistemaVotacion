#include <stdbool.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int NumArg, int votar, char *msj[])
{
	int cand_A = 0, cand_B = 0, vacio = 0;
//	int votar;
	int seguir;
	bool activo = true;

	printf("Votación: Elije numero de candidato y despues 1 para votar de nuevo o 0 para salir de la votción");

	while (activo) {
		printf("Vota Ahora \n");
		scanf("%i", &votar);

		switch (votar) {
		case 1:
			cand_A++;
			break;
		case 2:
			cand_B++;
			break;
		default: vacio++;
		}

		printf("Ingresa 0 para salir \n");
		scanf("%i", &seguir);
		if (seguir == 0) activo = false;
	}

	// resultados
	printf("Votos totales: %i\n", cand_A + cand_B + vacio);

	if (cand_A != cand_B) {
		printf("Ganó\n");

		if (cand_A > cand_B) printf("A, con %i votos", cand_A);
		else printf("B con %i votos", cand_B);
	}
	else printf("sin dganador");

	//	_getch();
	getstr();









	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	int i;
	//char ch = 'A';
	//char *msj = "hola";	
	//char *msj[] = "hola";
	/* Crear un socket para el cliente */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	/* Nombrar el socket, de acuerdo con el server */
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = htons(9734);
	len = sizeof(address);
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if (result == -1) {
		perror("oops: client1");
		exit(1);
	}
	write(sockfd, msj, 1);
	read(sockfd, msj, 1);
for(i=1; i<NumArg;i++)	printf("Mensaje enviado al servidor = %s \n", msj[i]);
	close(sockfd);
	exit(0);
}


