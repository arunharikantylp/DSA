#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
    char name[20];
    int id;
    int age;
    struct employee *next;
};
typedef struct employee *node;
node getnode();
node emp_beg(node head,char name[20],int id,int age);
node emp_id(node head,int id);
void display(node head);
void emp_ret(node head,int age);
int main()
{
    node head=NULL;
    int ch,id,age,x;char name[20];
    while(1)
    {
        printf("Enter the operations\n");
        printf("1 for Add a new employee at beginning\n2 for Print an employee data whose employee id is given\n3 for Display\n4 for Count the no. of employee is near to retirement\n 5 for exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
       case 1:printf("Enter the details\n");
              printf("Name\tID\tAge\n");
              scanf("%s%d%d",name,&id,&age);
              head=emp_beg(head,name,id,age);
              break;
       case 2:printf("Enter the ID\n");
              scanf("%d",&id);
              head=emp_id(head,id);
              break;
       case 3:display(head);
              break;
       case 4:printf("Enter the Age\n");
              scanf("%d",&age);
              emp_ret(head,age);
              break;

        }
    }

}
node getnode()
{
    node t;
    t=(node)malloc(sizeof(node));
    if(t==NULL)
    {
        printf("Node is not created\n");
        exit(0);
    }
    t->next=NULL;
    return t;
}
node emp_beg(node head,char name[20],int id,int age)
{
    node t;
    t=getnode();
    strcpy(t->name,name);
    t->id=id;
    t->age=age;
    if(head==NULL)
    {
        return t;
    }
    t->next=head;
    head=t;
    return t;
}
node emp_id(node head,int id)
{
    node t;
    char name;int age;
    t=head;
    if(head==NULL)
    {
        printf("Empty list");
        return 0;

    }
    while(t!=NULL)
    {
        if(t->id==id)
        {
            printf("\n%s\n%d\n%d\n",t->name,t->id,t->age);
        }
        t=t->next;
    }
    return t;
}
void display(node head)
{
    node t;char name[20];int age,id;
    t=head;
     if(head==NULL)
    {
        printf("Empty list\n");
        return;

    }
    while(t!=NULL)
    {
        printf("\n");
        printf("%s\n%d\n%d\n",t->name,t->id,t->age);
        printf("\n");
        t=t->next;
    }
}
void emp_ret(node head,int age)
{
    node t;
    t=head;
    int count;
    count=0;
    while(t!=NULL)
    {
        if((t->age)>=58 && (t->age)<=60)
        {
            count++;
        }
        t=t->next;
    }
     printf(" \n%d Employess are near to retirement\n",count);
}
