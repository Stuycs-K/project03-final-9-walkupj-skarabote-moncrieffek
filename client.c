void clientLogic(int server_socket){
//   Listens for a string (use the buffer size),
// Reply with the rot13 of the string.
char userinput[256];
printf("enter in a string: \n");
scanf("%s", &userinput);
int len, bytes_sent;
char buff[256+1];
len = strlen(userinput);
bytes_sent = send(server_socket, userinput, len, 0);
recv(server_socket, buff, 256, 0);
printf("RECIEVED: %s\n", buff);
}

int main(int argc, char *argv[] ) {
  char* IP = "127.0.0.1";
  if(argc>1){
    IP=argv[1];
  }
  while(1){
  int server_socket = client_tcp_handshake(IP);
  printf("client connected.\n");
  
  clientLogic(server_socket);
  }
}