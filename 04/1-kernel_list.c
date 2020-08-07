#include "kernel_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct list_head Knode;
typedef struct list_head * Knode_p;
typedef struct
{
	int data;
	Knode list;
} Node, *Node_p;

Node_p head_node()
{
	Node_p head = (Node_p)malloc(sizeof(Node));
	if (head != NULL)
	{
		INIT_LIST_HEAD(&(head->list));
		return head;
	}
	perror("head");
	return NULL;
}

Node_p new_node(int data)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if (new != NULL)
	{
		new->data = data;
		INIT_LIST_HEAD(&(new->list));
		return new;
	}
	perror("new");
	return NULL;
}
Knode_p find_node(Knode_p head, int op)
{
	Node_p pos = NULL;
	Node_p n = NULL;
	list_for_each_entry_safe(pos, n, head, list)
	{
		if (pos->data == op)
		{
			return &(pos->list);
		}
	}
	printf("没有找到\n");
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
	Node_p head = head_node();

	int op = 1;
	while (op)
	{
		printf("input your:");
		scanf("%d", &op);
		if (op > 0)
		{
			Node_p new = new_node(op);
			list_add_tail(&(new->list), &(head->list));
		}
		else if (op < 0)
		{
			list_del_init(find_node(&(head->list),-op));
		}
		else
			break;
	}
	display(head);
	return 0;
}