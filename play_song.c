#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
  pid_t f;
  char k[20] = "kill -s 9 ";
 
  f = fork();          
  if (f < 0) {  // just in case fork fails 
    puts("fork failure");
    exit(-1);
  }   
  else if (f == 0) { // child process 
    execlp("mpg123", "mpg123", "-q", "song1.mp3", (char *)NULL); 
  }
  else {
    printf("Press ENTER to quit.\n");
    sprintf(k, "%s%d", k, f);
    getchar();  // wait for user input
    system(k);
  }
  printf("All done.\n");
  exit(0);
}






















