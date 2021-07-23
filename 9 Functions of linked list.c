#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node insert_front(int item,node head);
node getnode();
void display(node head);
node delete_front(node head);
node insert_last(int item,node head);
node delete_rear(node head);
int count(node head);
int search(node head);
int occurance(node head);
node insert_at_pos(node head,int item,int pos);
node delete_at_pos(node head,int pos);
node spec_pos(node head,int item);
node reverse(node head);
node del_pos(node head,int pos);
int main()
{
    node head=NULL;
    int ch,n;int key,s,pos,item;
    while(1)
    {
        printf("enter operation 1.insert front\n2.display\n3.delete_front\n4.insert_last\n5.delete_rear\n6.count\n7.search\n8.occurance\n9.spec_pos\n10.Reverse\n11.delete at position\n12.value\n13.exit");
        scanf("%d",&ch);

    switch(ch)
    {
        case 1:printf("enter the number\n");
               scanf("%d",&n);
               head=insert_front(n,head);
               break;
        case 2:printf("display contains\n");
               display(head);
               break;
        case 3:head=delete_front(head);
               break;
        case 4:printf("enter the number\n");
               scanf("%d",&n);
               head=insert_last(n,head);
               break;
        case 5:head=delete_rear(head);
               break;
        case 6:s=count(head);
               printf("no of elements are %d:",s);

               break;
        case 7:
               s=search(head);
               if(s==1)
               {
                   printf("element is searched");
               }
               else
                printf("element not found");
        case 8:occurance(head);
        break;
        case 9 :printf("enter the number\n");
               scanf("%d",&n);
               head=spec_pos(head,n);
               break;
        case 10:head=reverse(head);
                break;
        case 11:printf("Enter the position\n");
                scanf("%d",&pos);
                head=del_pos(head,pos);
                break;
        default:exit(0);
    }
}
}

node insert_front(int item,node head)
{
    node c;
    c=getnode();
    c->data=item;
    c->next=NULL;
    if(head==NULL)
    {
        return c;
    }
    c->next=head;
    head=c;
    return c;
}
node getnode()
{
    node t;
    t=(node)malloc(sizeof(node));
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
node delete_front(node head)
{
    node c;
    c=head;
    if(head==NULL)
    {
        printf("empty list\n");
        return head;
    }
    head=head->next;
    printf("%d node is deleted\n",c->data);
    free(c);
    return head;
}
node insert_last(int item,node head)
{
    node c,t;
    t=getnode();
    t->data=item;
    c=head;
    if(head==NULL)
    {
        printf("the list is empty\n");
        return head;
    }
    while(c->next!=0)
    {
        c=c->next;
    }
    c->next=t;
    return head;

}
node delete_rear(node head)
{
    node prev,c;
    if(head==NULL)
    {
        printf("empty list");
    }
    prev=NULL;
    c=head;
    while(c->next!=NULL)
    {
        prev=c;
        c=c->next;

    }
    if(c==head)
    head=NULL;
    if(prev!=NULL)
        prev->next=NULL;
    {
        printf("item deleted is %d\n",c->data);
        free(c);
        return head;

    }
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
int search(node head)
{
    node p;
    int key;
    p=head;
    printf("enter the element to be searched:");
               scanf("%d",&key);
    while(p!=NULL)
    {
        if(p->data==key)
            return 1;
        p=p->next;
    }
    return 0;
}
int occurance(node head)
{
    int count=0;
    node p=head;
    int key;
     printf("Enter the element");
               scanf("%d",&key);

    while(p!=NULL)
    {
        if(p->data==key)
            count++;
        p=p->next;
    }
    printf("the frequency of the element is %d",count);
}
node spec_pos(node head,int item)
{
    node c,prev,t;
    int pos;
     printf("enter the pos\n");
               scanf("%d",&pos);
    int count=0;
    t=getnode();
    t->data=item;
    prev=NULL;
    c=head;
    while(c!=NULL && pos!=count)
    {
        prev=c;
        c=c->next;
        count++;
    }
    prev->next=t;
    t->next=c;
return head;
}

node reverse(node head)
{
    node p;
    node q;
    node r;
    p=head;
    if(p!=NULL)
        q=p->next;
    if(q!=NULL)
        r=q->next;
    while(q!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        if(r!=NULL)
            r=r->next;
    }
    if(head!=NULL)
        head->next=NULL;
    head=p;
    return head;

}
node del_pos(node head,int pos)
{
    node cur,follow;
    cur=head;
    follow=head;

    int i;
    if(head==NULL)
    {
        printf("Empty list\n");
        exit(0);
    }

    for(i=1;i<pos && cur->next!=NULL ;i++)
    {
        follow=cur;
        cur=cur->next;
    }
    follow->next=cur->next;

    free(cur);
    return head;
}


