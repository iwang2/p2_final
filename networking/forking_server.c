#include "networking.h"

void subserver(int from_client);

int main() {

  int send_socket;
  int f;
  send_socket = server_setup();

  while (1) {

    int client_socket = server_connect(send_socket);
    f = fork();
    if (f == 0)
      subserver(client_socket);
    else
      close(client_socket);
  }
}

void subserver(int client_socket) {
  char buffer[BUFFER_SIZE];

  while (1) {
    printf("enter data: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    write(client_socket, buffer, sizeof(buffer));
    read(client_socket, buffer, sizeof(buffer));
  }
  close(client_socket);
  exit(0);
}
