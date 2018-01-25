#include "list.h"

// returns new head node
struct node * insert_front(struct node * n, int num){
  struct node * new = (struct node *)malloc(sizeof(struct node));
  new->i = num;
  new->next = n;
  n->last = new;
  return new;
}

struct node * free_list(struct node * n){
  struct node * temp;
  while(n){
    temp = n->next;
    free(n);
    n = temp;
  }
  return temp;
}

// returns head node
struct node * remove_node(struct node * head, struct node * n){
  struct node * before;
  struct node * after;
  if(head == n){ // if the first in list
    after = n->next;
    after->last = NULL;
    head = after;
  }
  else if(!n->next){ // if last in list
    before = n->last;
    before->next = NULL;
  }
  else { // if there is a node in front of and behind
    before = n->last;
    after = n->next;
    before->next = after;
    after->last = before;
  }
  free(n);
  return head;
}

int list_length(struct node * n){
  int length = 0;
  while(n){
    length++;
    n = n->next;
  }
  return length;
}

void print_list(struct node * n){
  printf("[ ");
  while(n){
    printf("%d ", n->i);
    n = n->next;
  }
  printf("]\n");
}
