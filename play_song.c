#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char * argv[]){
  int k = atoi(argv[1]);
  char * args[3];
  args[0] = "mpg123";
  args[1] = "song1.mp3";
  args[2] = NULL;


  int pip1[2];
  pipe(pip1);

  int f = fork();


  if(f == 0){ //child
    close(pip1[0]);

    int k = (int)getpid();
    
    write(pip1[1], &k, sizeof(k));

    execvp(args[0], args);
  }
  
  if(f){ //parent
    close(pip1[1]);

    int j;
    read(pip1[0], &j, sizeof(j));

    //printf("Child pid: %d\n", j);

    wait(k);
    kill(j, 9);

    //printf("got past kill\n");
  }
  /*
  
  char * kill[2];
  kill[0] = "q";
  kill[1] = NULL;
  
  if(!fork()){
    printf("q\n");
  }
  */
  return 17;

    
}






















