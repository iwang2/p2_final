#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

void print_red(){
  printf("\033[22;31mYOU HAVE DIED ): ): ):\033[0m\n");
}

int main(){
  print_red();
  return 1;
}






