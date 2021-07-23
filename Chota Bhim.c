#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define infinite 10000

int** Graph(int );
int Distance_min(int *,int *,int);
void DJ(int **,int ,int ,int);

int main()
{
  int t,**kj,n,s,i,d;
  scanf("%d",&t);

  for(i=0;i<t;i++)
  {
  scanf("%d",&n);

  kj=Graph(n);
  scanf("%d%d",&s,&d);

  DJ(kj,n,s,d);
  }
}

int** Graph(int n)
{
  int i,j,v1,v2,w=0,e;

  int **kj=malloc(n*sizeof(int *));
  for(i=0;i<n;i++)
    *(kj+i)=malloc(n*sizeof(int));


  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
        *(*(kj+i)+j)=-1;
  }
  scanf("%d",&e);
  for(i=0;i<e;i++)
  {
    scanf("%d%d",&v1,&v2);
    *(*(kj+v1-1)+v2-1)=w;
    *(*(kj+v2-1)+v1-1)=1;
  }
  return(kj);
}

void DJ(int **mat,int n,int s,int d)
{
  int c[n],v[n],i,u,j;
  s=s-1;

  for(i=0;i<n;i++)
  {
    if(i==s)
        c[i]=0;
    else
        c[i]=infinite;
    v[i]=0;
  }

  for(i=0;i<n-1;i++)
  {
     u=Distance_min(c,v,n);

     v[u]=1;

     for(j=0;j<n;j++)
     {
         if(*(*(mat+u)+j) != -1 && v[j] == 0)
         {
             if(*(*(mat+u)+j) + c[u] < c[j])
                c[j] = c[u] + *(*(mat+u)+j);
         }
     }
  }

  if(c[d-1] == infinite)
    printf("-1\n");
  else
    printf("%d\n",c[d-1]);
}

int Distance_min(int *c,int *v,int n)
{
  int i,ind,min;
  for(i=0;i<n;i++)
    {
        if(v[i]==0)
            break;
    }
  ind=i;
  min=c[i];
  i += 1;
  for(;i<n;i++)
      if(v[i]==0)
      {
          if(c[i]<min)
          {
              ind=i;
              min=c[i];
          }
      }
  return(ind);
}
