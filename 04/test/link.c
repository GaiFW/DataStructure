#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Datatype;

//节点结构体声明
typedef struct node
{
	Datatype data;//数据域
	struct node *prev;//指针域：前驱节点指针
	struct node *next;//指针域：后继节点指针
}Node, *Link;

Link init_link(void);
Link creat_node(Datatype data);
void insert_node(Link node1, Link node2, Link new);
void insert_head(Link head, Link new);
void insert_tail(Link head, Link new);
void display_prev(Link head);
void display_next(Link head);
Link find_node(Link head, Datatype data);
void delete_node(Link head, Datatype data);
Link remove_node(Link head, Datatype data);
void update_node(Link head, Datatype old_data, Datatype new_data);
void move_node(Link head, int data2, int data1);

int main(int argc, char const *argv[])
{
	int n, m;

	//初始化空链表
	Link head = init_link();
	//添加5个节点
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &n);
		Link new = creat_node(n);
		insert_tail(head, new);
	}

	//遍历链表
	// display_prev(head);
	display_next(head);

	scanf("%d%d", &m, &n);
	//删除节点
	// delete_node(head, n);
	
	//取出节点
	// Link get_p = remove_node(head, n);
	// if (get_p == NULL)
	// {
	// 	printf("取出失败\n");
	// }
	// else
	// {
	// 	printf("取出节点：%d\n", get_p->data);
	// }

	//更新节点
	// update_node(head, m, n);

	//移动结点
	move_node(head, m, n);

	display_next(head);

	//查找节点
	// Link f = find_node(head, n);
	// if (f == NULL)
	// {
	// 	printf("没有对应节点\n");
	// }
	// else
	// {
	// 	printf("找到该节点\n");
	// }

	return 0;
}

//链表初始化
Link init_link(void)
{
	//(1)申请头节点空间
	Link head = malloc(sizeof(Node));
	if(head != NULL)
	{
		//(2)对头节点的成员进行初始化
		// head->data;//头节点不带数据的链表，不需要管data
		head->prev = head;
		head->next = head;
	}
	return head;
}

//创建节点
Link creat_node(Datatype data)
{
	//(1)申请节点空间
	Link new = malloc(sizeof(Node));
	if(new != NULL)
	{
		//(2)对节点的成员进行初始化
		new->data = data;
		new->prev = NULL;
		new->next = NULL;
	}
	return new;
}

//将new节点插入到node1和node2之间
void insert_node(Link node1, Link node2, Link new)
{
	if (node1 == NULL || node2 == NULL || new == NULL)
	{
		return;
	}

	new->prev = node1;
	new->next = node2;
	node1->next = new;
	node2->prev = new;
}

//头插法插入节点
void insert_head(Link head, Link new)
{
	insert_node(head, head->next, new);
	// //（1）找到第一个数据节点first
	// Link first = head->next;
	// //（2）将新节点插入到first的前面，head的后面
	// new->prev = head;
	// new->next = first;
	// head->next = new;
	// first->prev = new;
}

//尾插法插入节点
void insert_tail(Link head, Link new)
{
	insert_node(head->prev, head, new);
	// //（1）找到链表的尾部节点
	// Link tail = head->prev;
	// //（2）将新节点插入到尾部节点的后面，头节点的前面
	// new->next = head;
	// new->prev = tail;
	// head->prev = new;
	// tail->next = new;
}

//往前遍历双向循环链表
void display_prev(Link head)
{
	Link p = head;
	while(p->prev != head)
	{
		p = p->prev;
		printf("%d ", p->data);
	}
	printf("\n");
}

//往后遍历双向循环链表
void display_next(Link head)
{
	Link p = head;
	while(p->next != head)
	{
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//查找节点
Link find_node(Link head, Datatype data)
{
	if (head == NULL)
	{
		return NULL;
	}
	Link p = head;
	while(p->next != head)
	{
		p = p->next;
		if (p->data == data)
		{
			return p;
		}
	}
	//如果遍历完所有节点，都没有找到值为data的
	return NULL;
}

//删除节点
void delete_node(Link head, Datatype data)
{
	if (head == NULL || head->next == head)
	{
		return;
	}

	Link prev = head;
	while(prev->next != head)
	{
		//（1）先找到待删节点的前面节点
		if(prev->next->data == data)
		{
			//（2）删除
			Link delete = prev->next;
			Link next = delete->next;
			prev->next = next;
			next->prev = prev;

			delete->next = NULL;
			delete->prev = NULL;
			free(delete);
			break;
		}
		prev = prev->next;
	}
}

//取出节点
Link remove_node(Link head, Datatype data)
{
	if (head == NULL || head->next == head)
	{
		return NULL;
	}

	Link prev = head;
	while(prev->next != head)
	{
		//（1）先找到待删节点的前面节点
		if(prev->next->data == data)
		{
			//（2）删除
			Link delete = prev->next;
			Link next = delete->next;
			prev->next = next;
			next->prev = prev;

			delete->next = NULL;
			delete->prev = NULL;
			return delete;
		}
		prev = prev->next;
	}
	return NULL;
}

//移动节点node2节点移动到node1节点的后面
void move_node(Link head, int data2, int data1)
{
	Link node2 = remove_node(head, data2);
	Link node1 = find_node(head, data1);
	if (node1 != NULL && node2 != NULL)
	{
		insert_node(node1, node1->next, node2);
	}
}

//更新节点
void update_node(Link head, Datatype old_data, Datatype new_data)
{
	Link f = find_node(head, old_data);
	if (f != NULL)
	{
		f->data = new_data;
	}
}

/*
//插入的时候按照价格从小到大的顺序
void insert_node_price(Link head, Link new)
{
	// （1）先找到链表中第一个价格大于待插入节点价格的节点位置
	Link p = head;
	while(p->next != head)
	{
		p = p->next;
		if (p->data.price > new.price)
		{
			// （2）将待插入节点插入到当前节点的前面
			insert_node(p->prev, p, new);
		}
	}
	//（3）当遍历完都没有找到合适的位置，
	//说明该新节点的价格大于前面所有节点的价格，
	//将新节点插入到链表末尾
	insert_node(head->prev, head, new);
}*/


//通过第一个节点找到第二个节点
// Link find_second(Link head, Link first, float price)
// {
// 	Link second;
// 	if (first->prev == head)
// 	{
// 		second = first->next;
// 	}
// 	else if(first->next == head)
// 	{
// 		second = first->prev;
// 	}
// 	else//first左边和右边都有节点
// 	{
// 		float p1 = pirce - first->prev->data.price;
// 		float p2 = first->next->data.price - price;
// 		if (p1 < p2)
// 		{
// 			second = first->prev;
// 		}
// 		else
// 		{
// 			second = first->next;
// 		}
// 	}
// 	return second;
// }

// Link find_third(Link head, Link first, Link second, float price)
// {

// 	Link left;
// 	Link right;

// 	if (first->data.pirce > second->data.price)
// 	{
// 		left = second->prev;
// 		right = first->next;
// 	}
// 	else
// 	{
// 		left = first->prev;
// 		right = second->next;
// 	}

// 	if (left == head)
// 	{
// 		return right;
// 	}
// 	else if (right == head)
// 	{
// 		return left;
// 	}
// 	else
// 	{
// 		float p1 = price - left->data.price;
// 		float p2 = right->data.price - price;
// 		if (p1 < p2)
// 		{
// 			return left;
// 		}
// 		else
// 		{
// 			return right;
// 		}
// 	}
// }

// void show(Link first, Link second, Link third)
// {

// }

// // 能够通过一个价格查询与这个价格最相近的三种商品并显示
// void find_3price(Link head, float price)
// {
// 	//(1)找到与待查价格最近的第一个节点
// 	Link p = head;
// 	Link first, second, third;

// 	while(p->next != head)
// 	{
// 		p = p->next;
// 		if (p->data.price == price)
// 		{
// 			//p第一个节点
// 			first = p;
// 			//第二个节点？
// 			second = find_second(head, first, price);
// 			//第三个节点？
// 			third = find_third(head, first, second, price);
// 			show(first, second, third);
// 		}
// 		else if(p->data.price > price)
// 		{
// 			if (p->prev == head)
// 			{
// 				first = p;
// 			}
// 			//第一个节点一定是p或者p->prev
// 			float p1 = pirce - p->prev->data.price;
// 			float p2 = p->data.price - price;
// 			//与左边节点的价格更接近，那么左边节点就是第一个节点，否则右边节点是第一个节点
// 			if (p1 < p2)
// 			{
// 				first = p->prev;
// 				second = find_second(head, first, price);
// 				third = find_third(head, first, second, price);
// 				show(first, second, third);
// 			}
// 			else
// 			{
// 				first = p;
// 				second = find_second(head, first, price);
// 				third = find_third(head, first, second, price);
// 				show(first, second, third);
// 			}
// 		}
// 	}
// 	//(2)遍历完都没有找到，那么第一个节点就是尾部节点
// 	//这种情况，最后三个节点就是我们的待查节点
// 	first = head->prev;
// 	second = first->prev;
// 	third = second->prev;
// 	show(first, second, third);
// }

// void find_3price(Link head, float price)
// {
// 	Link p = head;

// 	p = p->next;
// 	Link first = p;
// 	float c1 = (first->data.price - price)>0 ? (first->data.price - price) : (price-first->data.price);

// 	p = p->next;
// 	Link second = p;
// 	float c2 = (second->data.price - price)>0 ? (second->data.price - price) : (price-second->data.price);

// 	p = p->next;
// 	third = p;
// 	float c3 = (third->data.price - price)>0 ? (third->data.price - price) : (price-third->data.price);

// 	while(p->next != head)
// 	{
// 		p = p->next;
// 		float c = (p->data.price - price)>0 ? (p->data.price - price) : (price-p->data.price);
// 		if (c<c1 || c<c2 || c<c3)
// 		{
// 			int x = (c1>c2?c1:c2)>c3 ? (c1>c2?c1:c2) : c3;
// 			if (c1 == x)
// 			{
// 				first = p;
// 				c1 = c;
// 			}
// 			else if (c2 == x)
// 			{
// 				second = p;
// 				c2 = c;
// 			}
// 			else if (c3 == x)
// 			{
// 				third = p;
// 				c3 = c;
// 			}
// 		}
// 	}

// 	show(first, second, third);
// }
