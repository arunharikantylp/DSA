#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
//1.Find the cheapest book
//2.add a new book in between the existing list and find the total number of books
//3.display all the books
struct BOOK{
	int price;
	char title[20];
	int copy;
	struct BOOK *next;
};

typedef struct BOOK *node;

node head;

node getnode()
{
	node t;
	t = (node) malloc(sizeof(struct BOOK));
	if(t == NULL)
	{
		printf("\nNode not created");
		exit(0);
	}
	t->next = NULL;
	return t;
}
node book_beg(node head,int price,char title[20],int copy)
{
    node t;
    t=getnode();
    t->price=price;
    strcpy(t->title,title);
    t->copy=copy;
    t->next=NULL;
    if(head==NULL)
    {
        return t;
    }
    t->next=head;
    head=t;
    return t;
}

node insert(node head, int position)
{
	node t, i;
	int count_t = 0;
	i = head;
	while(i != NULL)
	{
		i = i->next;
		count_t++;
	}
	printf("\nThe number of books are = %d\n", count_t);
	t = getnode();
	printf("\nEnter Title, price, and copy number");
	scanf("%s %d %d", t->title, &t->price, &t->copy);

	node c = head;
	node prev = NULL;
	int count  = 0;
	if(position == 1)
	{
		if(head == NULL)
			return t;
		t->next = head;
		return t;
	}

	while(c != NULL && count != position)
	{
		prev = c;
		c = c->next;
		count++;
	}


	prev->next = t;
	t->next = c;
	return head;
}

void display_same(node head)
{
	node c, t;
	c = head;/*
	char title_search[20];
	printf("\nEnter the title: ");
	scanf("%s", title_search);
	while(c != NULL)
	{
		if(strcmp(title_search, c->title) == 0)
		{
			printf("\nTitle: %s\tPrice: %d\tCopy: %d", c->title, c->price, c->copy);
		}
		c = c->next;
	}*/
	int f = 0;
	t = c->next;
	while(c!= NULL)
	{
		while(t!= NULL)
		{
			if(strcmp(t->title, c->title) == 0)
			{
				printf("\nThe book common title is = %s", t->title);
				f = 1;
				break;
			}
			t = t->next;
		}
		c = c->next;
	}
	if(f == 0)
		printf("\nNo common title");
}

void sortlib(node head)
{
 	node i = head;
 	int temp;
	int min = i->price;
 	for(i=head;i!=NULL;i=i->next)
 	{
		if(min < i->price)
			min = i->price;
	}
	i = head;
	while(i != NULL)
	{
		if(i->price == min)
		{
			printf("the cheapest book is %s whose price is %d copy= %d",i->title,i->price,i->copy);
			exit(0);
		}
	}

}
void display(node head)
{
    node t;
    char title[20];
    int copy;
    int price;
    t=head;
     if(head==NULL)
    {
        printf("Empty list\n");
        return;

    }
    while(t!=NULL)
    {
        printf("\n");
        printf("%f\n%s\n%d\n",t->price,t->title,t->copy);
        printf("\n");
        t=t->next;
    }
}


void main()
{
	node head;
	head = NULL;
	int ch, pos,copy;
	int price;
	char title[20];
	while(1)
	{   printf("\n1.Insert node at a specific front ");
        printf("\n2.Insert node at a specific position  ");
		printf("\n3.Search the cheapest book");
		printf("\n4.Display all the books having the same title\n");
		printf("\n5.Display");
		printf("\n6.Exit");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the price of the book , title and number of copies\n");
			scanf("%d%s%d",&price,title,&copy);
			head=book_beg(head,price,title,copy);
			break;
        case 2: printf("\nInserting node at a specific position and Displaying the number of books\nEnter the position of insertion");
			scanf("%d", &pos);
			head = insert(head, pos);
			break;
		case 3:	printf("\nSearching the cheapest book\n");
			sortlib(head);
			break;
		case 4:	printf("\n3.Displaying all the books having the same title\n");
			display_same(head);
			break;
        case 5:display(head);
			break;
			default:exit(0);
			break;
		}

	}
}























