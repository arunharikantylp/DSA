#include<stdio.h>
#include<stdlib.h>
void fib(int n,int a,int b);
int fib_n(int n);
int main()
{
    int n,ch,f;
   while(1)
   {
       printf("Enter the operations\n");
              printf("1.To print Fibonacci Series\n2.Find a no.at specified position\n3.Exit\n");

       scanf("%d",&ch);
       switch(ch)
       {
           case 1:
                   printf("Enter the n value\n");
                 scanf("%d",&n);
                  fib(n,-1,1);
                  break;
            case 2:printf("Enter the position\n");
                   scanf("%d",&n);
                   f=fib_n(n);
                  printf("At position %d element is %d\n",n,f);
                  break;
           case 3:exit(0);
       }
   }

}
void fib(int n,int a,int b)
{
    if(n>0)
    {
        printf("%d\t",a+b);
        fib(n-1,b,a+b);
    }
    printf("\n");
}

int fib_n(int n)
{
    int a,b;
    if(n==1)
    return 0;

    if(n==2)
    return 1;
     else
        {
        a=fib_n(n-1);
        b=fib_n(n-2);
        }
        return a+b;
}




