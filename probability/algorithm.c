#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct client {
	int prob; // out of 1000
	int status; // 0 is dead, 1 is alive
};

int main() {
	srand(time(NULL));
	int sum = 0;
	int i;
	struct client list[10];

	for (i = 0; i < 10; i ++) {
		list[i].prob = rand() % 1000;
		list[i].status = 1;
		printf("list[%d]: prob = %d, status = %d\n", i, list[i].prob, list[i].status);
		sum += list[i].prob;
	}
	printf("sum: %d\n", sum);

	printf("--------------------\n");

	printf("Rolling for death\n");
	for (i = 0; i < 10; i ++) {
		int roll = rand() % 1000;
		printf("Rolled %d, list[%d] prob = %d\n", roll, i, list[i].prob);
		if (roll <= list[i].prob) {
			printf("list[%d] died!\n", i);
			list[i].status = 0;
		}
		else printf("list[%d] lived!\n", i);
	}

	printf("--------------------\n");

	printf("Listing living computers\n");	
	for (i = 0; i < 10; i ++) {
		if (list[i].status) {
			printf("list[%d]: prob = %d\n", i, list[i].prob);
		}
	}
	return 0;
}
