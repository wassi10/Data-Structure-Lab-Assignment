#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL, *tail = NULL;

Node *Creation()
{

    int value ;
    printf("\nEnter some integer value for create a linked list and (-1) for stop linked list: ");
    scanf("%d",&value);

    while(value != -1)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value ;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = tail = newNode;

        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        scanf("%d",&value);
    }
    return head;
}

int countNode = 0;

int count = 0;
Node *totalNode(Node *a)
{
    a = head;

    while(a != NULL)
    {
        count++;
        a = a->next;
    }
    printf("\nTotal Node in the list = %d",count);
    //return count ;
}
Node *Insertion()
{
    int position;
    printf("\nEnter the position where we want to insert new node = ");
    scanf("%d",&position);

    Node *new_node = (Node*)malloc(sizeof(Node));
    printf("\nEnter node value = ");
    scanf("%d",&new_node->data);

    new_node->prev = NULL;
    new_node->next = NULL;

    Node *temp ;
    temp = head;
    if(position< 0 || position > count)
    {
        printf("\nInvalid Position");
    }
    else if (position == 1)
    {
        if(head == NULL)
        {
            head = tail =  new_node;
            count++;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
            count++;
        }
    }
    else
    {
        int i = 1 ;
        while (i < position-1)
        {
            temp = temp->next;
            i++;
        }
        new_node->prev = temp;
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->next->prev = new_node;
    }
    return head;
}
Node *Deletion()
{
   int position = 0, i = 1 ;
    Node *avail ;

    printf("\n\tEnter the position where we want to delete = ");
    scanf("%d",&position);

    if(position < 0 || position > count)
    {
        printf("\n\tInvalid Position ");
        printf("\n\tPrevious Node value = ");
    }
    else if(position == 1)
    {
        avail = head;
        head = head->next;
        head->prev = NULL;
        free(avail);

    }
    else
    {
        avail = head;
        while( i < position)
        {
            avail = avail->next;
            i++;
        }

        avail->prev->next = avail->next;
        avail->next->prev = avail->prev;
        free(avail);
    }

    return head;

}

void p(Node *a)
{
    a = head;
    while(a != NULL)
    {
        printf(" %d ",a->data);
        a = a->next;
    }
}

int main()
{
    Node *h = Creation();

    h = totalNode(h);

    if(h == NULL)
    {
        printf("\nThe List is Empty ");
    }
    else
    {
        h = Insertion();
        p(h);

        h = Deletion();
        p(h);
    }
    return 0;
}
