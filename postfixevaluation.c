// postfix evaluation
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int stack[50];
int top=-1;
void push(int n)
{
    stack[++top]=n;
}
int pop()
{
    return stack[top--];
}
void main()
{
    char exp[25],*e;
    int res,in;
    printf("Enter the postfix expression : ");
    scanf("%s",exp);
    e=exp;
    while(*e!='\0')
    {
        if(isdigit(*e))
        {
            in=*e-'0';
            push(in);
            e++;
        }
        else if(*e=='+')
        {
            in=pop();
            res=pop()+in;
            push(res);
            e++;
        }
        else if(*e=='-')
        {
            in=pop();
            res=pop()-in;
            push(res);
            e++;
        }
        else if(*e=='*')
        {
            in=pop();
            res=pop()*in;
            push(res);
            e++;
        }
        else if(*e=='/')
        {
            in=pop();
            res=pop()/in;
            push(res);
            e++;
        }
        else if(*e=='^')
        {
            in=pop();
            res=pop()^in;
            push(res);
            e++;
        }
        else
        {
            printf("Invalid Expression");
            exit(0);
        }
    }
    res=pop();
    printf("The result of the expression is : %d",res);

}