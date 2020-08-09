#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
typedef int Datatype;
typedef struct node
{
	Datatype data;
	struct node * next;
} Node, *Node_p;

typedef struct
{
	Node_p top;
	int size;
} Lstack, *Lstack_p;


Node_p newNode(Datatype data)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
		return new;
	}
	perror("new");
	return NULL;

}
Lstack_p Lstack_init()
{
	Lstack_p theLstack = (Lstack_p)malloc(sizeof(Lstack));
	if (theLstack != NULL)
	{
		theLstack->top = NULL;
		theLstack->size = 0;
		return theLstack;
	}
	perror("theLstack");
	return NULL;
}

bool is_empty(Lstack_p theLstack)
{
	return theLstack->size == 0;
}

bool push(Lstack_p theLstack, Node_p new)
{
	if (is_empty(theLstack))
	{
		theLstack->top = new;
	}
	else
	{
		new->next = theLstack->top;
		theLstack->top = new;
	}
	theLstack->size++;
	return true;
}

bool pop(Lstack_p theLstack, Node_p * node)
{
	if (is_empty(theLstack))
	{
		return 0;
	}
	else
	{
		*node = theLstack->top;
		theLstack->top = theLstack->top->next;
		theLstack->size--;
		return true;
	}
}

int main()
{
	Lstack_p theLstack = Lstack_init();
	int n = 123;
	Node_p node = NULL;
	while (1)
	{
		push(theLstack, newNode(n % 16));
		if (n == 0)
		{
			break;
		}
		n = n / 16;
	}
	while (!(is_empty(theLstack)))
	{
		pop(theLstack, &node);
		printf("%0X", node->data);
	}
	return 0;
}

