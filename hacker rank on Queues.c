
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Queue
{
    int elements[MAX];
    int front,rear;

};
void initQueue(struct Queue *p);
void Enqueue(struct Queue *p,int n);
int getfront(struct Queue *p);
int Dequeue(struct Queue *p);
void display(struct Queue *p);
int isFull(struct Queue *p);
int isEmpty(struct Queue *p);
int size(struct Queue *p);
void sel_cand(struct Queue *p,struct Queue *a[1]);
int main()
{
    struct Queue p;
    int n,i,e,ch,x,Qno;
    initQueue(&p);
  while(1)
  {
    printf("\n1.EnQueue\n2.DeQueue\n3.Display\n4.Getfront\n5.Size\n6.To display selected candidates\n7.Exit\n");

      printf("\nEnter the Choice\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:x=isFull(&p);
                 if(x==1)
                 {
                     printf("Q is Full\n");
                 }
                 else
                 {
                     printf("Enter the height of the candidate\n");
                     scanf("%d",&e);
                     if(e>100 && e<200)
                     {
                         Enqueue(&p,e);
                     }
                     else
                    {
                printf("Invalid Input\n");
                 }
                 }
                 break;
         case 2:x=isEmpty(&p);
                 if(x==1)
                 {
                     printf("Q is Empty\n");
                 }
                 else
                 {
                    x=Dequeue(&p);
                    printf("The value to be D Queued is %d\n",x);
                 }
                 break;
         case 3:display(&p);
                break;
        case 4:x=isEmpty(&p);
                if(x==1)
                    printf("Q is Empty\n");
                else
                {
                    x=getfront(&p);
                    printf("Get front is %d\n",x);
                }
                break;
        case 5:x=size(&p);
               printf(" SIZE is %d\n",x);
               break;
        case 6:sel_cand(&p,&p);
               break;
        case 7:exit(0);

      }
  }

}
void initQueue(struct Queue *p)
{
    p->front=-1;
    p->rear=-1;
}
int isFull(struct Queue *p)
{
    if(p->rear==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(struct Queue *p)
{
    if(p->front==-1)
        return 1;
    else if((p->front)>(p->rear))
            return 1;
    else
        return 0;
}
void Enqueue(struct Queue *p,int n)
{
    p->rear++;
    p->elements[p->rear]=n;
    if(p->front==-1)
        p->front=0;
}
int Dequeue(struct Queue *p)
{
    int e=p->elements[p->front];
    p->front++;
    return e;
}
void display(struct Queue *p)
{
    int i;
    for(i=p->front;i<=p->rear;i++)
    {
        printf("%d\t",p->elements[i]);
    }
}
int getfront(struct Queue *p)
{
    return p->elements[p->front];
}
int size(struct Queue *p)
{

    if(p->front==-1)
        return 0;
    else
        return (p->rear)-(p->front)+1;
}
void sel_cand(struct Queue *p,struct Queue *a[1])
{
   int i,s,m;
   initQueue(&a[1]);
   s=size(&p);
   printf("%d",s);
   int j=0;
   int k=2;
   for(i=1;i<(s-1);i++)
   {
       if(j!=(s-4) && k!=s)
      {

      if(p->elements[0]>=150)
       {
           Enqueue(&a[1],p->elements[0]);
       }
       else if((p->elements[i])>(p->elements[j]) && (p->elements[i])<(p->elements[k]) && (p->elements[i]>=150))
       {
           Enqueue(&a[1],p->elements[i]);
           j++;
           k++;
       }
       else if((p->elements[s-1])>=150)
       {
           Enqueue(&a[1],p->elements[s-1]);
       }
   }
   }
   printf("\n\nInitial Candidates are \t");
   display(&p);
   printf("\nSelected Candidates are\t");
   display(&a[1]);
   printf("\n\n");
   m=size(&a[1]);
   printf("The Number of selected candidates is %d",m);
}




