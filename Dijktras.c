#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100
int pos[MAX];
int available[MAX];
struct vertex
{
    int v;
    int wt;
};
struct node
{
    struct vertex data;
    struct node *next;
};
struct Heap
{
    struct vertex a[MAX];
    int size;
};
struct Graph
{
    struct node *head;
    struct node *last;
};

void initGraph(struct Graph G[])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        G[i].head=NULL;
        G[i].last=NULL;
    }
}
void addEdge(struct Graph G[],int src,int dest,int wt)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data.v=dest;
    p->data.wt=wt;
    p->next=NULL;
    if(G[src].head==NULL)
        G[src].head=p;
    else
        G[src].last->next=p;
    G[src].last=p;
}

void initheap(struct Heap *h)
{
    h->size=0;
}
void insertkey(struct Heap *h,struct vertex key)
{
    h->a[h->size]=key;
    h->size++;
    int i=h->size-1;
    while(i!=0 && h->a[i].wt < h->a[(i-1)/2].wt)
    {
        swap(&h->a[i],&h->a[(i-1)/2]);
        swapint(&pos[i],&pos[(i-1)/2]);
        i=(i-1)/2;
    }
}
void decresekey(struct Heap *h,int i,int k)
{
    if(i>=h->size)
        return;
    if(k>h->a[i].wt)
        return;
    h->a[i].wt=k;
     while(i!=0 && h->a[i].wt < h->a[(i-1)/2].wt)
    {
        swap(&h->a[i],&h->a[(i-1)/2]);
        swapint(&pos[h->a[i].v],&pos[h->a[(i-1)/2].v]);
        i=(i-1)/2;
    }
}
int isempty(struct Heap *h)
{
    return h->size==0;
}
struct vertex extractmin(struct Heap *h)
{
    struct vertex m = h->a[0];
    h->a[0]=h->a[h->size-1];
    available[m.v]=0;
    int x=(h->a[0]).v;
    pos[x]=0;
    h->size--;
    heapify(h,0);
    return m;
}
void heapify(struct Heap *h,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int min=i;
    if(left < h->size && h->a[left].wt < h->a[min].wt)
        left=min;
     if(right < h->size && h->a[right].wt < h->a[min].wt)
        right=min;
    if(min!=i)
    {
        swap(&h->a[i],&h->a[min]);
        swapint(&pos[h->a[i].v],&pos[h->a[min].v]);
        heapify(h,min);
    }
}
void swap(struct vertex *a,struct vertex *b)
{
    struct vertex temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swapint(int *a,int *b)
{
    int *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void print(int distance[],int vertex,int source)
{
    int i;
    for(i=0;i<vertex;i++)
    {
        printf("%Distance from %d to %d is %d\n",source,i,distance[i]);
    }
}
void dijktras(struct Graph G[],int vertex,int source)
{
    int i,j,d,v,dest,destwt,index;
    int distance[MAX];
    struct vertex u;
    struct Heap h;
    initheap(&h);
    for(i=0;i<MAX;i++)
    {
        u.v=i;
        u.wt=INT_MAX;
        insertkey(&h,u);
        available[i]=1;
        pos[i]=1;
    }
    decresekey(&h,pos[source],0);
    while(!isempty(&h))
    {
        u=extractmin(&h);
        d=u.wt;
        v=u.v;
        distance[v]=d;
        struct node *p=G[v].head;
        while(p!=NULL)
        {
            dest=p->data.v;
            destwt=p->data.wt;
            index=pos[dest];

            if(available[dest] && d+destwt < h.a[index].wt)
            {
                decresekey(&h,index,d+destwt);
            }
            p=p->next;
        }
    }
    print(distance,vertex,source);
}
int main()
{
    struct Graph G[MAX];
    initGraph(G);
    int i,j,v,e,dest,wt,src;
    printf("Enter the Vertices\n");
    scanf("%d",&v);
    for(i=0;i<v;i++)
    {
        printf("Enter the no.of edges from %d",i);
        scanf("%d",&e);
        for(j=0;j<e;j++)
        {
            printf("Enter destination\n");
            scanf("%d",&dest);
            printf("Enter weight\n");
            scanf("%d",&wt);
            addEdge(G,i,dest,wt);
        }
    }
    printf("Enter the Source\n");
    scanf("%d",&src);
    dijktras(G,v,src);
return ;
}
