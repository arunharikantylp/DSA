#include<stdio.h>
#define max 10
#define INF 9999
int main()
{
    int dist[max][max];
    int v,i,j;
    printf("Vertices Please\n");
    scanf("%d",&v);
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            scanf("%d",&dist[i][j]);

    floyd(dist,v);
    printsol(dist,v);


}

void floyd(int dist[max][max],int v)
{
    int i,j,k;
    for(k=0;k<v;k++)
{
     for(i=0;i<v;i++)
     {
         for(j=0;j<v;j++)
         {
             if(dist[i][k]+dist[k][j] < dist[i][j])
             {
                 dist[i][j]=dist[i][k]+dist[k][j];
             }


         }
     }

}

}

void printsol(int dist[max][max],int v)
{
   int i,j;
   for(i=0;i<v;i++)
   {
       for(j=0;j<v;j++)
       {
           if(dist[i][j] == INF)
           {
               printf("%7s","INF");
           }
           else
           {
               printf("%7d",dist[i][j]);
           }
       }
       printf("\n");
   }
}



