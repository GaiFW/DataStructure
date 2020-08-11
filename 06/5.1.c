#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct infor
{
	int id;
	char name[20];
	float salary;
}Datatype;

typedef struct node
{
	Datatype data;
	struct node* next;
}Node, *Link;

typedef struct sq
{
	Link front;
	Link rear;
	int size;
}Sq, *Sq_p;


Sq_p init()
{
	Sq_p mysq = malloc(sizeof(Sq));
	if (mysq != NULL)
	{
		mysq->front = NULL;
		mysq->rear = NULL;
		mysq->size = 0;
		return mysq;
	}
	return NULL;
}

Link creat(Datatype data)
{
	 Link new = malloc(sizeof(Node));
	if (new != NULL)
	{
		new->data = data;
		new->next = NULL;
		return new;

	}
	return NULL;
}

bool is_empty(Sq_p mysq)
{
	return mysq->size == 0;
}

bool push(Sq_p mysq, Link new)
{
	if (mysq == NULL || new == NULL)
	{
		return false;
	}
	else if (is_empty(mysq))
	{
		mysq->front = new;
		mysq->rear = new;
		printf("1111111\n");
	}
	else{
	mysq->rear->next = new;
	mysq->rear = new;
	printf("22222222222\n");
	}
	mysq->size++;
	return true;
}

Link find_node(Sq_p mysq, int id)
{
	if (mysq == NULL || is_empty(mysq))
	{
		return NULL;
	}

	Link p = mysq->front;
	while(p->next != NULL)
	{
		printf("----------------------------------\n");
		printf("%d\n",p->data.id);
		printf("%d\n",id );
		printf("---------------------------\n");
		if (p->data.id == id)
		{
			printf("------\n");
			Link m = p->next;

			p->next = m->next;
			printf("%p\n",m);
			return m;
		}
		p = p->next;
	}
	printf("%p\n",p->next);
	return NULL;
}

// bool pop1(Sq_p mysq, int id)
// {
// 	Link m = find_node(mysq, id);
// 	mysq->m = mysq->m->next;
// 	mysq->size--;
// }

bool pop(Sq_p mysq, Link *q)
{
	if (mysq == NULL || is_empty(mysq))
	{
		return false;
	}
	if (mysq->size == 1)
	{
		mysq->rear = NULL;
	}
	*q = mysq->front;
	mysq->front = mysq->front->next;
	mysq->size--;
	return true;
}

int main(int argc, char const *argv[])
 {
 	Sq_p mysq = init();
 	
 	while(1)
 	{
 		Datatype s;
 		int n = 0;
 		scanf("%d", &s.id);
 		if (s.id >0)
 		{
 			
 			scanf("%s%f", s.name, &s.salary);
 			Link new = creat(s);
 			push(mysq, new);
 		}

 		else if(s.id<0)
 		{
 			int n = -1*s.id;
 			Link q = find_node(mysq, n);
 			printf("%p\n",q );
 			printf("000000000\n");
 			printf("%d\t%s\t%f\n", q->data.id, q->data.name, q->data.salary);

 		}
 		else
 			break;
 	}
	Link q = NULL;
	while(is_empty(mysq))
	{
	if (pop(mysq, &q))
	{
		printf("%d\t%s\t%f\n", q->data.id, q->data.name, q->data.salary);
	}
	mysq->size--;		
	}

 	return 0;
 } 
