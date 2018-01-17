#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

// 16 lines per number
// file size of percent is 368

char * print_num (int n) {
  char s[sizeof("0.txt")];
  sprintf(s, "%d", n);
  strcat(s, ".txt");

  struct stat sb;
  stat(s, &sb);

  int fd1 = open(s, O_RDONLY);
  int fd2 = open("per.txt", O_RDONLY);  
}

char ** arr () {
  char s[10][sizeof("0.txt")];
  char temp[sizeof("0.txt")];
  for(int i = 0; i < 10; i++){
    sprintf(temp, "%d", i);
    strcat(temp, ".txt");

    struct stat sb;
    stat(temp, &sb);

    int fd = open(temp, O_RDONLY);
    for(int n = 0; n < 16; n++){
      strcpy(s[i][n], 
  }
}

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
}
