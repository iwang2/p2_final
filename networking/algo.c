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

/*
int arrlast(int * arr){
  int i;
  for(i = 0; arr[i]; i++
}

int arrlen(int * arr){
  return (sizeof(arr) / sizeof(arr[0]));
}
*/

int pick(int * probs){
  int * weighted = calloc(100, sizeof(int));
  int i;
  int k = 0;
  int track = 0;
  srand(time(NULL));
  /*
  while(k < probs[0] + 1){
    memset(weighted, k, track * sizeof(int));
    track += probs[k];
    k++;
  }
  */


  
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
    printf("At position %d, the value of the weighted array is %d\n", j, weighted[j]);
  }
  */
  srand(time(NULL)); 
  int ret = weighted[rand() % 100];
  free(weighted);
  return ret;
}




int main(){
  //int j = 5;
  int * test = assign(5);
  /*
  printf("size of test: %d\n", sizeof(*test));
  printf("size of first element of test: %d\n", sizeof(test[0]));
  printf("length of test: %d\n", (sizeof(test) / sizeof(test[0])));
  */
  int i;
  for(i = 1; i < 6; i++){
    printf("At position %d, the probability as a percentage is %d\n", i, test[i]);
  }
  int k = pick(test);
  printf("value of pick: %d\n", k);
  free(test);
  return 1;
}























