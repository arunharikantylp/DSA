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
void prio(struct Queue *p,struct Queue *a[1],struct Queue *b[2]);
int main()
{
    struct Queue p[3];
    int n,i,e,ch,x,Qno;
    initQueue(&p[0]);
    for(i=1;i<3;i++)
    {
       initQueue(&p[i]);
    }
  while(1)
  {
    printf("\n1.EnQueue\n2.DeQueue\n3.Display\n4.Getfront\n5.Size\n6.To create to Queue\n7.Exit\n");

      printf("\nEnter the Choice\n");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1:x=isFull(&p[0]);
                 if(x==1)
                 {
                     printf("Q is Full\n");
                 }
                 else
                 {
                     printf("Enter the value\n");
                     scanf("%d",&e);
                     if(e<0 || e>100)
                     {
                         printf("Invalid Input\n");
                     }
                     else
                    {
                    Enqueue(&p[0],e);
                 }
                 }
                 break;
         case 2:x=isEmpty(&p[0]);
                 if(x==1)
                 {
                     printf("Q is Empty\n");
                 }
                 else
                 {
                    x=Dequeue(&p[0]);
                    printf("The value to be D Queued is %d\n",x);
                 }
                 break;
         case 3:display(&p[0]);
                break;
        case 4:x=isEmpty(&p[0]);
                if(x==1)
                    printf("Q is Empty\n");
                else
                {
                    x=getfront(&p[0]);
                    printf("Get front is %d\n",x);
                }
                break;
        case 5:x=size(&p[0]);
               printf(" SIZE is %d\n",x);
               break;
        case 6:prio(&p[0],&p[1],&p[2]);
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
void prio(struct Queue *p,struct Queue *a[1],struct Queue *b[2])
{
    int i;
    for(i=p->front;i<=p->rear;i++)
    {
        if(p->elements[i]<60 && p->elements[i]>0 )
        {
            Enqueue(&p[1],p->elements[i]);
        }
         else if(p->elements[i]>=60 && p->elements[i]<100 )
        {
            Enqueue(&p[2],p->elements[i]);
        }
    }
    printf("\n\nInitial Queue is\t");
    display(&p[0]);
     printf("\nQueue 1 Less than 60 year\t");
    display(&p[1]);
    printf("\nQueue 2 Greater than 60 year\t");
    display(&p[2]);
    printf("\n\n");
    exit(0);

}


