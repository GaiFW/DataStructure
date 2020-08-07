#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int* Datatype;

typedef struct
{
    Datatype arr;
    int size;
    int top;
}Stack,*Stack_p;

Stack_p stack_init(int size)
{
    Stack_p theStack = (Stack_p)malloc(sizeof(Stack));
    if(theStack!=NULL)
    {
        theStack->arr = (Datatype)malloc(sizeof(Datatype)*size);
        if(theStack->arr != NULL)
        {
            memset(theStack->arr,0,size);
            theStack->size = size;
            theStack->top = -1;
            return theStack;
        }
        perror("theStack->arr");
        return NULL;
    }
    perror("theStack");
    return NULL;
}

bool is_empty(Stack_p theStack)
{
    return theStack->top==-1;
}

bool is_full(Stack_p theStack)
{
    return theStack->top == theStack->size-1;
}

void display(Stack_p theStack)
{
    for(int i=0;i<=theStack->top;i++)
    {
        printf("%d ",theStack->arr[i]);
    }
    printf("\n");
}
int main()
{

    int size=0;
    printf("size:");
    scanf("%d",&size);
    
    Stack_p theStack =  stack_init(size);  
    for(int i=0;i<size;i++)
    {
        theStack->arr[i]=i+1;
        theStack->top++;
    }
    display(theStack);
    if(is_empty(theStack))
    {
        printf("the Stack is empty!\n");
    }
    else if(is_full(theStack))
    {
        printf("the Stack is full!\n");
    
    }


    return 0;
}

