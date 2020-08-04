#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
	int num;
	char name[32];
	int age;
	float grade;
}student;

typedef struct node
{
	student stu_info;
	struct node * next;
}Node,*Node_p;


Node_p headNode();
Node_p newNode(student stu);
void insertNode(Node_p *head,Node_p new);
bool delNode(Node_p* head,int num);
void update_num(Node_p head,int num);
void find(Node_p head,int num);