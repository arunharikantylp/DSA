#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front;
    struct node *rear;
};
initqueue(struct queue *q)
{
    q->front=q->rear=NULL;
}

void enqueue(struct queue *q,int e)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=e;
    p->next=NULL;
    if(q->rear == NULL)
    {
        q->front=q->rear=p;
    }
    else
    {
        q->rear->next=p;
        p=q->rear;

    }
}
int dequeue(struct queue *q)
{
    int e;
    struct node *p=q->front;
    e=p->data;
    q->front=p->next;
    free(p);
    if(q->front==NULL)
        q->rear=NULL;
    return e;
}
int isempty(struct queue *q)
{
    if(q->front==NULL && q->rear==NULL)
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
    bfs(G,v,source);
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
void bfs(int G[4][4],int v,char source)
{
    int m,u,i;
    struct queue q;
    initqueue(&q);
    int visited[10]={0};
    m=source-65;
    printf("%c\t",source);
    enqueue(&q,m);
    visited[m]=1;
    while(!isempty(&q))
    {
        u=dequeue(&q);
        for(i=0;i<v;i++)
        {
            if(G[u][i]==1 && visited[i]==0)
            {
                enqueue(&q,i);
                visited[i]=1;
                 printf("%c\t",i+65);
            }
        }


    }


}
