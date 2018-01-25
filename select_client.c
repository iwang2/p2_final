#include "networking.h"
#include "/art/print_num.c"

void process (char * s);

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];

  fd_set read_fds;

  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  while (read(server_socket, buffer, sizeof(buffer))) {
    if(strcmp(buffer, "hello client") == 0){
      printf("received: [%s]\n", buffer);
    }
    else {
      printnum(atoi(buffer));
    }
  }//end loop
}
