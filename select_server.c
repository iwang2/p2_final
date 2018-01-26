#include "networking.h"
#include "algo.h"

int subserver_count = 0;
void subserver(int from_client);

int main() {
  srand(time(NULL));

  int listen_socket;
  int client_socket;
  int f;
  char buffer[BUFFER_SIZE];

  //set of file descriptors to read from
  fd_set read_fds;

  printf("Enter the number of players: ");
  fgets(buffer, sizeof(buffer), stdin);
  
  int max = atoi(buffer);
  int clients[max];
  //struct node * head = (struct node *)malloc(sizeof(struct node));

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
      if (f == 0) subserver(client_socket);
      
      else {
	      clients[subserver_count] = client_socket;
	      subserver_count++;
	      printf("[server] subserver count: %d\n", subserver_count);
	      //close(client_socket);
      }
    }//end listen_socket select
  }
  int client_numbers[max]; // Array of the client names
  int j;
  for (j = 0; j < max; j ++) {
    client_numbers[j] = j;
  }
  
  int dead_clients = 0;
  printf("Setup complete. Press ENTER to start the first round.");
  fgets(buffer, sizeof(buffer), stdin); // Buffer for pressing ENTER
  while (dead_clients < max - 1) { // Ends with 1 client alive
    int alive_clients = max - dead_clients;
    // Algorithm from algo.c
    int *probs = assign(alive_clients);
    int kill_me = pick(probs); // gives the index in clients[] to close
    printf("probs: ");
    print_arr(probs, alive_clients + 1);
    
    // PLAYING MUSIC ~~~~~~~~~~~~~  
    printf("Pick which song you would like to play by entering it's corresponding number:\n");
    printf("[0] Little Saint Nick, The Beach Boys\n");
    printf("[1] Last Christmas, Wham!\n");
    fgets(buffer, sizeof(buffer), stdin);
    int song = atoi(buffer);
  
    pid_t f;
    char k[20] = "kill -s 9 ";

    char * s;
  
    if(song) s = "Last_Christmas.mp3";
    else s = "Little_Saint_Nick.mp3";
 
    f = fork();          
    if (f < 0) {  // just in case fork fails 
      puts("fork failure");
      exit(-1);
    }   
    else if (f == 0) { // child process 
      execlp("mpg123", "mpg123", "-q", s, (char *)NULL);
    }
    else {
      printf("Press ENTER to stop the music.\n");
      
      for (int i = 0; i < alive_clients; i ++) {
	// Write each client its probability of death
	sprintf(buffer, "%d", probs[i + 1]);
	printf("%s ", buffer);
	write(clients[i], buffer, sizeof(buffer));
      }
      
      sprintf(k, "%s%d", k, f);
      fgets(buffer, sizeof(buffer), stdin); // wait for user input
      system(k);
    }
    printf("Music stopped.\n");
    
    //printf("kill_me = %d\n", kill_me);
    write(clients[kill_me], "die", sizeof("die"));
    close(clients[kill_me]); // Kill the client
    dead_clients ++;
    printf("Killed Client %d\n", client_numbers[kill_me]);
    // Move the dead clients to the rightmost of the array
    clients[kill_me] = -1;
    client_numbers[kill_me] = -1;
    shift(clients, max);
    shift(client_numbers, max);
    // Moving on to the next round
    printf("Press ENTER to go to next round...");
    fgets(buffer, sizeof(buffer), stdin);
  }
  printf("Game complete! Client %d is the last one standing!\n", client_numbers[0]);
}

void subserver(int client_socket) {
  char buffer[BUFFER_SIZE];

  //for testing client select statement
  sprintf(buffer, "Client %d", subserver_count);
  write(client_socket, buffer, sizeof(buffer));

  close(client_socket);
  exit(0);
}

//Currently, we have an array of the client sockets and an algorithm that assigns probabilities to and picks a random number.
// What I need to do is make it so that it picks a different socket each round.
