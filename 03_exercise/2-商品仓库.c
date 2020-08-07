#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int n = 0;
typedef struct
{
	int num;
	char name[32];
	float price;
	char sort[32];
	int mount;
} Goods;

typedef struct node
{
	Goods good;
	struct node *prev;
	struct node *next;
} Node, *Node_p;

Node_p headNode()
{
	Node_p head = (Node_p)malloc(sizeof(Node));
	if (head != NULL)
	{
		head->next = head;
		head->prev = head;
		return head;
	}
	perror("head");
	return NULL;
}

Node_p newNode(Goods good)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if (new != NULL)
	{
		new->good = good;
		new->next = NULL;
		new->prev = NULL;
		return new;
	}
	perror("new");
	return NULL;
}

bool insertNode(Node_p head, Node_p new)
{
	if (head != NULL && new != NULL)
	{
		if (head->next != head)
		{
			Node_p tmp = head->next;
			while (tmp != head && new->good.price > tmp->good.price)
			{
				tmp = tmp->next;
			}
			Node_p pre = tmp->prev;
			pre->next = new;
			new->prev = pre;
			tmp->prev = new;
			new->next = tmp;
			return 1;
		}
		else
		{
			head->next = new;
			new->next = head;
			head->prev = new;
			new->prev = head;
			return 1;
		}
	}
	else
	{
		perror("head new");
		return 0;
	}
}

Node_p findNode(Node_p head, int num)
{
	if (head != NULL)
	{
		Node_p tmp = head->next;
		while (tmp != head && tmp->good.num != num)
		{
			tmp = tmp->next;
		}
		if (tmp == head)
		{
			printf("没有这个num\n");
			return NULL;
		}
		else
		{
			return tmp;
		}
	}
	printf("head wrong\n");
	return NULL;
}

bool delNode(Node_p head, Node_p node)
{
	if (head == NULL || node == NULL)
	{
		perror("head or node wrong del");
		return 0;
	}
	else
	{
		Node_p tmp = head->next;
		while (tmp != node && tmp != head)
		{
			tmp = tmp->next;
		}
		if (tmp == node)
		{
			//删除并且改动后面的编号
			Node_p pr = tmp->prev;
			Node_p nx = tmp->next;
			pr->next = nx;
			nx->prev = pr;
			free(tmp);
			printf("删除成功\n");
			return 1;
		}
		else
		{
			printf("no this good!\n");
			return 0;
		}
	}
}

void selNode(Node_p head, float price)
{
	if (head != NULL)
	{
		Node_p tmp = head->next;
		int len = 0;
		float *arr = (float *)malloc(sizeof(float));
		while (tmp != head)
		{
			len++;
			arr = realloc(arr, sizeof(float) * len);
			arr[len - 1] = tmp->good.price - price;
			if(arr[len-1]<0)
			{
				arr[len-1] = -arr[len-1];
			}

			tmp = tmp->next;
		}
		//从小到大
/*		float tp = 0;
		for (int i = 0; i < len - 1; i++) //比较m-1次
		{
			for (int j = 0; j < len - i - 1; j++) // 最后一次比较a[m-i-1]与a[m-i-2]
			{
				if (arr[j] > arr[j + 1]) //如果a[j]比a[j+1]大则交换内容
				{
					tp = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = tp;
				}
			}
		}*/
		for (int i = 0; i < len; i++)
		{
			printf("--%f", arr[i]);
		}
		printf("\n");

		//找绝对值最小的下标
		float min = arr[len - 1];
		int mi=0;
		// int z_f = 0;
		for (int i = 0; i < len; i++)
		{
			if (min > arr[i])
			{
				// z_f = 1;
				min = arr[i];
				mi = i;
			}
		}
		printf("22%.2f\n", min );
		// if (!z_f)
		// {min = -min;}
		if(mi == 0)
		{
			tmp = head->next;
			for (int i = 0; i < 3; i++)
			{
				printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
				tmp = tmp->next;
			}
		}
		else if(mi == len -1 )
		{
			tmp = head->prev->prev;
			for (int i = 0; i < 3; i++)
			{
				printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
				tmp = tmp->next;
			}
		}
		else if(mi == 1)
		{
			if(arr[mi-1]>arr[mi+2])
			{
				tmp = head->next->next;
				for (int i = 0; i < 3; i++)
				{
					printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
					tmp = tmp->next;
				}
			}
			else
			{
				tmp = head->next;
				for (int i = 0; i < 3; i++)
				{
					printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
					tmp = tmp->next;
				}
			}
		}
		else if(mi == len-2)
		{
			if(arr[mi+1]>arr[mi-2])
			{
				tmp = head->prev->prev->prev;
				for (int i = 0; i < 3; i++)
				{
					printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
					tmp = tmp->next;
				}
			}
			else
			{
				tmp = head->prev->prev;
				for (int i = 0; i < 3; i++)
				{
					printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
					tmp = tmp->next;
				}
			}
		}
		else
		{
			tmp = head->next;
			while (tmp != head)
			{
				if (tmp->good.price - price == min )
				{
					if(arr[mi-1] > arr[mi+1])
					{
						if(arr[mi-1] > arr[mi+2])
						{
							//找mi 往后3个
							printf("11111\n");
							for (int i = 0; i < 3; i++)
							{
								printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
								tmp = tmp->next;
							}
							return;
						}
						//mi 中
						printf("2222\n");
						tmp = tmp->prev;
						for (int i = 0; i < 3; i++)
						{
							printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
							tmp = tmp->next;
						}
						return;
					}
					else
					{
						if(arr[mi+1]>arr[mi-2])
						{
							//mi最后一个
							tmp = tmp->prev->prev;
							printf("333333\n");
							for (int i = 0; i < 3; i++)
							{
								printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
								tmp = tmp->next;
							}
							return;
						}
						//mi中
						tmp = tmp->prev;
						printf("44444\n");
						for (int i = 0; i < 3; i++)
						{
							printf("商品信息：%d\t%s\t%.2f\t%s\t%d\t\n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
							tmp = tmp->next;
						}
						return;
					}
					return ;
				}
				tmp = tmp->next;
			}
		}
	}
	else
	{
		perror("head");
		return;
	}
}

void display(Node_p head)
{

	if (head != NULL)
	{	Node_p tmp = head->next;
		while (tmp != head)
		{
			printf("商品信息：%d %s %.2f %s %d \n", tmp->good.num, tmp->good.name, tmp->good.price, tmp->good.sort, tmp->good.mount);
			tmp = tmp->next;
		}
		printf("\n");
	}
	else
	{
		printf("空的\n");
	}
	return;
}

bool altNode(Node_p head, Node_p node)
{
	if (head == NULL || node == NULL)
	{
		perror("head or node wrong del");
		return 0;
	}
	else
	{
		Node_p tmp = head->next;
		while (tmp != node && tmp != head)
		{
			tmp = tmp->next;
		}
		if (tmp == node)
		{
			//修改并排序
			printf("input your goodinfo:");
			char name[32];
			char sort[32];
			scanf("%s %f %s %d", name, &tmp->good.price, sort, &tmp->good.mount);
			strcpy(node->good.name, name);
			strcpy(node->good.sort, sort);

			Node_p pre = node->prev;
			Node_p nxe = node->next;
			pre->next = nxe;
			nxe->prev = pre;

			tmp = head->next;
			while (tmp != head && node->good.price > tmp->good.price)
			{
				tmp = tmp->next;
			}
			pre = tmp->prev;
			pre->next = node;
			node->prev = pre;
			tmp->prev = node;
			node->next = tmp;

			printf("修改成功\n");
			return 1;
		}
		else
		{
			printf("no this good!\n");
			return 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	Node_p head = headNode();
	int numm = 0;
	printf("你有多少商品\n");
	scanf("%d", &numm);

	printf("输入你的商品信息 name price sort mount\n");
	for (int i = 0; i < numm; i++)
	{
		Goods good;
		good.num = ++n;
		scanf("%s %f %s %d", good.name, &good.price, good.sort, &good.mount);
		insertNode(head, newNode(good));
	}
	int op = 1;
	int n_add = 0;
	int n_alt = 0;
	float n_pr = 0;
	int n_del = 0;
	while (op)
	{
		printf("1 显示 2 增加 3 改动 4 查价格 5 删除 0退出 \n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			display(head);
			break;
		case 2:
			printf("增加多少商品\n");
			scanf("%d", &n_add);
			printf("输入你的商品信息 num name price sort mount\n");
			for (int i = 0; i < n_add; i++)
			{
				Goods good;
				good.num = ++n ;
				scanf("%s %f %s %d", good.name, &good.price, good.sort, &good.mount);
				insertNode(head, newNode(good));
			}
			break;
		case 3:
			printf("商品号\n");
			scanf("%d", &n_alt);
			altNode(head, findNode(head, n_alt));
			break;
		case 4:
			printf("价格\n");
			scanf("%f", &n_pr);
			selNode(head, n_pr);
			break;
		case 5:
			printf("商品号\n");
			scanf("%d", &n_del);
			delNode(head, findNode(head, n_del));
			break;
		case 0:
			break;
		}
	}
	return 0;
}
