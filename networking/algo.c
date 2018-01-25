#include "networking.h"
#include <time.h>

int* assign(int k){
  int i;
  int track = 100;
  int * probs = calloc(k + 1, sizeof(int));
  for(i = 1; i < k; i++){
    int temp = (rand() % track);
    if(track > 0){      
      probs[i] = temp;
      track -= temp;
    }
    else{
      probs[i] = 0;
    }
  }
  probs[k] = track;
  probs[0] = k;
  return probs;
}

int pick(int * probs){
  int * weighted = calloc(100, sizeof(int));
  int i;
  int k = 0;
  int track = 0;

  for(i = 1; i < 1 + probs[0]; i++){
    while(k < probs[i]){
      weighted[k + track] = i;
      k++;
    }
    track += probs[i];  
    k = 0;  
  }
  int j;
  /*
  for(j = 0; j < 100; j++){
    printf("[%d] = %d\n", j, weighted[j]);
  }
  */
  printf("\n");
  int ret = weighted[rand() % 100];
  free(weighted);
  return ret;
}

/*
int main(){
  srand(time(NULL));
  int j = 9;
  int * test = assign(j);
  int i;
  for(i = 1; i < j+1; i++){
    printf("[%d] = %d\n", i, test[i]);
  }
  int k = pick(test);
  printf("value of pick: %d\n", k);
  free(test);
  return 1;
}
*/
