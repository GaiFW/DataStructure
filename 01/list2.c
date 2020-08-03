#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node,*Node_p;

Node_p headNode()
{
	Node_p head = (Node_p)malloc(sizeof(Node));
	if(head!=NULL)
	{
		head->next = NULL;
		return head;
	}
	perror("head");
}

Node_p newNode(int data)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if(new!=NULL)
	{
		new->data = data;
		new->next = NULL;
		return new;
	}
	perror("new");
}

void headInsert(Node_p head,Node_p new)
{
	new->next = head->next;
	head->next = new;
}

void insert(Node_p head,Node_p new,int i)
{
	int n=0;
	Node_p tmp_p = head;
	Node_p fr_tmp = tmp_p;
	while(tmp_p->next != NULL)
	{
		tmp_p = tmp_p->next;
		++n;
		if(n==i)
		{
			new->next = fr_tmp->next;
			fr_tmp->next = new;
			return;
		}
		fr_tmp = tmp_p;
	}
}
Node_p find(Node_p head,int data,int new_data)
{
	Node_p fr_tmp = head;
	while(fr_tmp->next != NULL)
	{
		if(fr_tmp->next->data == data)
		{
			//找到
			Node_p ret_p = fr_tmp->next;
			//找到更新
			fr_tmp->next->data = new_data;
			//找到删除
/*			Node_p delete_p = fr_tmp->next;
			fr_tmp->next = delete_p->next;
			free(delete_p);
			return NULL;
*/
		}
		fr_tmp = fr_tmp->next;
	}
	return ret_p;
}
void display(Node_p head)
{
	if(head->next==NULL)
	{
		printf("head为NULL\n");
		return;
	}
	Node_p tmp_p = head;
	while(tmp_p->next!=NULL)
	{
		tmp_p = tmp_p->next;
		printf("%d ",tmp_p->data);
	}
	printf("\n");
}

void freeNode(Node_p head)
{
	Node_p tmp = head;
	Node_p fr_tmp = tmp;
	while(tmp->next != NULL)
	{
		tmp=tmp->next;
		free(fr_tmp);
		fr_tmp = tmp;
	}
}

int main()
{
	Node_p myhead = headNode();
	int num=1;
	while(num>0)
	{
		printf("input your number:");
		scanf("%d",&num);
		if(num>0)
		{
			headInsert(myhead,newNode(num));
		}
	}
	display(myhead);
	
	printf("insert which:");
	scanf("%d",&num);
	insert(myhead,newNode(num),num);
	display(myhead);

	freeNode(myhead);
	myhead = NULL;
	return 0;
}
