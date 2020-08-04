#include "4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int info[2];
	struct node *next;
} Node, *Node_p;



Node_p newNode(int info0);
Node_p insert(Node_p *head, Node_p new);
void delNode(Node_p * head, Node_p node);
void game(Node_p *head);

Node_p headNode()
{
	return NULL;
}

Node_p newNode(int info0)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if (new != NULL)
	{
		new->info[0] = info0;
		new->info[1] = 0;
		new->next = NULL;
		return new;
	}
	perror("new");
	return NULL;
}

Node_p insert(Node_p *head, Node_p new)
{
	if (*head == NULL)
	{
		*head = new;
		(*head)->next = *head;
		printf("%d插入成功\n", new->info[0]);
		// printf("指向%p\n",new->next );
		return *head;
	}
	else
	{
		Node_p tmp = *head;
		while (tmp->next != *head)
		{
			tmp = tmp->next;
		}
		new->next = *head;
		tmp->next = new;
		printf("%d插入成功\n", new->info[0]);
		// printf("指向%p\n",new->next );
		return *head;
	}
}
void delNode(Node_p * head, Node_p node)
{
	Node_p tmp = *head;
	if (node == tmp)
	{
		while (tmp->next != node)
		{
			tmp = tmp->next;
		}
		tmp->next = node->next;
		*head = node->next;
		printf("2删除了%d\n",node->info[0]);
		free(node);
		return ;
	}
	while (tmp->next != node)
	{
		tmp = tmp->next;
	}
	tmp->next = node->next;
	printf("1删除了%d\n",node->info[0]);
	free(node);
	return;
}
void game(Node_p *head)
{
	Node_p tmp = *head;
	int i = 0;
	while (tmp->next->next != tmp)
	{
		i++;
		tmp->info[1] = i;
		if (i == 2)
		{
			delNode(head, tmp->next);
			i = 0;
		}
		tmp = tmp->next;
	}
	printf("游戏结束，%d he %d 活了下来", tmp->info[0], tmp->next->info[0]);
}

/*bool delNode(Node_p *head,Node_p node)
{

}*/

int main(int argc, char const *argv[])
{
	Node_p head = headNode();
	for (int i = 0; i < 10; i++)
	{
		insert(&head, newNode(i + 1));
	}
	game(&head);
	return 0;
}