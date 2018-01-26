#include "play_song.h"

void play(int song){
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
    sprintf(k, "%s%d", k, f);
    getchar();  // wait for user input
    system(k);
  }
  printf("Music stopped.\n");
  //exit(0);
}





















