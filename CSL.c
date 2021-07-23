#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{char name[20];
int rno;
int sem;
};
struct node
{
struct student data;
struct node *next;
};
struct node *getnode(struct student e);
void readstudent(struct student *p);
 void deleteBeg(struct node **last);
int addAtBeg(struct node **last,struct student e);
int addAtRear(struct node **last,struct student e);
int addAtPos(struct node **last,struct student e,int pos);
void display(struct node *last);
void deleterear(struct node**last);
void delAtPos(struct node **last,int pos);
int main()
{
struct node *last=NULL;
int ch,x,pos;
struct student e;
while(1)
{printf("Enter 1.Add at Beginning\n2.for Display\n3.Add at Rear\n4.Add at given Position\n5.Delete at beginning\n6.delete rear\n.7.Delete at position\n8.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the Student Details\n");
        readstudent(&e);
        x=addAtBeg(&last,e);
        if(x==1)
        printf("Data added Succesfully\n");
        else
        printf("Memory Full\n");
        break;
case 2:display(last);
       break;
case 3:printf("Enter the Student Details\n");
        readstudent(&e);
        x=addAtRear(&last,e);
        if(x==1)
        printf("Data added Succesfully\n");
        else
        printf("Memory Full\n");
        break;
case 4:printf("Enter the Student Details\n");
        readstudent(&e);
        printf("Enter the position\n");
        scanf("%d",&pos);
        x=addAtPos(&last,e,pos);
        if(x==1)
        printf("Data added Succesfully\n");
        else
        printf("Memory Full\n");
        break;
case 5:if(last==NULL)
        printf("List is empty");
        else
            deleteBeg(&last);
       break;
case 6:if(last==NULL)
        printf("List is empty");
        else
            deleterear(&last);
       break;
case 7:if(last==NULL)
        printf("List is empty");
        else
       {
        printf("Enter the position\n");
        scanf("%d",&pos);
        delAtPos(&last,pos);
       }
       break;
case 8:exit(0);
}
}
}
int addAtBeg(struct node **last,struct student e)
{
struct node *q=getnode(e);
if(q==NULL)
return 0;
if(*last==NULL)
{*last=q;
(*last)->next=*last;
}
else
{q->next=(*last)->next;
(*last)->next=q;
}
return 1;
}
struct node *getnode(struct student e)
{struct node *q;
q=(struct node *)malloc(sizeof(struct node));
if(q!=NULL)
{q->data=e;
q->next=NULL;
}
return q;
}
void readstudent(struct student *p)
{
printf("Enter the name of the Student\n");
scanf("%s",p->name);
printf("Enter the Roll number of the Student\n");
scanf("%d",&p->rno);
printf("Enter the SEM of the Student\n");
scanf("%d",&p->sem);
}

void display(struct node *last)
{   struct node *p;
    if(last!=NULL)
    {
        struct node *p=last->next;
    do
    {
      printf("Name:%s\n",(p->data).name);
      printf("Roll No:%d\n",(p->data).rno);
      printf("SEM:%d\n",(p->data).sem);

      p=p->next;

    }while(p!=last->next);
    }
}
int addAtRear(struct node **last,struct student e)
{
struct node *q=getnode(e);
if(q==NULL)
return 0;
if(*last==NULL)
{*last=q;
(*last)->next=*last;
}
else
{q->next=(*last)->next;
(*last)->next=q;
*last=q;
}
return 1;
}
int addAtPos(struct node **last,struct student e,int pos)
{
    int x;
    if(*last==NULL || pos<=1)
    {
        x=addAtBeg(last,e);
        return x;
    }
    struct node *q=getnode(e);
    if(q==NULL)
        return 0;
    struct node *cur=(*last)->next;
    struct node *prev=(*last)->next;
    int i,flag=0;
    for(i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->next;
        if(cur==(*last)->next)
        {
            flag=1;
            break;
        }
    }
    prev->next=q;
    q->next=cur;
    if(flag==1)
        *last=q;
    return 1;
}
void deleteBeg(struct node **last)
{
    struct node*p=(*last)->next;
    (*last)->next=p->next;
    if(p==*last)
        *last=NULL;
    free(p);
}
void deleterear(struct node **last)
{
  struct node *p=(*last)->next;
  struct node *q=*last;
  while(p->next!=q)
  {
      p=p->next;
  }
  p->next=q->next;
  *last=p;
  if(*last==q)

      *last=NULL;
  free(q);
}
void delAtPos(struct node **last,int pos)
{
    if(pos=1)
    {
        deleteBeg(last);
        return ;
    }
    struct node *cur=(*last)->next;
    struct node *prev=(*last)->next;
    int i;
    for(i=1;i<pos && cur!=*last;i++)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=cur->next;
    if(cur==*last)
        free(cur);
}



