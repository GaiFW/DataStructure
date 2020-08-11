#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*队列 存27个数   入 出 遍历     */
typedef struct
{
	int size;
	int *arr;
	int front;
	int rear;
}Queue,*Queue_p;

Queue_p init_Que()
{
	Queue_p myQue = (Queue_p)malloc(sizeof(Queue));
	if(myQue!=NULL)
	{
		myQue->arr = (int *)malloc(sizeof(int)*28);
		if(myQue->arr!=NULL)
		{
			myQue->size = 28;
			myQue->front = 0;
			myQue->rear = 0;
			return myQue;
		}
		return NULL;
	}
	return NULL;
}

bool is_full(Queue_p myQue)
{
	return myQue->rear+1%28 == myQue->front;
}

bool is_empty(Queue_p myQue)
{
	return myQue->rear == myQue->front;
}

bool inQue(Queue_p myQue,int data)
{
	if(is_full(myQue))
	{
		return 0;
	}
	myQue->arr[++(myQue->rear)%28] = data;
	return 1;
}

int outQue(Queue_p myQue)
{
	if(is_empty(myQue))
	{
		return 0;
	}
	int a=myQue->arr[++(myQue->front)%28];
	myQue->arr[(myQue->front)%28]=0;
	return a;
}

void showQue(Queue_p myQue)
{
	int tmp = myQue->front;
	int i=1;
	while(i!=28)
	{
		printf("%d ",myQue->arr[++tmp%28] );
		if(tmp%28 == myQue->rear)
		{
			printf("\n");
			return ;
		}
		i++;
	}
}


/*栈 满5进1出栈入队列 满12进1出栈入队列  满12出栈入队列  */

typedef struct
{
	int size;
	int top;
	int * arr;
}Stack,*Stack_p;

Stack_p init_Stack(int size)
{
	Stack_p myStack = malloc(sizeof(Stack));
	if(myStack!=NULL)
	{
		myStack->arr = malloc(sizeof(int)*size);
		if(myStack->arr != NULL)
		{
			myStack->size = size;
			myStack->top = -1;
			return myStack;
		}
		return NULL;
	}
	return NULL;
}


bool is_full_s(Stack_p myStack)
{
	return myStack->top == myStack->size-1;
}

bool is_empty_s(Stack_p myStack)
{
	return myStack->top == -1;
}
bool push(Stack_p myStack,int data)
{
	if(is_full_s(myStack))
	{
		return 0;
	}
	myStack->arr[++(myStack->top)] = data;
	return 1;
}

int pop(Stack_p myStack)
{
	if(is_empty_s(myStack))
	{
		return 0;
	}
	int a = myStack->arr[(myStack->top)];
	myStack->arr[(myStack->top)] = 0;
	myStack->top--;
	return a;
}
void showSta(Stack_p myStack)
{
	if(myStack==NULL ||is_empty_s(myStack))
	{
		printf("空\n");
		return;
	}
	int p = -1;
	while(1)
	{
		printf("%d ",myStack->arr[++p] );
		if(p == myStack->top)
		{
			printf("\n");
			return;
		}

	}
}
bool cmp(int *arr1,int *arr)
{
	for(int i=0;i<27;i++)
	{
		if(arr1[i]!=arr[i])
		{
			return 0;
		}
	}
	return 1;
}
int checkQue(Queue_p myQue)
{
	int i=(myQue->front+1)%28;
	while(i!=myQue->rear)
	{
		if(myQue->arr[i]>myQue->arr[i+1])
		{
			return 0;
		}
		i=(i+1)%28;
		// printf("0000000\n");
		// return 1;
	}
	printf("0000000000000000000\n");
	return 1;
}
int main(int argc, char const *argv[])
{

	Queue_p myQue = init_Que();
	for (int i = 0; i < 27; ++i)
	{
		inQue(myQue, i+1);
	}
	printf("排前：\n");
	showQue(myQue);

	Stack_p fen = init_Stack(6);
	Stack_p wufen = init_Stack(15);
	Stack_p shi = init_Stack(30);
	// Stack_p  tian= init_Stack(30);
	int i=0;
	int j=0;
	int k=0;
	int d=0;
	int arr_p[27];
	int arr2[27];
	for(int i=0;i<27;i++)
	{
		arr_p[i]=i+1;
		arr2[i] = i+1;
	}
	while(d!=30)
	{
		if(++i%5!=0)
		{
			push(fen,outQue(myQue));
			// printf("%d:%d\n",k,j*5+i );
		}
		else if(++j%12 != 0)
		{
			if(i==5)
			{
			push(wufen,outQue(myQue));
			// showQue(myQue);
			// showSta(fen);
			// showSta(wufen);
			// showSta(shi);
			}
			i=0;
			// printf("%d:%d\n",k,j*5+i );
			while(!(is_empty_s(fen)))
			{
				inQue(myQue ,pop(fen));
			}
			// showQue(myQue);
			// printf("\n");
			// if(myQue->arr[myQue->front+1]==1 && myQue->arr[myQue->rear]==27)
			// {
			// 	break;
			// }

		}
		else if(++k%12!=0)
		{
			if(i==5&&j==12)
			{
				push(shi,outQue(myQue));
				// showQue(myQue);
				// showSta(fen);
				// showSta(wufen);
				// showSta(shi);
			}
			i=0;
			j=0;
			// printf("%d:%d\n",k,j*5+i );
				while(!(is_empty_s(wufen)))
			{
				inQue(myQue,pop(wufen));
			}
			while(!(is_empty_s(fen)))
			{
				inQue(myQue ,pop(fen));
			}
			// showQue(myQue);
			// printf("\n");


		}
		else
		{
			if(i==5 && j==12 && k==12)
			{
				++d;
			}
			i=0;j=0;k=0;
			printf("%d:%d\n",k,j*5+i );
			while(!(is_empty_s(fen)))
			{
				inQue(myQue ,pop(fen));
			}
			while(!(is_empty_s(wufen)))
			{
				inQue(myQue,pop(wufen));
			}
			while(!(is_empty_s(shi)))
			{
				inQue(myQue,pop(shi));
			}

			showQue(myQue);
			printf("\n");
			// if(cmp((myQue->arr)+((myQue->front+1)%28),arr_p))
			// if(checkQue(myQue))
			if((myQue->arr)[(myQue->front+1)%28]==1&&(myQue->arr)[(myQue->rear)%28]==27)
			{
				break;
			}
		}
	}
	// printf("时间%d:%d\n",(d*12+k)*60,j*5+i );
	printf("排后 ：\n");
	showQue(myQue);
	printf("\n");
	return 0;
}
