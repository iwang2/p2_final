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
