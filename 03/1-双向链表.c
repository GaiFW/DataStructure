#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node * next;
	struct node * prev;
}Node, *Node_p;


