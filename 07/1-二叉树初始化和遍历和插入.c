/*二叉搜索树 BST
特点：左儿子小，根节点中，右儿子大。不能大小一样
结构：数据域，指针域。指针域指向左右节点。
操作集：先序遍历、中序遍历、后序遍历、按层遍历、查找，插入，删除

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//定义结构
typedef struct node
{
	//数据域
	int data;
	//指针
	struct node * lptr;
	struct node * rptr;
}Node, *Node_p;

//初始化一个空树
Node_p init_tree()
{
	return NULL;
}

//创建一个新节点
Node_p new_node(int data)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if(new!=NULL)
	{
		new->data = data;
		new->lptr = NULL;
		new->rptr = NULL;
		return new;
	}
	perror("new");
	return NULL;
}

//插入节点-按BST的规则
Node_p insert_node(Node_p root,Node_p new)
{
	if(new == NULL)
	{
		return root;
	}
	else if(root == NULL)
	{
		return new;
	}
	else
	{
		if(new->data > root->data)
		{
			//去root 的右后方，当右后方没人就插入
			root->rptr = insert_node(root->rptr,new);
		}
		else if(new->data < root->data)
		{
			//左后方
			root->lptr = insert_node(root->lptr,new);
		}
		else
		{
			printf("重复插入\n");
		}
		return root;
	}
}

//查找节点
Node_p find_node(Node_p root,int data)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(root->data == data )
	{
		return root;
	}
	else
	{
		return find_node(root->lptr,data);
		return find_node(root->rptr,data);
	}
}

//先序遍历
void pre_traver(Node_p root)
{
	if(root != NULL)
	{
		printf("%d ",root->data );
		pre_traver(root->lptr);
		pre_traver(root->rptr);
		return;
	}
	else if(root == NULL)
		return ;
}

//中序遍历
void mid_traver(Node_p root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		mid_traver(root->lptr);
		printf("%d ",root->data );
		mid_traver(root->rptr);
		return;
	}
}

//后序遍历
void post_traver(Node_p root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		post_traver(root->lptr);
		post_traver(root->rptr);
		printf("%d ",root->data );
		return;
	}
}

typedef struct link
{
	Node_p node;
	struct link * next;
}Que,*Que_p;

typedef struct
{
	Que_p front;
	Que_p rear;
}Master,*Master_p;

Que_p init_que()
{
	Que_p head = (Que_p)malloc(sizeof(Que));
	if(head!= NULL)
	{
		head->node=NULL;
		head->next = NULL;
		return head;
	}
	perror("head");
	return NULL;
}

Master_p init_mas(Que_p head)
{
	Master_p myMas = malloc(sizeof(Master));
	if(myMas!=NULL)
	{
		myMas->front = head;
		myMas->rear = head;
		return myMas;
	}
	return NULL;
}

bool is_empty(Master_p myMas)
{
	return myMas->front == myMas->rear;
}

bool in_que(Master_p myMas,Node_p node)
{
	Que_p new = malloc(sizeof(Que));
	if(new!=NULL)
	{
		new->node = node;
		myMas->rear->next = new;
		myMas->rear = new;
	}
	
	printf("%d ",new->node->data );
	return 1;
}

bool push_ch(Master_p myMas,Node_p father)
{
	if(father->lptr!=NULL)
	{
		in_que(myMas,father->lptr);
	}
	if(father->rptr != NULL)
	{
		in_que(myMas,father->rptr);
	}
	return 1;
}
//按层遍历
void floor_traver(Node_p root,Master_p myMas)
{
	if(root==NULL)
	{
		printf("无任何数据\n");
		return;
	}
	else
	{
		in_que(myMas,root);
		Que_p tmp = myMas->front;
		while(tmp != myMas->rear)
		{
			tmp= tmp->next;
			push_ch(myMas,tmp->node);
		}
	}
}

int main(int argc, char const *argv[])
{
	//初始化树
	Node_p root = init_tree();
	for(int i=0; i<7; i++)
	{
		int a = 0;
		printf("input you:" );
		scanf("%d",&a);
		root = insert_node(root, new_node(a));
	}

	//初始化队列
	Que_p head = init_que();
	//初始化队列管理器
	Master_p myMas = init_mas(head);
	
	//按层遍历
	floor_traver(root,myMas);
	
	//遍历
	// pre_traver(root);
	// printf("\n");
	// mid_traver(root);
	// printf("\n");
	// post_traver(root);
	// printf("\n");
	//查找
	// Node_p the = find_node(root,2);
	// printf("%d\n",the->data );
	


	return 0;
}