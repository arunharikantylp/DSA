#include<stdio.h>
#include<stdlib.h>
struct player
{
    char team_name[20];
    char p_n[20];
    int h_s;
};
void read(struct player a[10],int n);
void display(struct player a[10],int n);
void sort(struct player a[10],int n);
int max(struct player a[10],int n);
int main()
{
    struct player a[10];
    int n,S;
    printf("Enter the value of n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    sort(a,n);
    display(a,n);
    S=max(a,n);
    printf("\n%d",S);


}
void read(struct player a[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s%s%d",a[i].team_name,a[i].p_n,&a[i].h_s);
    }
}
void display(struct player a[10],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\n%s\n%s\n%d\n",a[i].team_name,a[i].p_n,a[i].h_s);
    }
}
void sort(struct player a[10],int n)
{
    int i,j;
    struct player temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j].h_s>a[j+1].h_s)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
int max(struct player a[10],int n)
{
    int i,M,position;
    M=a[0].h_s;
    for(i=0;i<n;i++)
    {
      if(a[i].h_s>M)
      {
          M=a[i].h_s;
      }

    }
    position=i;
    return position;
}
