//Addition of two polynomials using linked list with recursion
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int c,e;
    struct node *next;
}*p1=NULL,*p2=NULL,*p3=NULL;
struct node * create(int id,int n,int m)
{
    if(n<m)
    {
        struct node *t=malloc(sizeof(struct node));
        printf("Enter the coe of %d poly",id);
        scanf("%d",&t->c);
        printf("Enter the exp of %d poly",id);
        scanf("%d",&t->e);
        t->next=create(id,n+1,m);
        return t;
    }
    else
        return NULL;
}
struct node * add(struct node *t1,struct node *t2)
{
    struct node * r =malloc(sizeof(struct node));
    if(t1 != NULL && t2 != NULL)
    {
        if(t1->e > t2->e)
        {
            r->e=t1->e;
            r->c=t1->c;
            r->next=add(t1->next,t2);
            return r;
        }
        else if(t2->e > t1->e)
        {
            r->e=t2->e;
            r->c=t2->c;
            r->next=add(t1,t2->next);
            return r;
        }
        else
        {
            r->e=t1->e;
            r->c=t1->c+t2->c;
            r->next=add(t1->next,t2->next);
            return r;
        }
    }
    else if(t1 != NULL)
    {
            r->e=t1->e;
            r->c=t1->c;
            r->next=add(t1->next,t2);
            return r;
    }
    else if(t2 != NULL)
    {
            r->e=t2->e;
            r->c=t2->c;
            r->next=add(t1,t2->next);
            return r;
    }
    else
        return NULL;
}
struct node * display(struct node *t)
{
    if(t->next !=NULL)
    {
        printf("%d^%d+",t->c,t->e);
        display(t->next);
    }
    else if(t!=NULL)
    {
        printf("%d^%d",t->c,t->e);
    }
}
void main()
{
    int n1,n2;
    printf("Enter the size of 1 poly");
    scanf("%d",&n1);
    printf("Enter the size of 2 poly");
    scanf("%d",&n2);
    p1=create(1,0,n1);
    p2=create(2,0,n2);
    p3=add(p1,p2);
    display(p3);
}