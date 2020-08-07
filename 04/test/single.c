/*头结点不带数据的单链表*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Datatype;

//1.声明节点结构体类型
typedef struct node
{
	Datatype data;//数据域
	struct node *next;//指针域
}Node, *Link;
// typedef struct node Node;
// typedef struct node *Link;

Link init_list(void);//初始化链表
Link creat_node(Datatype data);//新建结点
void insert_tail(Link head, Link node);//尾插法
void insert_head(Link head, Link node);//头插法
bool is_empty(Link head);//判断空链表
void display(Link head);//遍历链表
Link find_node(Link head, Datatype data);//查找结点
void delete_node(Link head, Datatype data);//删除结点
void update_node(Link head, Datatype data, Datatype new_data);//修改（更新）结点
void clean_list(Link head);//清空链表
Link remove_node(Link head, Datatype data);//取出结点（不释放）
void move_node(Link head, Link node1, Link node2);//移动结点

int main(int argc, char const *argv[])
{
	int n;
	Link mylist = init_list();
	while(1)
	{
		scanf("%d", &n);
		//大于0的时候用尾插法插入节点
		if (n > 0)
		{
			insert_tail(mylist, creat_node(n));
		}
		//小于0的时候删除n的绝对值对应的元素
		else if (n < 0)
		{
			//找到这个元素
			// Link find = find_node(mylist, -n);
			// if (find != NULL)
			// {
			// 	printf("找到了\n");
			// }
			// else
			// {
			// 	printf("没找到\n");
			// }
		
			//删除这个元素
			delete_node(mylist, -n);
		
			//更新结点，修改结点
			// update_node(mylist, -n, -n*100);
		}
		//等于0的时候结束输入
		else
		{
			break;
		}
	}
	display(mylist);
	
	int i, j;
	//将m结点移动到n结点后面
	scanf("%d%d", &i, &j);
	move_node(mylist, find_node(mylist, i), find_node(mylist, j));

	// clean_list(mylist);
	// printf("清空过后：\n");
	display(mylist);

	return 0;
}

//2.初始化新链表
Link init_list(void)
{
	//申请头结点空间
	Link head = malloc(sizeof(Node));
	//判断申请成功
	if (head != NULL)
	{
		//初始化
		// data 不管
		head->next = NULL;
	}
	return head;
}

//3.创建节点
Link creat_node(Datatype data)
{
	//申请新节点空间
	Link new = malloc(sizeof(Node));
	//判断申请成功
	if (new != NULL)
	{
		//初始化
		new->data = data;
		new->next = NULL;
	}
	return new;
}

//4.尾插法：插入节点到链表的尾部
void insert_tail(Link head, Link node)
{
	//(1)找到链表的尾部节点
	Link p = head;
	if (p == NULL)
	{
		return;
	}
	while(p->next != NULL)
	{
		p = p->next;
	}

	//(2)将尾部节点的next指针设置为待插入节点的地址
	p->next = node;
}

//5.遍历链表
void display(Link head)
{
	//如果说传进来的是空指针或者传进来的是空链表
	if (head == NULL || is_empty(head))
	{
		return;
	}

	Link p = head;
	while(p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//6.头插法：将新节点插入到链表头部
//13.将node结点插入到任意结点head的后面
void insert_head(Link head, Link node)
{
	if (head == NULL || node == NULL)
	{
		return;
	}
	node->next = head->next;
	head->next = node;
}

//7.判断空链表
bool is_empty(Link head)
{
	// if (head->next == NULL)
	// {
	// 	return true;
	// }
	// else
	// {
	// 	return false;
	// }
	return (head->next == NULL);
}

//8.找到值为data的结点，并返回该结点的地址
Link find_node(Link head, Datatype data)
{
	Link p = head;
	while(p->next != NULL)
	{
		p = p->next;
		//找到
		if (p->data == data)
		{
			return p;
		}
	}
	//没有找到
	return NULL;
}

//9.删除值为data的结点
void delete_node(Link head, Datatype data)
{
	if (head == NULL || is_empty(head))
	{
		return;
	}

	//用prev表示待删除结点的前面结点
	Link prev = head;
	while(prev->next != NULL)
	{
		//找到待删节点是prev->next
		if(prev->next->data == data)
		{
			//定义一个delete指针变量表示要删除的结点
			Link delete = prev->next;
			prev->next = delete->next;
			free(delete);
			// break;//只删除第一次找到的这个值的结点
			continue;//删除所有这个值的结点
		}
		prev = prev->next;
	}
}

//10.将head链表中值为data的结点数据改为new_data
void update_node(Link head, Datatype data, Datatype new_data)
{
	//找到要更新的结点
	Link node = find_node(head, data);
	//找到结点
	if (node != NULL)
	{
		printf("找到结点，更新...\n");
		node->data = new_data;
	}
	else
	{
		printf("对不起，该元素不存在\n");
	}
}

//11.取出链表中值为data的结点
Link remove_node(Link head, Datatype data)
{
	if (head == NULL || is_empty(head))
	{
		return NULL;
	}

	//用prev表示待删除结点的前面结点
	Link prev = head;
	while(prev->next != NULL)
	{
		//找到待删节点是prev->next
		if(prev->next->data == data)
		{
			//定义一个delete指针变量表示要删除的结点
			Link delete = prev->next;
			prev->next = delete->next;
			// free(delete);
			delete->next = NULL;
			return delete;
		}
		prev = prev->next;
	}
	return NULL;
}

//12.清空链表
void clean_list(Link head)
{
	if (head == NULL || is_empty(head))
	{
		return;
	}
	while(!is_empty(head))
	{
		delete_node(head, head->next->data);
	}
}

//14.将node1移动到node2结点的后面
void move_node(Link head, Link node1, Link node2)
{
	if (node1 == NULL || node2 == NULL)
	{
		return;
	}

	//将node1取出来
	Link n = remove_node(head, node1->data);
	if (n == NULL)
	{
		return;
	}
	//将node1插入到node2后面
	insert_head(node2, node1);
}
