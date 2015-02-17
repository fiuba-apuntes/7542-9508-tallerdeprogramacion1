#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring> //Necesario para el memset
#include <cstdio>

#define BACKLOG 20
#define MSG_SIZE 30

int main(int, char**){
		printf("Iniciando el cliente en la direccion 127.0.0.1:8080\n");
		int socketFd = socket(PF_INET, SOCK_STREAM, 0); //Creo el socket

		char serverAddress[] = "127.0.0.1";

		struct sockaddr_in address; //Armo los datos para conectarse
		address.sin_family = AF_INET;
		address.sin_port = htons(8080); //Seteo el puerto, en formato de red
		address.sin_addr.s_addr = inet_addr(serverAddress);
		memset(address.sin_zero, 0, sizeof(address.sin_zero));

		int connected = connect(socketFd, (struct sockaddr *) &address,
				sizeof(struct sockaddr_in)); //Me conecto a la direccion.
		if (connected != 0){
				printf("Falla al conectar\n");
				return connected;
		}

		char message[MSG_SIZE];
		int bytesRecv = 0;

		printf ("Recibiendo el mensaje...\n");
		//Le envio 30 bytes al cliente (un numero arbitrario
		while (bytesRecv < MSG_SIZE && bytesRecv != -1){
			// Agrego offsets si es que no se envia todo el mensaje
			bytesRecv += recv(socketFd, message + bytesRecv, MSG_SIZE - bytesRecv, 0); 
			printf("Recibido %d bytes\n", bytesRecv);
		}
		message[29] = 0; //Cierro string

		printf ("Recibo el mensaje %s\n", message);

		shutdown(socketFd, 0); //Dejo de transmitir datos

		close(socketFd); //Cierro file descriptor

		printf("Adios, vuelvas prontos\n");

		return 0;
}
