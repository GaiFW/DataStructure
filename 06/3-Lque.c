#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int num;
	int sal;
	char name[32];
	struct node *next;
}Node, *Node_p;

typedef struct 
{
	Node_p front;
	Node_p rear;
}que,*que_p;

que_p init_q()
{
	que_p Mq = (que_p)malloc(sizeof(que));
	if(Mq!=NULL)
	{
		Node_p head = (Node_p)malloc(sizeof(Node));
		if(head!=NULL)
		{
			head->next = head;
			Mq->front = head;
			Mq->rear = head;
			return Mq;
		}
		perror("head");
		return NULL;
	}
	perror("Mq");
	return NULL;
}

Node_p newNode()
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if(new!=NULL)
	{
		printf("input your infomation:");
		scanf("%d %s %d",&(new->num),new->name,&(new->sal));
		new->next = NULL;
		return new;
	}
	perror("new");
	return 0;
}

bool is_empty(que_p Mq)
{
	return Mq->rear == Mq->front;
}



bool in_q(que_p Mq,Node_p new)
{
	new->next = Mq->rear->next;
	Mq->rear->next = new;
	Mq->rear = new;
	return 1;
}

bool out_q(que_p Mq,Node_p* new)
{
	if(is_empty(Mq))
	{
		return 0;
	}
	*new = Mq->front->next;
	Mq->front->next = (*new)->next;
	return 1;
}

void display(que_p Mq)
{
	Node_p tmp = Mq->front;
	while(tmp != Mq->rear)
	{
		tmp = tmp->next;
		printf("num:%d name:%s sal:%d\n",tmp->num,tmp->name,tmp->sal);
	}
}

int main()
{
	que_p Mq = init_q();

	int op=1;
	while(op)
	{
		printf("input your:");
		scanf("%d",&op);
		if(op>0)
		{
			in_q(Mq,newNode());
		}
		else if(op<0)
		{
			Node tmp;
			Node_p tmp_p = &tmp;
			out_q(Mq,&tmp_p);
			printf("num:%d name:%s sal:%d\n",tmp_p->num,tmp_p->name,tmp_p->sal);
		}
		else
			display(Mq);
	}
	return 0;
}
