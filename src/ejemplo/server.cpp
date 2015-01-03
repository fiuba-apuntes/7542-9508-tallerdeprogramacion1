#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring> //Necesario para el memset
#include <cstdio>

#define BACKLOG 20

int main(int, char**){
	printf("Iniciando el servidor\n");
	int socketFd = socket(PF_INET, SOCK_STREAM, 0); //Creo el socket

	struct sockaddr_in address; //Armo los datos para bindearse
	address.sin_family = AF_INET;
	address.sin_port = htons(8080); //Seteo el puerto, en formato de red
	address.sin_addr.s_addr = INADDR_ANY;
	memset(address.sin_zero, 0, sizeof(address.sin_zero));
	//Bindeo al puerto 8080
	bind(socketFd, (struct sockaddr*) &address, sizeof(struct sockaddr_in));

	listen(socketFd, BACKLOG); //Pasivo el socket

	printf("Esperando conexión...\n");
	//Acepto una conexión e ignoro la información de la misma
	int clientFd = accept(socketFd, 0, 0);
	printf("Conexión aceptada\n");
	
	int bytesSent = 0;

	printf("Enviando datos\n");
	//Le envío 30 bytes al cliente (un número arbitrario)
	while (bytesSent < 30 && bytesSent != -1){ 
		char message[30] = "Este es un mensaje prueba :D\n";
		// Agrego offsets si es que no se envía todo el mensaje
		bytesSent = send(clientFd, message + bytesSent, 30 - bytesSent, MSG_NOSIGNAL); 
		printf("Recibido %d bytes\n", bytesSent);
	}
	printf("Datos enviados\n");

	shutdown(socketFd, 0); //Dejo de transmitir datos
	shutdown(clientFd, 0);
	
	close(socketFd);
	close(clientFd);

	printf("Adios, vuelvas prontos\n");

	return 0;
}
