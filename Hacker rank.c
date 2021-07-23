#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* node;
node getnode();
void display(node head);
node insert_rear(node head,int item);
node insert_pos(node head,int n);
 int count(node head);
int main()
{
    node head=NULL;
    int n1,n2,x,item,ch;
    printf("Enter n1\n");
    scanf("%d",&n1);
    head=insert_rear(head,n1);
    printf("Enter n2\n");
    scanf("%d",&n2);
    head=insert_rear(head,n2);


    while(1)
    {
        printf("1.Insert a compartment\n2.Count\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the Id of compartment\n");
                   scanf("%d",&item);
                   if(item>-1)
                   {
                       head=insert_pos(head,item);
                       display(head);
                       break;
                   }
                   else
                   {
                       display(head);
                       exit(0);
                   }
            case 2:x=count(head);
                   printf("No. of elements are %d\n",x);
                   break;

        }
    }

}
node insert_rear(node head,int item)
{
    node c,t;
    t=getnode();
    t->data=item;
    c=head;
    if(head==NULL)
    {
        return t;
    }
    while(c->next!=0)
    {
        c=c->next;
    }
    c->next=t;
    return head;

}
node getnode()
{
    node t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("not created");
        exit(0);

    }
    t->next=NULL;
    return t;
}
void display(node head)
{
    node t;
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
node insert_pos(node head,int n)
{
    node cur,follow,t,p;
    int pos,i;
    cur=head;
    follow=head;
    p=head;
    int count=0;
    t=getnode();
    t->data=n;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    pos=(count)/2;
    for(i=0;i<pos && cur!=NULL;i++)
    {
        follow=cur;
        cur=cur->next;
    }

    follow->next=t;
    t->next=cur;
return head;
}
 int count(node head)
{
    node p;
    p=head;
    int count=0;
    if(head==NULL)
    {
        return NULL;
    }
    for(p=head;p!=NULL; p=p->next)
    {
        count++;

    }
    return count;
}

