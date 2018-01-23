#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

// 16 lines per number
// file size of percent is 368

void print_num (int n) {
  int fd, size;
  int single = 0;
  
  int fds[3][2];
  fds[2][0] = open("per.txt", O_RDONLY);
  struct stat sb;
  stat("per.txt", &sb);
  fds[2][1] = (int)sb.st_size / 16;
  // fds[x][0] is the file descriptor
  // fds[x][1] is the line size

  char s[sizeof("0.txt")];
  for (int g = 1; g >= 0; g--){
    sprintf(s, "%d", n%10);
    strcat(s, ".txt");
    fds[g][0] = open(s, O_RDONLY);

    if(g == 0 && strcmp(s, "0.txt") == 0) {
      single = 1;
    }

    stat(s, &sb);
    fds[g][1] = (int)sb.st_size / 16;
    
    n /= 10;
  }
  
  for (int i = 0; i < 16; i++) {
    for(int j = 0; j < 3; j++) {
      fd = fds[j][0];
      size = fds[j][1];
      
      char buff[size];
      read(fd, buff, size);
      //buff[0] = ' ';
      buff[size-1] = 0;
      if((single && j != 0) || (!single)) printf("%s  ", buff);
      //memset(buff, 0, sizeof(buff));
    }
    printf("\n");
  }

  for (int k = 0; k < 3; k++) {
    close(fds[k][0]);
  }
}

int main(int argc, char *argv[]){
  if (argc > 0) {
    int num = atoi(argv[1]);
    //printf("%d\n", num);
    print_num(num);
  }
}
