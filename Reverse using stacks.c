#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100
struct stack
{
    int a[MAX];
    int top;
};
int top=-1;
int item;
char stack_string[MAX];
void pushChar(char item);
char popChar(void);
int isEmpty(void);
int isFull(void);

int main()
{
    char str[MAX];

    int i;

    printf("Input a string: ");
    scanf("%s",str);
   for(i=0;i<strlen(str);i++)
        pushChar(str[i]);

    for(i=0;i<strlen(str);i++)
        str[i]=popChar();

    printf("Reversed String is: %s\n",str);

    return 0;
}


void pushChar(char item)
{

    if(isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }


    top++;
    stack_string[top]=item;
}


 char popChar()
{

    if(isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }

    item = stack_string[top];
    top--;
    return item;
}


int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}


int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
