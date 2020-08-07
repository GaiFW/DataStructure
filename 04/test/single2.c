/*头结点带数据的单链表*/
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
Link insert_tail(Link head, Link node);//尾插法
Link insert_head(Link head, Link node);//头插法
bool is_empty(Link head);//判断空链表
void display(Link head);//遍历链表
Link find_node(Link head, Datatype data);//查找结点
Link delete_node(Link head, Datatype data);//删除结点
void update_node(Link head, Datatype data, Datatype new_data);//修改（更新）结点
Link clean_list(Link head);//清空链表
Link remove_node(Link head, Datatype data, Link *get_p);//取出结点（不释放）
Link move_node(Link head, Link node1, Link node2);//移动结点

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
			mylist = insert_tail(mylist, creat_node(n));
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
			// mylist = delete_node(mylist, -n);
		
			//更新结点，修改结点
			// update_node(mylist, -n, -n*100);
			
			//取出结点
			Link get_p = NULL;
			mylist = remove_node(mylist, -n, &get_p);
			if (get_p != NULL)
			{
				printf("拿到数据：%d\n", get_p->data);
			}
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
	mylist = move_node(mylist, find_node(mylist, i), find_node(mylist, j));

	// mylist = clean_list(mylist);
	// printf("清空过后：\n");
	display(mylist);

	return 0;
}

//2.初始化新链表
Link init_list(void)
{
	//空链表直接用NULL指针表示
	return NULL;
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
Link insert_tail(Link head, Link node)
{
	//如果原来链表是空的，那么我们直接将新结点当做链表表头
	if (is_empty(head))
	{
		return node;
	}

	//(1)找到链表的尾部节点
	Link p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}

	//(2)将尾部节点的next指针设置为待插入节点的地址
	p->next = node;
	return head;
}

//5.遍历链表
void display(Link head)
{
	Link p = head;
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//6.头插法：将新节点插入到链表头部
//13.将node结点插入到任意结点head的后面
Link insert_head(Link head, Link node)
{
	if (node == NULL)
	{
		return head;
	}
	node->next = head;
	return node;
}

//7.判断空链表
bool is_empty(Link head)
{
	return (head == NULL);
}

//8.找到值为data的结点，并返回该结点的地址
Link find_node(Link head, Datatype data)
{
	Link p = head;
	while(p != NULL)
	{
		//找到
		if (p->data == data)
		{
			return p;
		}
		p = p->next;
	}
	//没有找到
	return NULL;
}

//9.删除值为data的结点
Link delete_node(Link head, Datatype data)
{
	if (is_empty(head))
	{
		return head;
	}

	//如果头结点就是待删节点
	if (head->data == data)
	{
		Link p = head->next;
		head->next = NULL;
		free(head);
		return p;
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
Link remove_node(Link head, Datatype data, Link *get_p)
{
	if (is_empty(head))
	{
		return NULL;
	}

	//如果头结点就是待删节点
	if (head->data == data)
	{
		Link p = head->next;
		head->next = NULL;
		*get_p = head;
		return p;
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
			*get_p = delete;
			return head;
		}
		prev = prev->next;
	}
	return head;
}

//12.清空链表
Link clean_list(Link head)
{
	if (head == NULL || is_empty(head))
	{
		return NULL;
	}
	while(head->next != NULL)
	{
		delete_node(head, head->next->data);
	}
	free(head);
	return NULL;
}

//14.将node1移动到node2结点的后面
Link move_node(Link head, Link node1, Link node2)
{
	if (node1 == NULL || node2 == NULL)
	{
		return head;
	}

	//将node1取出来
	Link get_p = NULL;
	head = remove_node(head, node1->data, &get_p);
	if (get_p == NULL)
	{
		return head;
	}

	//将node1插入到node2后面
	get_p->next = node2->next;
	node2->next = get_p;
	return head;
}
