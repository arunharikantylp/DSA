#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100
struct edge
{
    int src;
    int dest;
    int wt;
};
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

struct subset
{
    int rank;
    int parent;
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

void cmp(const void *a,const void *b)
{
    struct edge *p=(struct edge *)a;
    struct edge *q=(struct edge *)b;
    return p->wt - q->wt;
}
void initsubset(struct subset s[],int v)
{
    int i;
    for(i=0;i<v;i++)
    {
        s[i].parent=i;
        s[i].rank=0;
    }
}
int find(struct subset s[],int i)
{
    if(s[i].parent!=i)
        s[i].parent=find(s,s[i].parent);
    return s[i].parent;
}
void Union(struct subset s[], int m, int n)
{
	int mroot = find(s,m);
	int nroot = find(s,n);

	if(mroot != nroot)
	{
		//Attach the tree which has lower rank to Higher rank and make parent
		//of lower rank tree same as parent of higher rank tree
		if(s[mroot].rank < s[nroot].rank)
			s[mroot].parent = nroot;

		else if(s[nroot].rank < s[mroot].rank)
			s[nroot].parent = mroot;

		else
		{
			s[nroot].parent = mroot;
			s[mroot].rank++;
		}
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
void deleteGraph(struct Graph G[])
{
	int i;
	for(i=0;i<MAX;i++)
	{
		struct node *p = G[i].head;
		while(p!=NULL)
		{
			G[i].head=p->next;
			free(p);
			p = G[i].head;
		}
	}
}
void display(struct edge e[], int n)
{
	int i;
	int sum = 0;
	printf("The following edges are selected in kruskal's MST \n");


	for(i=0;i<n;i++)
	{
		printf("%d --> %d with weight %d\n",e[i].src,e[i].dest,e[i].wt);
		sum+=e[i].wt;
	}
	printf("Minimum cost spanning tree is %d\n",sum);
}
void kruskal(struct Graph G[], int v)
{
	struct subset s[MAX];
	initsubset(s,v);

	struct edge e[MAX];
	struct edge output[MAX];

	int i = 0, j=0, k=0;
	int x, y;

	struct node *p;

	//Take all Edges and store it in an array
	for(i=0;i<v;i++)
	{
		p = G[i].head;
		while(p!=NULL)
		{
			e[j].src = i;
			e[j].dest = (p->data).v;
			e[j].wt = (p->data).wt;
			j++;
			p=p->next;
		}
	}

	//sort the array e (edges array)
	qsort(e, j, sizeof(struct edge), cmp);

	//Kruskal
	for(i=0;i<j;i++)
	{
		x = find(s, e[i].src);
		y = find(s, e[i].dest);

		if(x!=y)
		{
			output[k]=e[i];
			k++;
			Union(s, x, y);
			if(k==v-1)
				break;
		}
	}

	//Display the output array
	display(output, k);
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
    kruskal(G,v);
    deleteGraph(G);

return ;
}

