#include<stdio.h>
#include<stdlib.h>
struct node
{ char data;
 struct node *next;
};
struct node *add_beg(char item,struct node **head);
struct node *add(char n1[],char n2[]);
void display(struct node** head);
int main()
{
struct node *res=NULL;
char n1[100];
char n2[100];
printf("Enter the first number\n");
scanf("%s",&n1);
printf("Enter the Second number\n");
scanf("%s",&n2);
res=add(n1,n2);
display(res);
}
struct node *add(char n1[],char n2[])
{
struct node *res=NULL;
struct node *a=NULL;
struct node *b=NULL;
int i,carry=0,e;
for(i=0;n1[i]!='\0';i++)
{
add_beg(&a,n1[i]);
}
for(i=0;n2[i]!='\0';i++)
{
add_beg(&b,n2[i]);
}

while(a!=NULL && b!=NULL)
{
   e=((a->data-48)+(b->data-48)+carry)%10;
   carry=((a->data-48)+(b->data-48)+carry)/10;
   add_beg(&res,e+48);
   a=a->next;
   b=b->next;
}
while(a!=NULL)
{
 e=((a->data-48)+carry)%10;
   carry=((a->data-48)+carry)/10;
   add_beg(&res,e+48);
   a=a->next;

}
while(b!=NULL)
{
 e=((b->data-48)+carry)%10;
   carry=((b->data-48)+carry)/10;
   add_beg(&res,e+48);
   b=b->next;

}
if(carry!=0)
{add_beg(&res,carry+48);
}
return res;



}
struct node* getnode()
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
struct node *add_beg(char item,struct node **head)
{
    struct node* c;
    c=getnode();
    c->data=item;
    c->next=NULL;
    if(head==NULL)
    {
        return c;
    }
    c->next=head;
    return c;
}
void display(struct node** head)
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

