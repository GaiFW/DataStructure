#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>


typedef struct
{
    int * arr;
    int size;
    int top;
}Stack,*Stack_p;

Stack_p stack_init(int size)
{
    Stack_p theStack = (Stack_p)malloc(sizeof(Stack));
    if(theStack != NULL)
    {
        theStack->arr = calloc(size,sizeof(int));
        if(theStack != NULL)
        {
        theStack->size = size;
        theStack->top = -1;
        return theStack;
        }
        perror("arr");
        return NULL;
    }
    perror("theStack");
    return NULL;
}

bool is_empty(Stack_p theStack)
{
    return theStack->top == -1;
}
bool is_full(Stack_p theStack)
{
    return theStack->top == theStack->size-1;
}

bool push(Stack_p theStack,int data)
{
    if(is_full(theStack) || theStack==NULL)
    {
        return 0;
    }
    theStack->top++;
    theStack->arr[theStack->top] = data;
    return 1;
}

bool pop(Stack_p theStack)
{
    if(is_empty(theStack) || theStack == NULL)
    {
        return 0;
    }
    printf("%d ",theStack->arr[theStack->top]);
    theStack->top--;
}

int func(Stack_p theStack,int a)
{
    if(a==0)
    {
        push(theStack,0);
        return 0;
    }
    push(theStack,a%8);
    return func(theStack,a/8);
}
int main()
{
    Stack_p theStack = stack_init(5);
//    func(theStack,123);
    int n = 123;
    do
    {
        push(theStack,n%8);
        if(n==0)
        {
        break;
        }
        n = n/8;
        
    }while(1);
    int n1 = theStack->top;
    for(int i=0;i<=n1;i++)
    {
        pop(theStack);
    }

    return 0;
}

