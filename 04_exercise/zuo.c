#include "kernel_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct list_head KNode;
typedef struct list_head *KNode_p;
typedef struct
{
	int data;
	KNode list;
}Node, *Node_p;

Node_p headNode()
{
	Node_p head = (Node_p)malloc(sizeof(Node));
	if(head != NULL)
	{
		INIT_LIST_HEAD(&(head->list));
		return head;
	}
	perror("head");
	return NULL;
}

Node_p newNode(int data)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if(new != NULL)
	{
		new->data =data;
		INIT_LIST_HEAD(&(new->list));
		return new;
	}
	perror("new");
	return NULL;
}

void display(Node_p head)
{
	Node_p pos = NULL;
	Node_p n = NULL;
	list_for_each_entry_safe(pos, n, &(head->list), list)
	{
		printf("%d ",pos->data);
	}
	printf("\n");
}

int main()
{
	Node_p head = headNode();

    for(int i=0; i<10;i++)
    {
        Node_p new = newNode(i+1);
        list_add_tail( &(new->list),&(head->list));
    }


    displaj(head);
    Node_p pos = NULL;
	Node_p n = NULL;
	list_for_each_entry_safe(pos, n, &(head->list), list)
	{
		if(pos->data%2 == 1)
		{
			list_move(&(pos->list),&(head->list));
		}
	}

	display( head);

	return 0;

}
