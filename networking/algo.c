#include "networking.h"
#include "algo.h"

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
  
  printf("\n");
  int ret = weighted[rand() % 100];
  free(weighted);
  return ret;
}
