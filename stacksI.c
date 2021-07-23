#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int a[4];
    int top;
};
void push(struct stack *s,int item);
void display(struct stack s);
void pop(struct stack *s);
int empty(struct stack *s);
int full(struct stack *s);
int main()
{
    struct stack s;
    int n,ch,m;
    s.top=-1;
    while(1)
    {
        printf("\n1.PUSH\n\n2.Display\n\n3.POP\n\n4.IS empty\n\n5.IS full\n\n6.exit\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the value to be Pushed\n\n");
                   scanf("%d",&n);
                   push(&s,n);
                   break;
            case 2:display(s);
                   break;
            case 3:pop(&s);
                   break;
            case 4:m=empty(&s);
                   if(m==1)
                   {
                       printf("\nStack is Under Flow\n\n");
                   }
                   else
                   {
                       printf("\nYou can do Operation\n\n");
                   }
                   break;
            case 5:m=full(&s);
                   if(m==1)
                   {
                       printf("\nStack is Over Flow\n\n");
                   }
                   else
                   {
                       printf("\nYou can do Operation\n\n");
                   }
                   break;
             case 6:exit(0);
        }
    }
}
void push(struct stack *s,int item)
{
    s->top++;
    s->a[s->top]=item;
}
void display(struct stack s)
{
    int i;
     printf("Entered numbers are\n\n");
    for(i=s.top;s.top>=0;(s.top)--)
    {
        printf("{%d}\t",s.a[s.top]);
    }
    printf("\n");
}
void pop(struct stack *s)
{
    int num;
    num=s->a[s->top];
    printf("\nElement {%d} to be popped\n\n",num);
    (s->top)--;
}
int empty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int full(struct stack *s)
{
    if(s->top>=(4-1))
        return 1;
    else
        return 0;
}
