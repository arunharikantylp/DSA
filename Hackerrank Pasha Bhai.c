#include <limits.h>
#include <stdio.h>
#include<stdbool.h>

int gra[1003][1003],n;


int mink(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index,v;

    for ( v = 1; v <= n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void printSolution(int dist[], int n)
{
    int i;
    for ( i = 2; i <=n; i++)
        if(dist[i]==INT_MAX)
        {
            printf("INF ");
        }
        else
        {
            printf("%d ",dist[i]);
        }
}


void dijkstra( int src)
{
    int dist[1003],i,count,v,u;
    bool set[1003];
    for ( i = 1; i <=n; i++)
        dist[i] = INT_MAX, set[i] = false;

    dist[src] = 0;
    for (count = 1; count <= n - 1; count++) {
        u = mink(dist, set);
        set[u] = true;

        for ( v = 1; v <= n; v++)
            if (!set[v] && gra[u][v] && dist[u] != INT_MAX
                && dist[u] + gra[u][v] <= dist[v])
                dist[v] = dist[u] + gra[u][v];
    }


    printSolution(dist, n);
}


int main()
{
int m,i,j,a,b,w;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
           gra[i][j]=0;
       }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        gra[a][b]=w;
    }

    dijkstra(1);
  return 0;
}
