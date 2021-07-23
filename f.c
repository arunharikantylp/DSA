#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* insert_f(struct node* head,int item);
struct node* getnode(int item);
void display(struct node* head);
int main()
{
    struct node* head=NULL;
    int ch,e,x;
    while(1)
    {
        printf("Enter\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("No.\n");
                   scanf("%d",&e);
                   insert_f(head,e);
                   break;
            case 2:display(head);
                   break;

        }
    }
}
struct node* getnode(int item)
{
 struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("not created");
        exit(0);

    }
    t->next=NULL;
    return t;
}
struct node* insert_f(struct node* head,int item)
{
   struct node* c;
    c=getnode(item);
    c->data=item;
    c->next=NULL;
    if(head==NULL)
    {
        return c;
    }
    c->next=head;
    return c;

}
void display(struct node* head)
{
   struct node* t;
    t=head;
    if(head==NULL)
    {
        printf("empty list");
        return;
    }
    printf("element are\n");
    t=head;
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");

}
