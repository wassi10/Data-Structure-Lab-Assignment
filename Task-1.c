#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} Node;

Node *head = NULL, *tail=NULL;

int count = 0;

Node *Creation()
{
    int value;
    printf("\nEnter some integer value for create a linked list and (-1) for stop linked list \n");
    scanf("%d",&value);

    head = NULL;
    tail = NULL;

    while(value != -1)
    {
        Node *new_node = (Node*) malloc(sizeof(Node));

        new_node->data = value;
        new_node->next = NULL;

        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        scanf("%d",&value);
    }
    return head;
}

int totalNode(Node *q)
{
    while( q != NULL)
    {
        count++;
        q = q->next;
    }
    return count;
}


Node *Insertion()
{
    Node *avail ;

    int i = 1, position = 1;
    printf("\nEnter the position where we want to insert Node = ");
    scanf("%d",&position);

    if( position < 0 || position > count)
    {
        printf("\nInvalid Position");
    }

    else if(position == 1)
    {
        Node *new_node = (Node*)malloc(sizeof(Node));
         printf("\nEnter New Node value = ");
        scanf("%d",&new_node->data);

        new_node->next = head;
        head = new_node;

        count++;
    }
    else
    {
        Node *new_node = (Node*)malloc(sizeof(Node));

        avail = head ;
        while( i < position - 1 )
        {
            avail = avail->next;
            i++;
        }
        printf("\nEnter New Node value = ");
        scanf("%d",&new_node->data);
        new_node->next =  avail->next;
        avail->next = new_node;

        count++;
    }

    return head;
}

Node *Deletion()
{
    Node *avail, *next_node;
    int i = 1, position = 0;
    printf("\nEnter the position where we want to remove node = ");
    scanf("%d",&position);
    avail = head;

    if(position < 0 || position > count)
    {
        printf("\nInvalid Position\n");
    }
    else if(position == 1)
    {
        //avail = head;
        head = head->next;
        free(avail);

    }
    else
    {
        while(i < position-1)
        {
            avail = avail->next;
            i++;
        }
        next_node = avail->next;
        avail->next = next_node->next;
        free(next_node);

    }


    return head;
}


//p = print Node
void p(Node *q)
{
    while( q != NULL)
    {
        printf(" %d ",q->data);
        q = q->next;
    }
}

int main()
{
    Node *i = Creation();

    totalNode(i);
    if(i == NULL)
    {
        printf("\nList is NULL\n");

    }
    else
    {
        i = Insertion();

        p(i);

        i = Deletion();
        p(i);
    }

    return 0;
}

