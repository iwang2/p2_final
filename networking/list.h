#include <stdio.h>
#include <stdlib.h>

struct node {
  int i;
  struct node * next;
  struct node * last;
};

void print_list(struct node * n);

struct node * insert_front(struct node * n, int num);
struct node * free_list(struct node * n);
struct node * remove_node(struct node * head, struct node * n);

int list_length(struct node * n);
