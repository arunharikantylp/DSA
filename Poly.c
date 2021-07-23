 #include<stdio.h>
#include<stdlib.h>
struct polynomial
{
    int co;
    int pow;
};
struct node
{
    struct polynomial data;
    struct node *next;
};
void read_polynomial(struct node** head);
int add_atBeg(struct node **head,struct polynomial e);
void sort(struct node *head);
void read_polynomial(struct node** head);
struct node *getnode(struct polynomial e);
struct node* addpolynomial(struct node *p1,struct node *p2);
void display(struct node *p);
int main()
{
    struct node *p1=NULL;
    struct node *p2=NULL;
    struct node *res=NULL;
    printf("Enter the 1st polynomial\n");
    read_polynomial(&p1);
    printf("Enter the 2nd polynomial\n");
    read_polynomial(&p2);
    res=addpolynomial(p1,p2);
    display(res);

}
void read_polynomial(struct node** head)
{
    struct polynomial e;
    int c;
    do
    {
        printf("Enter the coefficient\n");
        scanf("%d",&e.co);
        printf("Enter the Pow\n");
        scanf("%d",&e.pow);
        add_atBeg(head,e);
        printf("Do you want to continue press 1\n");
        scanf("%d",&c);
    }while(c==1);
}
int add_atBeg(struct node **head,struct polynomial e)
{
    struct node *q=getnode(e);
    if(head==NULL)
        return q;
    q->next=*head;
    *head=q;
    return 0;

}
struct node *getnode(struct polynomial e)
{
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    if(q!=NULL)
    {
        q->data=e;
        q->next=NULL;
    }
    return q;
}
void sort(struct node *head)
{
    struct node *i;
    struct node *j;
    struct polynomial temp;
    for(i=head;i!=NULL;i=i->next)
    {
        for(j=head;j->next!=NULL;j=j->next)
        {
            if((j->data).pow>(j->next->data).pow)
            {
                temp=j->data;
                j->data=j->next->data;
                j->next->data=temp;
            }
        }
    }
}
struct node* addpolynomial(struct node *p1,struct node *p2)
{
    struct node *res=NULL;
    struct polynomial temp;
    sort(p1);
    sort(p2);
    while(p1!=NULL && p2!=NULL)
    {
        if((p1->data).pow==(p2->data).pow)
           {
               temp.co=(p1->data).co+(p2->data).co;
               temp.pow=(p1->data).pow;
               add_atBeg(&res,temp);
               p1=p1->next;
               p2=p2->next;
           }
           else if((p1->data).pow<(p2->data).pow)
            {
                add_atBeg(&res,p1->data);
                p1=p1->next;
            }
            else
            {
                add_atBeg(&res,p2->data);
                p2=p2->next;
            }
    }
    while(p1!=NULL)
    {
         add_atBeg(&res,p1->data);
                p1=p1->next;
    }
     while(p2!=NULL)
    {
         add_atBeg(&res,p2->data);
                p2=p2->next;
    }
    return res;
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d.x^%d +",(p->data).co,(p->data).pow);
        p=p->next;
    }
    printf("\b ");n
}
