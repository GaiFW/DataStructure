#include"1_3.h"

Node_p headNode()
{
	return NULL;
}

Node_p newNode(student stu)
{
	Node_p new = (Node_p)malloc(sizeof(Node));
	if (new != NULL)
	{
		new->stu_info = stu;
		new->next = NULL;
		return new;
	}
	perror("new");
	return NULL;
}

void insertNode(Node_p *head, Node_p new)
{
	// static int N=0;
	// N++;
	/*按学习成绩由高到低排序*/
	if (*head == NULL)
	{	/*判断是否是第一个插入的*/
		*head = new;
		new = NULL;
		// printf("000NI:%d,%p\n",N,*head);
		return;
	}
	Node_p tmp = *head;
	Node_p fr_tmp = NULL;
	while (new->stu_info.grade < tmp->stu_info.grade)
	{
		fr_tmp = tmp;
		if (tmp->next == NULL)
		{	/*如果是最后一个*/
			tmp->next = new;
			new = NULL;
			// printf("111NI:%d,%p\n",N,tmp->next);
			return;
		}

		tmp = tmp->next;
	}
	if (fr_tmp == NULL)
	{	/*如果比头节点大*/
		new->next = *head;
		*head = new;
		new = NULL;
		// printf("222NI:%d,%p\n",N,*head);
		return;
	}
	else
	{	/*比头节点小 并且不是最后一个*/
		new->next = fr_tmp->next;
		fr_tmp->next = new;
		// printf("3333NI:%d,%p\n",N,new);
		return ;
	}
}

void display(Node_p head)
{
	Node_p tmp = head;
	while (tmp != NULL)
	{
		printf("学号：%d\t姓名：%s\t年龄：%d\t成绩%.2f\t\n", \
		       tmp->stu_info.num, tmp->stu_info.name, \
		       tmp->stu_info.age, tmp->stu_info.grade);
		// printf("tmp:%p\n",tmp );
		if (tmp->next == NULL)
		{
			// printf("\n---------");
			return;
		}
		tmp = tmp->next;
	}
	// printf("\n222222222222222222");
}

bool delNode(Node_p* head, int num)
{
	if (*head == NULL)
	{
		return 0;
	}
	else if ((*head)->next == NULL && (*head)->next->stu_info.num != num)
	{
		return 0;
	}
	else
	{
		Node_p tmp = *head;
		Node_p fr_tmp = NULL;
		while (tmp->stu_info.num != num )
		{
			fr_tmp = tmp;
			if (tmp->next == NULL)
			{
				return 0;
			}
			tmp = tmp->next;
		}
		if (fr_tmp == NULL)
		{
			*head = tmp->next;
			free(tmp);
			tmp = NULL;
			return 1;
		}
		else
		{
			fr_tmp->next = tmp->next;
			free(tmp);
			tmp = NULL;
			return 1;
		}
	}
}
void update_num(Node_p head, int num)
{
	if (head == NULL)
	{
		printf("空的\n");
		return;
	}
	else
	{
		Node_p tmp = head;
		while (tmp->stu_info.num != num)
		{
			if (tmp->next == NULL)
			{
				printf("没有这个学号\n");
				return;
			}
			tmp = tmp->next;
		}
		printf("请输入要改变的学号：姓名：年龄：成绩");
		scanf("%d %s %d %f", &tmp->stu_info.num, tmp->stu_info.name, &tmp->stu_info.age, &tmp->stu_info.grade);
		printf("修改成功\n");
		return;
	}
}
void update_name(char *name)
{

}
void find(Node_p head, int num)
{
	if (head == NULL)
	{
		printf("空的\n");
		return;
	}
	else
	{
		Node_p tmp = head;
		while (tmp->stu_info.num != num)
		{
			if (tmp->next == NULL)
			{
				printf("没有这个学号\n");
				return;
			}
			tmp = tmp->next;
		}
		printf("学号：%d\t姓名：%s\t年龄：%d\t成绩%.2f\t\n", \
		       tmp->stu_info.num, tmp->stu_info.name, \
		       tmp->stu_info.age, tmp->stu_info.grade);
		printf("\n");
		return;
	}
}

