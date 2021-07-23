 #include<stdio.h>
#include<stdlib.h>
#define max 100
struct stack
	{
		char elements[max];
		int top;
	};
int isempty(struct stack *s);
void push(struct stack *s,char e);
char peek(struct stack *s);
void convert_postfix(char infix[],char postfix[]);
int isfull(struct stack *s);
char pop(struct stack *s);
int size(struct stack *s);
void initstack(struct stack *s);
int isoperator(char t);
int pre(char t);
int isoperand(char t);

int main()
{
	char infix[max];
	char postfix[max];
	printf("Enter infix expression:");
	scanf("%s",infix);
	convert_postfix(infix,postfix);
	reverse(postfix);
	printf("Postfix:%s\n",postfix);
}
int isoperand(char t)
{
	if(t>='A'&&t<='Z')
{
	return 1;
}
	else if(t>='a'&&t<='z')
{
	return 1;
}
	else if(t>='0'&&t<='9')
{
	return 1;
}
	else
{
	return 0;
}
}
int isoperator(char t)
{
	if(t=='('||t=='+'||t=='-'||t=='*'||t=='/'||t=='$')
{
	return 1;
}
	else
{
	return 0;
}
}
int pre(char t)
{
	int p;
	switch(t)
{
	case '$':p=3;
	break;
	case '*':p=2;
	break;
	case '/':p=2;
	break;
	case '+':p=1;
	break;
	case '-':p=1;
	break;
	default:p=-1;
}
	return p;
}
void convert_postfix(char infix[],char postfix[])
{
	struct stack s;
	initstack(&s);
	int i,j=0;
	int len=strlen(infix);
	for(i=len-1;i>=0;i--)
	{
		if(isoperand(infix[i]))
		{
		postfix[j]=infix[i];
		j++;
		}
		else if(isoperator(infix[i]))
		{
			if(isempty(&s)||infix[i]==')')
			{
			push(&s,infix[i]);
			}
			else
			{
			while(!isempty(&s)&&pre(infix[i])<=pre(peek(&s)))
			{
			postfix[j]=pop(&s);
			j++;
			}
			push(&s,infix[i]);
			}
		}
		else if(infix[i]=='(')
		{
			while(!isempty(&s)&&peek(&s)!=')')
			{
			postfix[j]=pop(&s);
			j++;
			}
			pop(&s);
		}
}
		while(!isempty(&s))
		{
		postfix[j]=pop(&s);
		j++;
		}
		postfix[j]='\0';


}
void initstack(struct stack *s)
	{
	s->top=-1;
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
void push(struct stack *s,char e)
{
	s->top++;
	s->elements[s->top]=e;
}
char peek(struct stack *s)
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
char pop(struct stack *s)
{
	char e=s->elements[s->top];
	s->top--;
	return e;
}
int size(struct stack *s)
{
	return (s->top)+1;
}
void reverse(char str[])
{
    int i=0;
    int j=strlen(str)-1;
    char temp;
    while(i<j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}
