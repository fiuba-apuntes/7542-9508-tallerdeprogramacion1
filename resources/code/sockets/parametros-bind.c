struct sockaddr_in {
  sa_family_t sin_family; /* address family: AF_INET */
  in_port_t sin_port;     /* puerto en formato de red (pasarle htons(port)) */
  in_addr sin_addr;       /*IP a la que se quiere asociar */
};