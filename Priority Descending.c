#include<stdio.h>
#include<stdlib.h>
#define MAX 3
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
        int j=p->rear-1;
        while(j>=0 && n> (p->elements[j]))
        {
            p->elements[j+1]=p->elements[j];
            j--;
        }
        p->elements[j+1]=n;
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


