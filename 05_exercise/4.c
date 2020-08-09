#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
	float * data_arr;
	int top;
	int size;
} dataStack, *dataStack_p;

typedef struct
{
	char * char_arr;
	int top;
	int size;
} charStack, *charStack_p;

dataStack_p Dstack_init()
{
	dataStack_p theDstack = (dataStack_p)malloc(sizeof(dataStack));
	if (theDstack != NULL)
	{
		theDstack->data_arr = (float *)malloc(sizeof(float) * 50);
		memset(theDstack->data_arr, 0, 50);
		theDstack->size = 50;
		theDstack->top = -1;
		return theDstack;
	}
}

charStack_p Cstack_init()
{
	charStack_p theCstack = (charStack_p)malloc(sizeof(charStack));
	if (theCstack != NULL)
	{
		theCstack->char_arr = (char *)malloc(sizeof(char) * 50);
		memset(theCstack->char_arr, 0, 50);

		theCstack->size = 50;
		theCstack->top = -1;
		return theCstack;
	}
}

bool is_empty_data(dataStack_p theDstack)
{
	return theDstack->top == -1;
}

bool is_empty_char(charStack_p theCstack)
{
	return theCstack->top == -1;
}

bool is_full_data(dataStack_p theDstack)
{
	return theDstack->top == theDstack->size - 1;
}


bool is_full_char(charStack_p theCstack)
{
	return theCstack->top == theCstack->size - 1;
}

bool data_push(dataStack_p theDstack, float data)
{
	if (is_full_data(theDstack))
	{
		return 0;
	}
	else
	{
		theDstack->top++;
		theDstack->data_arr[theDstack->top] = data;
		return 1;
	}
}

bool char_push(charStack_p theCstack, char data)
{
	if (is_full_char(theCstack))
	{
		return 0;
	}
	else
	{
		theCstack->top++;
		theCstack->char_arr[theCstack->top] = data;
		return 1;
	}
}

bool data_pop(dataStack_p theDstack, float * num1, float *num2)
{
	if (is_empty_data(theDstack))
	{
		return 0;
	}
	*num2 = theDstack->data_arr[theDstack->top];
	theDstack->top--;
	*num1 = theDstack->data_arr[theDstack->top];
	theDstack->top--;
	return 1;
}

bool char_pop(charStack_p theCstack,char * fu)
{

	if (is_empty_char(theCstack))
	{
		return 0;
	}

	*fu= (theCstack->char_arr)[theCstack->top];
	theCstack->top--;
	return 1;
}

float qushu(char * buf, int *i)
{
	char data_buf[20] = "";
	int j = 0;
	while (buf[*i] != 0 && (buf[*i] == 46 || (buf[*i] > 47 && buf[*i] < 58) ))
	{
		data_buf[j] = buf[(*i)];
		(*i)++;
		j++;
	}
	return atof(data_buf);
}
int youxianji(char fu)
{
	switch (fu)
	{
	case '}':
		return -3;
	case ']':
		return -2;
	case ')':
		return -1;
	case '+':
		return 1;
		break;
	case '0':
		return 0;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	}
}

float yunsuan(char fu, float num1, float num2)
{
	switch (fu)
	{
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '/':
		return num1 / num2;
		break;
	}

}
float cacu(dataStack_p theDstack,charStack_p theCstack, char * buf,int end,int first,int *buf_i);


int buf_i = 0;
int main()
{
	dataStack_p theDstack = Dstack_init();
	charStack_p theCstack = Cstack_init();
	char buf[100] = "";
	fgets(buf, sizeof(buf), stdin);
// float cacu(theDstack,theCstack, buf,10,0,&buf_i);


	// while (buf[buf_i] != 10)
	// {
	// 	//取数 压栈
	// 	data_push(theDstack, qushu(buf, &buf_i));
	// 	if(buf[buf_i] != 10 )
	// 	{

	// 		if( youxianji(theCstack->char_arr[theCstack->top]) >= youxianji(buf[buf_i]))
	// 		{
	// 			while (1)
	// 			{
	// 				float num1, num2;
	// 				char p;
	// 				data_pop(theDstack, &num1, &num2);
	// 				char_pop(theCstack, &p);
	// 				data_push(theDstack, yunsuan(p, num1, num2));
	// 				if (youxianji(buf[buf_i]) > youxianji(theCstack->char_arr[theCstack->top]))
	// 				{
	// 					break;
	// 				}
	// 			}
	// 			char_push(theCstack, buf[buf_i]);
	// 			buf_i++;
	// 			// if(buf[buf_i] == 41)
	// 			// {
	// 			// 	char_push(theCstack, buf[buf_i]);
	// 			// 	buf_i++;
	// 			// 	while (buf[buf_i] != 10)
	// 			// 	{
	// 			// 		data_push(theDstack, qushu(buf, &buf_i));
	// 			// 	}
					
	// 			// }
	// 		}
	// 		else
	// 		{
	// 			char_push(theCstack, buf[buf_i]);
	// 			buf_i++;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (1)
	// 		{
	// 			float num1, num2;
	// 			char p;
	// 			data_pop(theDstack, &num1, &num2);
	// 			char_pop(theCstack, &p);
	// 			data_push(theDstack, yunsuan(p, num1, num2));
	// 			if (theDstack->top == 0)
	// 			{
	// 				break;
	// 			}
	// 		}
	// 		break;

	// 	}
	// }

	printf("%.2f\n", cacu(theDstack,theCstack, buf,10,0,&buf_i));

	return 0;
}

float cacu(dataStack_p theDstack,charStack_p theCstack, char * buf,int end,int first,int *buf_i)
{
	while (buf[*buf_i] != end)
	{

		//取数 压栈
		data_push(theDstack, qushu(buf, buf_i));
		if(buf[*buf_i] != end )
		{

			if( youxianji(theCstack->char_arr[theCstack->top]) >= youxianji(buf[*buf_i]))
			{
				if(buf[*buf_i]==')')
				{
					printf("括号匹配错误！\n");
					return 0;
				}
				while (1)
				{
					float num1, num2;
					char p;
					data_pop(theDstack, &num1, &num2);
					char_pop(theCstack, &p);
					data_push(theDstack, yunsuan(p, num1, num2));
					if (youxianji(buf[*buf_i]) > youxianji(theCstack->char_arr[theCstack->top]))
					{
						break;
					}
				}
				char_push(theCstack, buf[*buf_i]);
				(*buf_i)++;
				if(buf[*buf_i] == '(')
				{
					char_push(theCstack, buf[*buf_i]);
					buf_i++;
					while (buf[*buf_i] != 10)
					{
						data_push(theDstack, cacu(theDstack,theCstack,buf,41, 40,buf_i));
						// data_push(theDstack, qushu(buf, buf_i));
					}
					char p;
					char_pop(theCstack, &p);
					if(buf[*buf_i] == 10)
					{
						while (1)
						{
							float num1, num2;
							char p;
							data_pop(theDstack, &num1, &num2);
							char_pop(theCstack, &p);
							data_push(theDstack, yunsuan(p, num1, num2));
							if (theDstack->top == 0)
							{
								char_push(theCstack, buf[*buf_i]);
								(*buf_i)++;
								char p;
								char_pop(theCstack, &p);
								break;
							}
						}
					break;
					}
					else
					{
						char_push(theCstack, buf[*buf_i]);
						buf_i++;
					}
				}
			}
			else
			{
				char_push(theCstack, buf[*buf_i]);
				(*buf_i)++;
				if(buf[*buf_i] == '(')
				{
					char_push(theCstack, buf[*buf_i]);
					buf_i++;
					while (buf[*buf_i] != 10)
					{
						data_push(theDstack, cacu(theDstack,theCstack,buf,')', '(',buf_i));
					}
					char p;
					char_pop(theCstack, &p);
					if(buf[*buf_i] == 10)
					{
						while (1)
						{
							float num1, num2;
							char p;
							data_pop(theDstack, &num1, &num2);
							char_pop(theCstack, &p);
							data_push(theDstack, yunsuan(p, num1, num2));
							if (theDstack->top == first)
							{
								char_push(theCstack, buf[*buf_i]);
								(*buf_i)++;
								char p;
								char_pop(theCstack, &p);
								break;
							}
						}
					break;
					}
					else
					{
						char_push(theCstack, buf[*buf_i]);
						buf_i++;
					}
				}
			}
		}
		else
		{
			while (1)
			{
				float num1, num2;
				char p;
				data_pop(theDstack, &num1, &num2);
				char_pop(theCstack, &p);
				data_push(theDstack, yunsuan(p, num1, num2));
				if (theDstack->top == first)
				{
					char_push(theCstack, buf[*buf_i]);
					(*buf_i)++;
					char p;
					char_pop(theCstack, &p);
					break;
				}
			}
			break;
		}
	}
	return theDstack->data_arr[theDstack->top];
}
