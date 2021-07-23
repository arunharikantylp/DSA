#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char b_name[100];
    char b_author[100];
    float b_price;
    struct node *link;
};
typedef struct node *node;
node root;
node getnode();
node add_f(node root);
void display(node root);
int count(node root);
node add_pos(node root);
void cheapest(node root);
void s_book(node root);

int main()
{
    node root=NULL;
    int ch,d;
    while(1)
    {
        printf("enter choice \n1=insert at first\n2=display list\n3=count the nodes\n4=add at specified positon\n5=to print cheapest book in list\n6=book with same name\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:root=add_f(root);
                  break;
        case 2:  display(root);
        break;
        case 3: d=count(root);
        break;
        case 4: root=add_pos(root);
        break;
        case 5: cheapest(root);
        break ;
        case 6: s_book(root);
        break;
        default : printf("invalid input\n");
        exit(0);
        }}}
        node getnode()
{
    node t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("node not created\n");
        exit(0);
    }
    t->link=NULL;
    return t;
}
node add_f(node root)
{
    node t;
    t=getnode();
    printf("enter the book name\t book author name\tbook price\n");
    scanf("%s%s%f",t->b_name,t->b_author,&t->b_price);
    if(root==NULL)
    {
        return t;
    }
    else
    {
        t->link=root;
        return t;
    }
}
void display(node root)
{
    node t=root;
    if(root==NULL)
    {
        printf("list is empty\n");

    }
    else
    {
        while(t!=NULL)
        {
            printf("book name=%s\tbook author=%s\tbook price%f\n",t->b_name,t->b_author,t->b_price);
            t=t->link;
        }
    }
    }
int count(node root)
{

    node t=root;
   int  c=0;
    while(t!=NULL)
    {
        c++;
        t=t->link;
    }
    printf("number of nodes are =%d\n",c);
    return c;

}
node add_pos(node root)
{
    node t,c=root,prev=NULL;
    int p=1,pos,k;
    t=getnode();
    k=count(root);
    printf("enter the book name\t book author name\tbook price\n");
    scanf("%s%s%f",t->b_name,t->b_author,&t->b_price);
    printf("enter the position\n");
    scanf("%d",&pos);
    if(k>=pos)
    {
    if(root==NULL)
    {
        printf("list is empty first enter one node inf\n");
    }
    while(c!=NULL&&p!=pos)
    {  prev=c;
        c=c->link;
        p++;
    }
    if(prev==NULL)
    {
        t->link=c;
        return t;
    }
    else
    {
        prev->link=t;
        t->link=c;
        return root;
    }
    }
    else
    {
        printf("there are only %d nodes in list",k);
    }

}
void cheapest(node root)
{
    node t=root;
    node r=NULL;
    float m=t->b_price;
    if(root==NULL)
    {
        printf("node is empty\n");
    }
    while(t!=NULL)
    {
        if(t->b_price<m)
        {
            m=t->b_price;
            r=t;
        }
        t=t->link;
    }
    if(r==NULL)
    {
        printf("cheapest price of book =%f\nbook name=%s\tbook author=%s\tbook price=%f",m,t->b_name,t->b_author,t->b_price);

    }
    else{
    printf("cheapest price of book =%f\nbook name=%s\tbook author=%s\tbook price=%f",m,r->b_name,r->b_author,r->b_price);
    }

}
void s_book(node root)
{
    node t=root;
    char hesar[100];
    int c=0;
    printf("enter the book name u want to search\n");
    scanf("%s",hesar);
    if(root==NULL)
    {
        printf("list is empty\n");
    }
    else{
            while(t!=NULL)
            {

                if(strcmp(t->b_name,hesar)==0)
                {
                    printf("book name=%s\tbook author=%s\tbook price=%f\n",t->b_name,t->b_author,t->b_price);
                    c++;
                }
                t=t->link;

            }
            if(c==0)
            {
                printf("there is no book in this name\n");
            }

    }
}
