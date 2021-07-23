#include<stdio.h>
#include<stdlib.h>
 struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node getnode();
node insert_front(int item,node head);
void display(node head);
node delete_front(node head);
node insert_rear(int item,node head);

 int main()
{
    int n,ch;
    node head=NULL;
    while(1)
    {
        printf("Enter the choice 1 for Insert front\n 2 for Display\n 3 for delete front\nand 4 also\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter the number");
                   scanf("%d",&n);
                   head=insert_front(n,head);
                   break;
            case 2:printf("Lists are");
                   display(head);
                   break;
            case 3:head=delete_front(head);
                   break;
            case 4:printf("Enter the number");
                   scanf("%d",&n);
                   head=insert_rear(n,head);
                   break;

        }
    }
    }

node getnode()
    {
        node t;
    t=(node)malloc(sizeof(struct NODE));
    if(t==NULL)
    {
        printf("Not created");
        exit(0);
    }
        t->next=NULL;
        return t;
    }
node insert_front(int item,node head)
{

    node t,c;
    t=getnode();
    t->data=item;
    t->next=NULL;
    if(head==NULL)
        return t;
    t->next=head;
    return t;
}
void display(node head)
{
    node t;
    if(head==NULL)
    {
        printf("Empty list");
    }
    printf("Elements are\n");
    t=head;
    while(t!=NULL)
    {
        printf("%d",t->data);
        t=t->next;
    }
    printf("\n");
}
node delete_front(node head)
{
    node t;
     t=head;
    if(head==NULL)
    {
        printf("List empty");
        return head;
    }
    else if(t->next==NULL)
    {
    printf("Item deleted is %d\n",t->data);
    free(t);
    head=NULL;
    }
    else
    {
    head=t->next;
    }
    return head;

}
node insert_rear(int item,node head)
{
     node t,c;
    t=getnode();
    t->data=item;
    if(head==NULL)
        return t;
        c=head;
        while(c->next!=NULL)
            c=c->next;
        c->next=t;
        return head;
}


