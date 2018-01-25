#include "networking.h"

void subserver(int from_client);

int main() {

  int listen_socket;
  int client_socket;
  int f;
  int subserver_count = 0;
  char buffer[BUFFER_SIZE];

  //set of file descriptors to read from
  fd_set read_fds;

  printf("Enter the number of players: ");
  fgets(buffer, sizeof(buffer), stdin);
  int playnum = atoi(buffer);
  int sfd[playnum];

  listen_socket = server_setup();
  
  while (strcmp(buffer, "start\n") != 0) {
    
    //select() modifies read_fds
    //we must reset it at each iteration
    FD_ZERO(&read_fds); //0 out fd set
    FD_SET(listen_socket, &read_fds); //add socket to fd set

    //select will block until either fd is ready
    select(listen_socket + 1, &read_fds, NULL, NULL, NULL);

    //if listen_socket triggered select
    if (FD_ISSET(listen_socket, &read_fds)) {
      client_socket = server_connect(listen_socket);

      f = fork();
      if (f == 0)
	subserver(client_socket);
      else {
	sfd[subserver_count] = client_socket;
	subserver_count++;
	printf("[server] subserver count: %d\n", subserver_count);
	//close(client_socket);
      }
    }//end listen_socket select
    
    fgets(buffer, sizeof(buffer), stdin);
  }
  printf("game starting...\n");
}

void subserver(int client_socket) {
  char buffer[BUFFER_SIZE];

  //for testing client select statement
  strncpy(buffer, "hello client", sizeof(buffer));
  write(client_socket, buffer, sizeof(buffer));

  fgets(buffer, sizeof(buffer), stdin);
  /*
  while (1) {
    printf("enter data: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    write(client_socket, buffer, sizeof(buffer));
    read(client_socket, buffer, sizeof(buffer));
  }
  */
  close(client_socket);
  exit(0);
}
