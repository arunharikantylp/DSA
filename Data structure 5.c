#include<stdio.h>
#include<stdlib.h>
struct complex
{
    int real;
    int complex;
};
struct complex read();
void display(struct complex p,struct complex q);
void add(struct complex p,struct complex q);
int main()
{
    struct complex p,q;
    printf("Enter the values of p and q\n");
    p=read();
    q=read();
    add(p,q);

}
struct complex read()
{
struct complex a;
    scanf("%d\n%d\n",&a.real,&a.complex);
    return a;
};

void add(struct complex p,struct complex q)
{
    int add,sum;
    add=p.real+q.real;
    sum=p.complex+q.complex;
    printf("Answer=%d+%di",add,sum);
}
