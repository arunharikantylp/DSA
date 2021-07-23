#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
struct stack
{
float elements[max];
int top;
};
void initstack(struct stack *s);
void push(struct stack *s,float e);
float pop(struct stack *s);
float peek(struct stack *s);
int isfull(struct stack *s);
int isempty(struct stack *s);
float eval(char postfix[]);
int isoperand(char t);
int main()
{
char postfix[max];
float res;
printf("Enter the postfix expression:");
scanf("%s",postfix);
res=eval(postfix);
printf("RESULT:%f\n",res);
}
void initstack(struct stack *s)
{
s->top=-1;
}
void push(struct stack *s,float e)
{
s->top++;
s->elements[s->top]=e;
}
float pop(struct stack *s)
{
float e=s->elements[s->top];
s->top--;
return e;
}
float peek(struct stack *s)
{
return s->elements[s->top];
}
int isfull(struct stack *s)
{
if(s->top==max-1)
{
return 1;
}
else
{
return 0;
}
}
int isempty(struct stack *s)
{
if(s->top==-1)
{
return 1;
}
else
{
return 0;
}
}
int size(struct stack *s)
{
return s->top+1;
}
float eval(char postfix[])
{
struct stack s;
initstack(&s);
int i;
float e;
float opnd1,opnd2,res;
for(i=0;postfix[i]!='\0';i++)
{
	if(isoperand(postfix[i]))
	{
		if(isalpha(postfix[i]))
		{
		printf("Enter value of %c:",postfix[i]);
		scanf("%f",&e);
		push(&s,e);
		}
		else
		{
		e=postfix[i]-48;
		push(&s,e);
		}
	}
	else
	{
	opnd2=pop(&s);
	opnd1=pop(&s);
	switch(postfix[i])
	{
	case '+':res=opnd1+opnd2;
		 break;
	case '*':res=opnd1*opnd2;
		 break;
	case '-':res=opnd1-opnd2;
		 break;
	case '/':res=opnd1/opnd2;
		 break;
	case '$':res=pow(opnd1,opnd2);
		 break;
	}
	push(&s,res);
	}
     }
return pop(&s);
}
int isoperand(char t)
{
if(t>='A'&&t<='Z')
return 1;
else if(t>='a'&&t<='z')
return 1;
else if(t>='0'&&t<='9')
return 1;
else
return 0;
}
