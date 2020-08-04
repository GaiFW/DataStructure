#include"1_3.h"

int main(int argc, char const *argv[])
{
	Node_p head = headNode();
	for (int i = 0; i < 5; ++i)
	{
		student stu;
		printf("请输入学号：姓名：年龄：成绩");
		scanf("%d %s %d %f", &stu.num, stu.name, &stu.age, &stu.grade);
		insertNode(&head, newNode(stu));
	}

	int op = 1;
	int nu = 0;
	int del_n = 0;
	int upd_n = 0;
	int sel_n = 0;
	while (op)
	{
		printf("your opration:\n1 add增加 2 del删除 3 update修改 4 sel查找 0 exit 5显示\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1://add
			printf("添加几个：");
			scanf("%d", &nu);
			for (int i = 0; i < nu; i++)
			{
				student stu;
				printf("请输入学号：姓名：年龄：成绩");
				scanf("%d %s %d %f", &stu.num, stu.name, &stu.age, &stu.grade);
				insertNode(&head, newNode( stu));
			}
			break;
		case 2://del
			printf("删除哪个学号：");
			scanf("%d", &del_n);
			if (delNode(&head, del_n))
			{
				printf("删除成功\n");
			}
			else
			{
				printf("删除失败\n");
			}
			break;
		case 3://update

			printf("修改哪个学号：");
			scanf("%d", &upd_n);
			update_num(head, upd_n);
			break;
		case 4://sel

			printf("查找哪个学号：");
			scanf("%d", &sel_n);
			find(head, sel_n);
			break;
		case 0://exit
			break;
		case 5://show
			display(head);
			break;
		default:
			printf("输入有误，重新输入\n");
			break;
		}
	}
	return 0;
}