#include <stdio.h>
#include <stdlib.h>

struct node1
{
	char a;
};

struct node
{
	int data;
	struct node1 n1;
};

int main()
{
	
	struct node *nn1 =malloc(sizeof(struct node));
	nn1->data = 1;
	nn1->n1.a = 'a'; 

	printf("nn1:%p\ndata:%p\nn1:%p\n",nn1,&(nn1->data),&(nn1->n1));

	return 0;

}
