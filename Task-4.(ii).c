#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;

} Node;

Node *top = 0;

void push()
{
    int value;
    printf("\n\tEnter value = ");
    scanf("%d",&value);

    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->link = top;
    top = new_node;
}

void pop()
{
    Node *temp ;
    temp = top;
    if(top == 0)
    {
        printf("\n\tUnderflow");

    }
    else
    {
        printf("\n\tPopped data = %d",top->data);
        top=top->link;
        free(temp);
    }
}
void display()
{
    Node *a;
    a = top;

    if(top == 0)
    {
        printf("\n\tStack Empty ");
    }
    else
    {
        printf("\nEnter Stack Elements = ");
        while(a != 0)
        {
            printf(" %d ",a->data);
            a = a->link;
        }
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

