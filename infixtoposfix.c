#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[50];
int top=-1;
int pre(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 2;
    }
    else if(x=='^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void push(int x)
{
    stack[++top]=x;
}
int pop()
{
    int x=stack[top--];
    return x;
}
void main()
{
    int i=0;
    char exp[25],*e,res[25];
    printf("Enter the expression : ");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isalpha(*e))
        {
            res[i++]=*e;
            e++;
        }
        else if(*e=='(')
        {
            push(*e);
            e++;
        }
        else if(*e==')')
        {
            e++;
            while((stack[top])!='(')
            {
                res[i++]=pop();
            }
            pop();
        }
        else
        {
            if(pre(*e) != 0)
            {
                if(pre(*e)>pre(stack[top]))
                {
                    push(*e);
                }
                else
                {
                    while(pre(*e)<=pre(stack[top]))
                    {
                        res[i++]=pop();
                    }
                    push(*e);
                }
                e++;
            }
        }
    }
    while(top != -1)
    {
        res[i++]=pop();
    }
    res[i]='\0';
    printf("Result = %s",res);
}