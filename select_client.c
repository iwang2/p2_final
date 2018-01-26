#include "networking.h"
#include "print_num.h"

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];

  fd_set read_fds;

  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  while (read(server_socket, buffer, sizeof(buffer))) {
    if(strstr(buffer, "Client")){
      printf("This is %s\n", buffer);
    }
    else if (strcmp(buffer, "die") == 0) {
     printf("I HAVE BEEN KILLED\n");
   }
    else {
      printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      print_num(atoi(buffer));
      //printf("%s\n", buffer);
    }
  }//end loop
}
