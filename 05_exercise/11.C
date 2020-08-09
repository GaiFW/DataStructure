/*************************************************************************
数字->小数点，右括号，运算符
左括号->数字，左括号, 不可以结束
运算符->数字，左括号, 不可以结束
小数点后面->数字, 不可以结束
右括号->运算符，可以结束
结束，数字，   小数点，左括号，右括号，运算符
**************************************************************************/
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

#define NUMBER  (unsigned char)0x3b
#define LEFT    (unsigned char)0X14
#define RIGHT   (unsigned char)0X23
#define POINT   (unsigned char)0X10
#define ACCU    (unsigned char)0X14


#define ISNUMBER (unsigned char)0X10
#define ISLEFT   (unsigned char)0X04
#define ISRIGHT  (unsigned char)0X02
#define ISPOINT  (unsigned char)0X08
#define ISACCU   (unsigned char)0X01


#define START 0x14
#define END   0x20

typedef struct QUEU_FLOAT_T
{
    int head;
    int tail;
    float data[18];
}QUEU_FLOAT_T;

/*输入表达式，语法分析 */

int InputString(char * str)
{
    int flag_left = 0;
    unsigned char flag_next;
    unsigned char allow_pre = START;
    unsigned char allow_next = 0;
    unsigned char emerge = 0;
    int ret = 0;
    
    printf("\n please input the expression :\n");
    fgets(str,sizeof(str),stdin);
    fputs(str,stdout);
    
    while('\0' != *str)
    {
        if(('0' <= *str) && (*str <= '9'))
        {
            emerge = ISNUMBER ;
            allow_next = NUMBER;
        }
        else if('(' == *str)
        {
            emerge = ISLEFT;
            allow_next = LEFT;
            flag_left++;
        }
        else if(')' == *str)
        {
            emerge = ISRIGHT;
            allow_next = RIGHT;
            flag_left--;
        }
        else if('.' == *str)
        {
            emerge = ISPOINT;
            allow_next = POINT;
        }
        else if(('+' == *str) || ('-' == *str) || ('*' == *str) || ('/' == *str))
        {
            emerge = ISACCU;
            allow_next = ACCU;
        }
        else
        {
            printf("ERROR:illegal character");
            return 1;
        }
    	
        if(allow_pre & emerge)
        {
            str++;
            allow_pre = allow_next;
        }
        else
        {
            printf("ERROR:expression error");
            return 2;
        }
        if(flag_left < 0)
        {
            printf("ERROR:左括号出现在右括号之前");
            ret = 3;
        }
    }
    if(flag_left)
    {
        printf("ERROR:左右括号不匹配");
        ret = 3;
    }
    if(!(allow_pre & END))
    {
        printf("\nERROR:expressin is not over!\n");
        ret = 4;
    }
    
    return ret;
}

/* 表达式转换 */
int Translate2(char * str, QUEU_FLOAT_T * data_t, char * str_op)
{
    char con_float[13] = {'\0'};
    int tail = 0;
    int count_i = 0;
    int count;
    int flag_break = 1;
    
    while(flag_break)
    {
        if((('0' <= *str) && (*str <= '9')) || ('.' == *str))
        {
            con_float[count_i++] = *str;
        }
        else
        {
    		
            if(count_i || ('\0' == *str))
            {
                con_float[count_i] = '\0';
    			
                data_t->data[data_t->tail] = atof(con_float);
                str_op[tail] = data_t->tail + 1;/*************** 加1 *****/
            	tail++;
                data_t->tail++;
                count_i = 0;
                if('\0' == *(str))
        		{
                    str_op[tail] = '\0';
                	return 0;
                    flag_break = 0;
        		}
            }
        	if(1)
    		{
                str_op[tail] = *str;
            	tail++;
    		}
        }
        str++;
    }
    str_op[tail] = '\0';
    
    for(count = 0; '\0' != *(str_op + count); count++)
    {
        printf(" show op %d(%c) ",str_op[count],str_op[count]);
    }
    return 0;
}


/* 显示转换后的结果 */
void Show(QUEU_FLOAT_T data_t, char * str_op)
{
    int count_i = 0;
    for(count_i = 0; count_i < data_t.tail; count_i++)
    {
        printf("show da %7.7f ",data_t.data[count_i]);
    }
    printf("str_op%d(%d),%d(%c),%d(%c)",str_op[0],str_op[0],str_op[1],str_op[1],str_op[2],str_op[2]);
    for(count_i = 0; '\0' != *(str_op + count_i); count_i++)
    {
        printf(" show op %d(%c) ",str_op[count_i],str_op[count_i]);
    }
    
}


/* 查找指定字符 */
int SearchCharacter1(char * str_op, char ch)
{
    int count_i = 0;
    while('\0' != *(str_op + count_i))
    {
        if(*(str_op + count_i) == ch)
        {
            return count_i;
        }
        else
        {
            count_i++;
        }
    }
    return -1;
}
/* 查找匹配的左右括号 */
int SearchCharacter2(char * str_op, int * left, int * right)
{
    int count_i = 0;
    int count_j = 0;
    
    while('\0' != *(str_op + count_j))
    {
        if('(' == *(str_op + count_j))
        {
            if(0 == count_i)
    		{
                *left = count_j;
    		}
            count_i++;
        }
        if(')' == *(str_op + count_j))
        {
            count_i--;
            if(! count_i)
    		{
                *right = count_j;
                return 0;
    		}
        }
        count_j++;
    }
    return 0;
}
/* 移位 */
void ShiftOp(int start, int end, char * str_op, char * str_cp)
{
    int sh = end - start;
    int index_i = 0;
    
    if(NULL != str_cp)
    {
        for(index_i = 0; index_i < sh - 1; index_i++)
    	{
            str_cp[index_i] = str_op[start + index_i + 1];/*是否有0*/
        }
        str_cp[index_i] = '\0';
        index_i = 0;
    }
    
    while('\0' != str_op[end + index_i])
    {
    	
        str_op[start + index_i] = str_op[end + index_i];
        index_i++;
    }
    /*应该移动0*/
    str_op[start + index_i] = '\0';
}

/* 计算指定运算 */
int Compute4(char * str_op, QUEU_FLOAT_T * da_t,char ch)
{
    int left = 1;
    float re = 0.0;
    
    while(-1 != left)
    {
        left = SearchCharacter1(str_op, ch);
        if(-1 != left)
    	{
            switch(ch)
    		{
                case '*' : re = da_t->data[str_op[left - 1] - 1] * da_t->data[str_op[left + 1] - 1]; break;
    			
                case '/' : re = da_t->data[str_op[left - 1] - 1] / da_t->data[str_op[left + 1] - 1]; break;
    			
                case '+' : re = da_t->data[str_op[left - 1] - 1] + da_t->data[str_op[left + 1] - 1]; break;
    			
                case '-' : re = da_t->data[str_op[left - 1] - 1] - da_t->data[str_op[left + 1] - 1]; break;
    			
                default : ;
    		}
            ShiftOp(left, left + 2, str_op, NULL);
            da_t->data[da_t->tail++] = re;
            str_op[left - 1] = da_t->tail;
    	}
    }
    return 0;
}

/* 开始计算 先括号，再乘除，最后加减 */
float Computer3(QUEU_FLOAT_T * da_t, char * str_op)
{
    int left = 1;
    int right = 1;
    float re = 0.0;
    char str_cp[50] = {'\0'};
    /*去括号*/
    while(-1 != left)
    {
        right = left = -1;
        SearchCharacter2(str_op, &left, &right);
        if(-1 != right)
        {
            ShiftOp(left, right, str_op, str_cp);
            re = Computer3(da_t, str_cp);
            da_t->data[da_t->tail++] = re;
            str_op[left] = da_t->tail;
        }
    }
    Compute4(str_op, da_t, '*');
    Compute4(str_op, da_t, '/');
    Compute4(str_op, da_t, '+');
    Compute4(str_op, da_t, '-');
    
    printf("\n the end is :%f",da_t->data[da_t->tail - 1]);
    
    return da_t->data[da_t->tail - 1];
}

/* 初始化数据 */
void Initial(QUEU_FLOAT_T * pr_da_t, char * str_op)
{
    int index_i = 0;
    
    pr_da_t->head = 0;
    pr_da_t->tail = 0;
    
    while(index_i < 100)
    {
        str_op[index_i] = '\0';
        index_i++;
    }
}

int main(void)
{
    char str[100] = {'\0'};
    char str_op[100] = {'\0'};
    char contral = 0;
    float end= 0;
    
    QUEU_FLOAT_T qu_da_t;
    
    while(contral != 1)
    {
        Initial(& qu_da_t, str_op);
    	
        printf("\n\t*MENU*\n'j' is to computer\n'q' is to exit\n'c' is to clear the screen\nplease to input:");
        contral = getchar();
        fflush(stdin);
        switch(contral)
        {
        case 'j' :
        case 'J' :  
            if(! InputString(str))
    		{
                Translate2(str, &qu_da_t, str_op);
                //Show(qu_da_t, str_op);
                printf("\n %s  the end is:%f",str, Computer3(&qu_da_t, str_op));
    		}
            break;
    		
        case 'q' :
        case 'Q' :  exit(1);
            break;
        	/*
            case 'c' :
            case 'C' : clrscr();
            break;
    		
              default :  ;
            */      }
            contral = 0;
    }
    	
}

