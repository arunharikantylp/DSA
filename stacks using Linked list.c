#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};
void push(struct stack *s,int item);
void display(struct stack *s);
void pop(struct stack *s);
int empty(struct stack *s);
int full(struct stack *s);
int main()
{
    struct stack s;
    int n,ch,m;
    s.top=NULL;
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
            case 2:display(&s);
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
   struct node *q;
   q=(struct node *)malloc(sizeof(struct node));
   q->data=item;
   q->next=s->top;
   s->top=q;
}
void pop(struct stack *s)
{
    struct node *q;
    q=s->top;
    s->top=q->next;
    int v=q->data;
    printf("\n\n[Data to be Deleted: %d]\n\n",v);
    free(q);

}
int empty(struct stack *s)
{
    if(s->top==NULL)
    {
       return 1;
    }
    return 0;
}
int full(struct stack *s)
{
    return 0;
}
void display(struct stack *s)
{
    struct node* q;
    q=s->top;
    while(q!=NULL)
    {
        printf("\t%d\t\t",q->data);
        q=q->next;
    }
}



