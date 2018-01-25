#include "networking.h"
#include "list.h"
#include "algo.h"

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
  
  int max = atoi(buffer);
  struct node * head = (struct node *)malloc(sizeof(struct node));

  listen_socket = server_setup();
  
  //while (strcmp(buffer, "start\n") != 0) {
  while (max > subserver_count) {
    
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
	if(subserver_count == 0) head->i = client_socket;
	else head = insert_front(head, client_socket);
        
	subserver_count++;
	printf("[server] subserver count: %d\n", subserver_count);
	//close(client_socket);
      }
    }//end listen_socket select
    
    fgets(buffer, sizeof(buffer), stdin);
  }
  srand(time(NULL));
  
  struct node * n = head;
  int * probs = assign(subserver_count);
  int count = probs[0];
  char num[sizeof("99")];
  
  while(n){
    sprintf(num, "%d", probs[count]);
    write(n->i, num, sizeof(num));
    n = n->next;
    count--;
  }
  printf("finished sending probability\n");
  free_list(head);
}

void subserver(int client_socket) {
  char buffer[BUFFER_SIZE];

  //for testing client select statement
  strncpy(buffer, "hello client", sizeof(buffer));
  write(client_socket, buffer, sizeof(buffer));

  close(client_socket);
  exit(0);
}
