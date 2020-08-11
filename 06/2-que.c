#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
	int num;
	int sal;
	char name[32];
}Node, *Node_p;
typedef struct
{
    Node_p* arr;
    int front;
    int rear;
    int size;
}que, *que_p;

Node_p newNode()
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if(new!=NULL)
	{
		printf("your infomation:");
		scanf("%d %s %d",&(new->num),new->name,&(new->sal));
		return new;
	}
}
que_p init_que(int size)
{
    que_p Mq = (que_p)malloc(sizeof(que));
    if(Mq != NULL)
    {
        Mq->arr = (Node_p*)malloc(sizeof(Node)*size);
        if(Mq->arr == NULL)
        {
            perror("Mq->arr");
            return NULL;
        }
        Mq->size = size;
        Mq->front = 0;
        Mq->rear = 0;
        return Mq;
    }
    perror("Mq");
    return NULL;
}

bool is_empty(que_p Mq)
{
    return Mq->front == Mq->rear;
}
bool is_full(que_p Mq)
{
    return ((1+Mq->rear))%(Mq->size) == Mq->front;
}

bool in_q(que_p Mq,Node_p node)
{
    if(is_full(Mq))
    {
        return 0;
    }

    Mq->arr[(++(Mq->rear))%(Mq->size)]=node;

    return 1;
}
bool out_q(que_p Mq,Node_p* node_p)
{
    if(is_empty(Mq))
    {
        return 0;
    }
    *node_p = Mq->arr[++(Mq->front)%(Mq->size)];
    return 1;
}

void display(que_p Mq)
{
    int tmp = Mq->front;
    while(tmp != Mq->rear)
    {
        Node_p tmp1 = Mq->arr[++tmp%(Mq->size)];
        printf("num:%d name:%s sal:%d\n",tmp1->num,tmp1->name,tmp1->sal);
    }
    printf("\n");
}
int main()
{
    que_p Mq = init_que(8);
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

