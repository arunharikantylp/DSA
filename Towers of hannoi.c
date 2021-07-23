#include<stdio.h>
int main()
{
    int n;
    printf("enter the value of n");
    scanf("%d",&n);
    TOH(n,'s','a','d');
}
void TOH(int n,char source,char aux,char dest)
{
    if(n==0)
        return;
    TOH(n-1,source,dest,aux);
    printf("\n move disk \t%d from\t%c to\t%c",n,source,dest);
    TOH(n-1,aux,dest,source);
}
