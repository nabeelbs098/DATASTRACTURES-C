//Implementation of stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int d;
    struct node * n;
};
struct node * push(struct node *top,int x)
{
    struct node * t = malloc(sizeof(struct node));
    t->d=x;
    t->n=top;
    top=t;
    return top;
}
struct node * pop(struct node *top)
{
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node * t = malloc(sizeof(struct node));
        t=top;
        top=top->n;
        free(t);
    }
    return top;
}
void display(struct node * top)
{
    struct node * t = malloc(sizeof(struct node));
    for(t=top;t->n!=NULL;t=t->n)
    {
        printf("%d ",t->d);
    }
    printf("%d\n",t->d);
}
void main()
{
    struct node * top = malloc(sizeof(struct node));
    int c,x;
    do{
        printf("\n\n1)PUSH\n2)POP\n3)DISPLAY\n4)EXIT\nEnter the choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter the element to push : ");
                scanf("%d",&x);
                top=push(top,x);
                break;
            }
            case 2:
            {
                top=pop(top);
                break;
            }
            case 3:
            {
                display(top);
                break;
            }
            case 4:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid input\n");
            }
        }
    }while(c!=4);
}