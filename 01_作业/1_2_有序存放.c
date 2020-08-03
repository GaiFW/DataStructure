#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node* next;
}Node,*Node_p;

Node_p headNode();
Node_p newNode(int data);
bool delete(Node_p head,Node_p node);
void headInsert(Node_p head, Node_p node, Node_p new);
bool delete(Node_p head,Node_p node);
Node_p find(Node_p head, int data);
void display(Node_p head);


Node_p headNode()
{
	Node_p head = (Node_p)malloc(sizeof(Node));
	if(head!=NULL)
	{
		head->next = NULL;
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
		new->data = data;
		new->next = NULL;
		return new;
	}
	perror("new");
	return NULL;
}
void insert(Node_p head,Node_p new)
{
	Node_p tmp_p = head;
	if(tmp_p->next == NULL)
	{
		tmp_p->next = new;
	}
	else
	{
		while(tmp_p->next != NULL)
		{
			if(new->data < tmp_p->next->data)
			{
				new->next = tmp_p->next;
				tmp_p->next = new;
				return;
			}
			tmp_p = tmp_p->next;
		}
		tmp_p->next = new;

	}
	
}

bool delete(Node_p head,Node_p node)
{
	if(head != NULL && node != NULL)
	{
		Node_p tmp_p = head;

		while(tmp_p->next != node)
		{
			tmp_p = tmp_p->next;
		}
		tmp_p->next = node->next;
		free(node);
		node = NULL;
		return true;
	}
	return false;
}

Node_p find(Node_p head, int data)
{
		Node_p tmp_p = head->next;
		while( tmp_p != NULL)
		{
			if(tmp_p->data == data)
			{	
			return tmp_p;
			}
			tmp_p = tmp_p->next;
		}
		return NULL;
}
void display(Node_p head)
{
	Node_p tmp_p = head;
	while(tmp_p->next != NULL)
	{
		tmp_p = tmp_p->next;
		printf("%d ",tmp_p->data);
	}
	printf("\n");
}
void freeNode(bool del (Node_p head,Node_p node), Node_p head)
{
	Node_p tmp_p = head->next;
	while(delete(head,tmp_p))
	{
		tmp_p = head->next;
	}
	free(head);
}

int main()
{
	Node_p myhead = headNode();
	int n=1;
	while(n!=0)
	{
		printf("input your number:");
		scanf("%d",&n);
		if(n>0)
		{
			if(!find(myhead,n))
			{
				//按序插入
				insert(myhead,newNode(n));
			}
		}
		else if(n<0)
		{
			if(find(myhead,-n))
			{
				delete(myhead,find(myhead,-n));
			}
			else
			{
				printf("没有这个值的绝对值\n");
			}
		}
		
	}
	display(myhead);
	freeNode(delete,myhead);
	myhead = NULL;

	return 0;
}
