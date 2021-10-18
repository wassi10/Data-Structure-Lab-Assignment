#include<stdio.h>
#include<stdlib.h>
#define N 10

int stack[N];
int top = -1;

void push()
{
    int value;
    printf("\n\tEnter value = ");
    scanf("%d",&value);

    if(top == N-1)
    {
        printf("\n\tOverflow");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    int item;
    if(top == -1)
    {
        printf("\n\tUnderflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("\n\tPopped item = %d",item);
    }
}

void display()
{
    int i ;
     printf("\nEnter Stack Elements = ");
    for(i = top ; i>=0 ; i--)
    {
        printf(" %d ",stack[i]);
    }
}

int main()
{
    int choice ;
    printf("\n 1 - Insert Stack");
    printf("\n 2 - Delete  Stack");
    printf("\n 3 - Display ");
    printf("\n 4 - Exit\n");
    while(1)
    {
         printf("\nEnter your Choice = ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
          push();
            break;
        case 2:
           pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("The Program is Over.\n");
            exit(0);
            break;

        default:
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}


