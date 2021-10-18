#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *head = NULL, *tail = NULL;
Node *CreateList()
{
    int value ;
    printf("\nEnter some Integer value and (-1) for stop linked list \n");
    scanf("%d",&value);

    while(value != -1)
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;

        if(head == NULL)
        {
            head = tail = new_node;

        }
        else
        {
            tail->next = new_node ;
            tail = new_node;
        }
        tail->next = head;
        scanf("%d",&value);
    }
    return head;
}
int count = 0;
Node *totalNode()
{
    Node *avail;

    avail = head;

    while(avail->next != head)
    {
        count++;
        avail = avail->next;
    }
    count++;
    printf("\nTotal Node = %d",count);

}
Node *InsertGivenPosition()
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    int position = 0, i= 1;

    printf("\nEnter Position where we want to insert new node = ");
    scanf("%d",&position);

    if(position < 0 || position > count)
    {
        printf("\nInvalid Position ");
    }
    else if(position == 1)
    {
        printf("\nEnter the value of Node = ");
        scanf("%d",&new_node->data);
        new_node->next = NULL;

        if(tail == NULL)
        {
            tail = new_node;
            tail->next = new_node;
        }
        else
        {
            new_node->next = head;
            tail->next = new_node;
            head = new_node;
        }

        count++;
    }
    else
    {
        printf("\nEnter the value of Node = ");
        scanf("%d",&new_node->data);
        new_node->next = NULL;
        Node *temp = tail->next;

        while(i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;
}
Node *DeletePosition()
{
    Node *nextNode, *currentNode;
    int position = 0, i = 1;

    currentNode = tail->next;
    printf("\nEnter Position = ");
    scanf("%d",&position);

    if(position < 0 || position > count)
    {
        printf("\nInvalid position");
    }
    else if(position == 1)
    {
        Node *temp;
        temp = head;


        if(tail == 0)
        {
            printf("\n\tUnderflow");
        }
        else if(temp->next = temp)
        {
            tail = 0;
            free(temp);
        }
        else
        {
            temp = head;
            head = head->next;
            tail->next= head;
            free(temp);
        }
    }
    else
    {
        while(i<position-1)
        {
            currentNode = currentNode->next;
            i++;
        }
        nextNode = currentNode->next;
        currentNode->next = nextNode->next;
        free(nextNode);
    }
    return head;
}

void Traverse(Node *avail)
{

    if(head == 0)
    {
        printf("\nThe data is off ");
    }
    else
    {

        avail = head;
        while(avail->next != head)
        {
            printf(" %d ",avail->data);
            avail = avail->next;
        }
        printf(" %d ",avail->data);
    }
}
int main()
{
    Node *y= CreateList();
    y= totalNode();
    y = InsertGivenPosition();
    Traverse(y);

    y = DeletePosition();
    Traverse(y);
    return 0;
}





