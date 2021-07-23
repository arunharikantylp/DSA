#include<stdio.h>
#include<stdlib.h>
#define MAX 5
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
int main()
{
    struct Queue p;
    int n,e,ch,x;
  initQueue(&p);
  while(1)
  {
            printf("\n1.EnQueue\n2.DeQueue\n3.Display\n4.Getfront\n5.Size\n7.Exit\n");

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
                     printf("Enter the value\n");
                     scanf("%d",&e);
                    Enqueue(&p,e);
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
    if((p->rear+1)%MAX==p->front)
        return 1;
    else
        return 0;
}
int isEmpty(struct Queue *p)
{
    if(p->front==-1)
        return 1;
    else
        return 0;
}
void Enqueue(struct Queue *p,int n)
{
    p->rear=(p->rear+1)%MAX;
    p->elements[p->rear]=n;
    if(p->front==-1)
        p->front=0;
}
int Dequeue(struct Queue *p)
{
    int e=p->elements[p->front];
    if(p->front==p->rear)
        p->front=p->rear=-1;
    else
    p->front=(p->front+1)%MAX;
    return e;
}
void display(struct Queue *p)
{
    int i;
    struct Queue *d;
    d=p->front;
    for(i=d;i!=p->rear;i=(i+1)%MAX)
    {
        printf("%d\t",p->elements[i]);
    }
    if(i!=-1)
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
    else if((p->rear)>(p->front))
        return (p->rear)-(p->front)+1;
        else
        {
            return (MAX-(p->front))+(p->rear+1);
        }
}

