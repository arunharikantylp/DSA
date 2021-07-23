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
struct stack *s;
int visited[10]={0};
void initstack(struct stack *s)
{
    s->top=NULL;
}
void push(struct stack *s,int e)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=e;
    p->next=NULL;
    if(s->top==NULL)
        s->top=p;
    else
    {
        p->next=s->top;
        s->top=p;
    }
}
void pop(struct stack *s)
{
    struct node *p=s->top;
    int e=s->top->data;
    s->top=s->top->next;
    free(p);
    return;

}
int peek(struct stack *s)
{
    return s->top->data;
}
int isempty(struct stack *s)
{
    if(s->top==NULL)
        return 1;
    else
        return 0;
}
int main()
{
    char source;
    int v=4;
    int G[4][4]={0,0,1,1,0,0,1,1,1,1,0,0,1,1,0,0};
    print(G,v);
    printf("Enter the source\n");
    scanf(" %c",&source);
    dfs(G,v,source);
}
void dfs(int G[4][4],int v,char source)
{
    int i;
    int visited[10]={0};
    int m=source-65;
    push(&s,m);
    visited[m]=1;
    printf("%c\t",m+65);

        while(!isempty(&s))
        {
            m=peek(&s);
            for(i=0;i<v;i++)
            {
                if(G[m][i]==1 && visited[i]==0)
                {
                    push(&s,i);
                    visited[i]=1;
                    printf("%c\t",65+i);
                    break;
                }
            }
            if(i==v)
            pop(&s);


        }
    }

void print(int G[4][4],int v)
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d\t",G[i][j]);
        }
        printf("\n");
    }
}
