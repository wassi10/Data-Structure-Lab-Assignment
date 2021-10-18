#include<stdio.h>
#include<stdlib.h>
#define N 10

int queue[N];
int  front = -1;
int rare = -1;

void push()
{
    int value;
    printf("\n\tEnter value = ");
    scanf("%d",&value);

    if(rare == N-1)
    {
        printf("\n\tOverflow");
    }
    else if(front == -1 && rare == -1)
    {
        front = rare = 0;
        queue[rare] = value;
    }
    else
    {
        rare++;
        queue[rare] = value;
    }
}

void pop()
{
    int item;

    if(front == -1 && rare == -1)
    {
        printf("\n\tUnderflow");
    }
    else if(front == rare)
    {
        front = rare = -1;
    }
    else
    {
        printf("\n\tPopped value from Queue= %d",queue[front]);
        front++;
    }
}

void display()
{
    int i ;

    if(front == -1 && rare == -1)
    {
        printf("\n\tQueue is Empty ");
    }
    else
    {
         printf("\nEnter Stack Elements = ");
        for(i = front ; i < rare+1 ; i++)
        {
            printf(" %d ",queue[i]);
        }
    }

}

int main()
{
    int choice ;
    printf("\n 1 - Insert Queue ");
    printf("\n 2 - Delete Queue ");
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



