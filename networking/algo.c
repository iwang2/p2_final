#include "networking.h"
#include <time.h>

int* assign(int k){
  srand(time(NULL));
  int i;
  int track = 100;
  int * probs = calloc(k, sizeof(int));
  for(i = 0; i < k - 1; i++){
    int temp = (rand() % track);
    if(track > 0){      
      probs[i] = temp;
      track -= temp;
    }
    else{
      probs[i] = 0;
    }
  }
  probs[k - 1] = track;
  //probs[k] = k;
  return probs;
}

/*
int arrlast(int * arr){
  int i;
  for(i = 0; arr[i]; i++
}
*/
int arrlen(int * arr){
  return (sizeof(arr) / sizeof(arr[0]));
}

int pick(int * probs){
  int * weighted = calloc(100, sizeof(int));
  int i;
  int k;
  srand(time(NULL));
  for(i = 0; i < arrlen(probs); i++){
    for(k = 0; k < probs[i]; k++){
      weighted[k] = i;
    }
  }
  
  //test
  int j;
  for(j = 0; j < 100; j++){
    printf("At position %d, the value of the weighted array is %d\n", j, weighted[j]);
  }



  int ret = weighted[rand() % 100];
  free(weighted);
  return ret;
}




int main(){
  int * test = assign(5);
  printf("size of test: %d\n", sizeof(test));
  printf("size of first element of test: %d\n", sizeof(test[0]));
  printf("length of test: %d\n", (sizeof(test) / sizeof(test[0])));
  int i;
  for(i = 0; i < 5; i++){
    printf("At position %d, the value is %d\n", i, test[i]);
  }
  int k = pick(test);
  printf("value of pick: %d\n", k);
  free(test);
  return 1;
}























