#include "networking.h"
//don't need a sig handler bc theres no pipe to delete
/*Connect to the server
 *return the to_server socket descriptor
 *blocks until connection is made.*/
int client_tcp_handshake(char * server_address) {

  //getaddrinfo
  struct addrinfo * hints, * results;
  hints = calloc(1,sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; //TCP socket
  hints->ai_flags = AI_PASSIVE; //only needed on server
  //getaddrinfo(NULL, “80”, hints, &results);  //Server sets node to NULL
  int i = getaddrinfo(server_address, PORT, hints, &results);
  err(i, "getaddrinfo");
  printf("got address\n");
  int serverd;//store the socket descriptor here
  //create the socket
 
  serverd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  //err(serverd, socket);
  printf("got the server socket\n");
  //this code should get around the address in use error
  int yes = 1;
  int sockOpt =  setsockopt(serverd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
  err(sockOpt,"sockopt  error");

  // int b = bind(serverd, results->ai_addr, results->ai_addrlen);
  // //printf("b: %d", b);
  // err(b, "bind");
  // printf("bind\n");
  //connect to the server

  int c = connect(serverd, results->ai_addr, results->ai_addrlen);
  //printf("c: %d", c);
  err(c, "connect");
  printf("client handshake connect to server\n");
  free(hints);
  freeaddrinfo(results);

  return serverd;
}

/*Accept a connection from a client
 *return the to_client socket descriptor
 *blocks until connection is made.
 */
int server_tcp_handshake(int listen_socket){
    int client_socket;
    
    socklen_t sock_size;
    struct sockaddr_storage client_address;
    sock_size = sizeof(client_address);
    client_socket = accept(listen_socket,(struct sockaddr *)&client_address, &sock_size);
    //accept the client connection
    printf("server handshake accept\n");
    return client_socket;
}

/*Create and bind a socket.
* Place the socket in a listening state.
*/

/*Create and bind a socket.
* Place the socket in a listening state.
*/
int server_setup() {
  //setup structs for getaddrinfo
  struct addrinfo * hints, * results;//results is allocated in getaddrinfo
  hints = calloc(1,sizeof(struct addrinfo));
  hints->ai_family = AF_INET;
  hints->ai_socktype = SOCK_STREAM; //TCP socket
  hints->ai_flags = AI_PASSIVE; //only needed on server
  getaddrinfo(NULL, PORT, hints, &results);  //Server sets node to NULL
  printf("setup structs for getaddrinfo\n");

  //create the socket
  int clientd;//store the socket descriptor here
	clientd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  printf("create the socket\n");
  
  //this code should get around the address in use error
  int yes = 1;
  int sockOpt =  setsockopt(clientd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
  err(sockOpt,"sockopt  error");

  //bind the socket to address and port
  bind(clientd, results->ai_addr, results->ai_addrlen);
  printf("bind the socket to address and port\n");
  //set socket to listen state
  listen(clientd, 10);
  printf("listen\n");

  int client_socket;
  socklen_t sock_size;
  struct sockaddr_storage client_address;
  sock_size = sizeof(client_address);
  //client_socket = accept(clientd,(struct sockaddr *)&client_address, &sock_size);
  //idk

  //free the structs used by getaddrinfo
  free(hints);
  freeaddrinfo(results);
  
  return clientd;
}

void err(int i, char*message){
  if(i < 0){
	  printf("Error: %s - %s\n",message, strerror(errno));
  	exit(0);
  }
}
