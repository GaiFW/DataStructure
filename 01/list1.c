#include<stdio.h>
#include<stdlib.h>


//声明节点结构体类型
typedef struct node
{
	int data;
	struct node *next;
}Node,*Node_p;
//创建头结点
Node_p head_node()
{
	Node_p head = (Node_p)malloc(sizeof(Node));
	if(head != NULL)
	{
		head->next = NULL;
		return head;
	}
	perror("head");
}
//创建节点
Node_p cre_node(int data)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if(new != NULL)
	{
		new->next = NULL;
		new->data = data;
		return new;
	}
	perror("new");
}

//插入节点到链表的尾部
void insert_node(Node_p head,Node_p new)
{
	Node_p tmp_p = head;
	if(head != NULL && new != NULL)
	{
		//判断tmp_p是否是要找的尾部节点
		while(tmp_p->next != NULL)
		{
			tmp_p = tmp_p->next;
		}
		//插入
		tmp_p->next = new;
		return ;
	}
	perror("head or new");
}
//遍历链表
void display(Node_p head)
{
	Node_p tmp_p = head;
	if(tmp_p != NULL)
	{
		while(tmp_p->next != NULL)
		{
			tmp_p = tmp_p->next;
			printf("%d ",tmp_p->data);
		}
		printf("\n");
		return;
	}
	perror("head");
}

//集体释放
void freeNode(Node_p head)
{

	Node_p tmp_p = head;
	Node_p fr_tmp = tmp_p;

	while(tmp_p->next != NULL)
	{
		tmp_p = tmp_p->next;
		free(fr_tmp);
		fr_tmp = tmp_p;
	}


}

int main()
{
	//创建新链表
	Node_p myhead = head_node();

	//创建5个普通节点保存数
	for(int i=0;i<5;i++)
	{
		int num = 0;
		scanf("%d",&num);

		//创建节点
		Node_p new = cre_node(num);

		//插入元素
		insert_node(myhead,new);
	}

	display(myhead);
	
	freeNode(myhead);
//	new = NULL;
	myhead =NULL;
	return 0;
}

