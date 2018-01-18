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
  int
    fd1 = -1,
    fd2 = -1;
  int fdp = open("per.txt", O_RDONLY);
  int size = 0;

  if ( n/10 > 0 ) {
    
  }
  
  for (int i = 0; n / 10 > 0; i++) {    
    char s[sizeof("per.txt")];
    if (nc == 1) {
      strcpy(s, "per.txt");
    } else {
      sprintf(s, "%d", n%10);
      strcat(s, ".txt");
    }
    struct stat sb;
    stat(s, &sb);
    
    size = (int)sb.st_size / 16;

    fd = open(s, O_RDONLY);

    n /= 10;
  }

  for (int i = 0; i < 

  close(fd1);
  close(fdp);
  if (fd2 > -1) close(fd2);
}

/*
char *** arr () {
  char *** s = malloc(10 * 16 * sizeof(char *));
  //char s[10][16][23];
  char temp[sizeof("0.txt")];
  
  for(int i = 0; i < 10; i++){
    sprintf(temp, "%d", i);
    strcat(temp, ".txt");

    struct stat sb;
    stat(temp, &sb);
    int size = (int)sb.st_size / 16;

    int fd = open(temp, O_RDONLY);
    
    for(int n = 0; n < 16; n++){
      //s[i][n] = (char *)malloc(size);
      *(s + i + n) = malloc(size);
      if (read(fd, *(s + i + n), size) == -1) {
	printf("%s\n", strerror(errno));
	exit(0);
      }
    }
    close(fd);
  }
  return s;
}
*/

int main(){
  for(int i = 0; i < 11; i++){
    struct stat sb;
    char s[sizeof("abc.txt")];
    
    if (i == 10) strcpy(s, "per");
    else sprintf(s, "%d", i);

    strcat(s, ".txt");
    stat(s, &sb);
    printf("%s: %d\n", s, (int)sb.st_size);
  }
  
  char *** s = arr();
  //strcpy(s, arr());
  for(int i = 0; i < 10; i++){
    for(int k = 0; k < 16; k++){
      //for(int j = 0; a[j]; j++){
      printf("%d, %d: %s\n", i, k, *(s + i + k));
	// }
    }
  }
}
