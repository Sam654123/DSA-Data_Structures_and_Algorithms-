#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct node
{
    int data;
    struct node *next;
};

// Print the Data of Node
void printdata(struct node *N)
{
    if (N == NULL)
    {
        printf("The List is Empty!!");
    }
    else
    {
        while (N != NULL)
        {
            printf("%d ", N->data);
            N = N->next;
        }
    }
    printf("\n");
}

// Inserting the data at the beginning of Node
void insertatfirst(struct node **head, int x)
{
    struct node *N = *head;
    struct node *p = NULL;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if (N == NULL)
    {
        *head = p;
    }
    else
    {
        p->next = N;
        *head = p;
    }
}

// Inserting data at the End of the Node
void insertatlast(struct node **head, int x)
{
    struct node *N = *head;
    struct node *p = NULL;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if (N == NULL)
    {
        *head = p;
    }
    else
    {
        while (N->next != NULL)
        {
            N = N->next;
        }
        N->next = p;
    }
}

// Inserting data in between the Node
void insertbetween(struct node **head, int x, int pos)
{
    int size = sizeof(*head);

    if (pos < 1 || size < pos)
    {
        printf("Can't insert, %d is not a valid position\n", pos);
    }
    else
    {
        struct node *N = *head;
        struct node *p = NULL;
        p = (struct node *)malloc(sizeof(struct node));
        p->data = x;
        p->next = NULL;
        if (N == NULL)
        {
            *head = p;
        }
        while (--pos)
        {
            N = N->next;
        }
        p->next = N->next;
        N->next = p;
    }
}

// Deleting the  First Node
void deletefirst(struct node **head)
{
    struct node *p;
    if (*head == NULL)
    {
        printf("No Node Existing");
    }
    else
    {
        p = *head;
        *head = (*head)->next;
        free(p);
        p = NULL;
    }
}

// Deleting the Last Node
void deletelast(struct node **head)
{
    if (*head == NULL)
    {
        printf("No Node Existing");
    }
    else
    {
        struct node *p = *head;
        struct node *q;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
        p = NULL;
    }
}

// Deleting the Node in between
void deletebetween(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("No Node Existing");
    }
    else
    {
        struct node *p = *head;
        struct node *q;
        if (p->next == NULL)
        {
            *head = NULL;
            free(p);
            p = NULL;
        }
        else
        {
            while (--pos)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            p->next = NULL;
            free(p);
            p = NULL;
        }
    }
}

// Main function
int main()
{
    int ch, num, pos, opt;
    struct node *head = NULL;
    while (1)
    {
        printf("Choose the following option for singly linked list:-\n1:Insertion\t2:Deletion\t3:Exit\n=>");
        scanf("%d", &opt);

        if (opt == 1)
        {
            while (1)
            {
                printf("Choose the operation you want to perform:\n1:Insert at begining\t2:Insert at last\t3:Insert in between\t4:Print the data\t5:Exit from insertion operation\n=>");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                {
                    printf("Enter the integer:");
                    scanf("%d", &num);
                    insertatfirst(&head, num);
                    break;
                }
                case 2:
                {
                    printf("Enter the integer:");
                    scanf("%d", &num);
                    insertatlast(&head, num);
                    break;
                }
                case 3:
                {
                    printf("Enter after which position you want to insert:");
                    scanf("%d", &pos);
                    printf("Enter the integer:");
                    scanf("%d", &num);
                    insertbetween(&head, num, pos);
                    break;
                }
                case 4:
                {
                    printdata(head);
                    break;
                }
                case 5:
                {
                    break;
                }
                default:
                    printf("Enter a valid Operation number!!");
                }
                if (ch == 5)
                {
                    break;
                }
            }
        }
        else if (opt == 2)
        {
            while (1)
            {
                printf("Choose the operation you want to perform:\n1:Delete First Node\t2:Delete Last Node\t3:Delete Node in between\t4:Print the data\t5:Exit from deletion operation\n=>");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                {
                    deletefirst(&head);
                    break;
                }
                case 2:
                {
                    deletelast(&head);
                    break;
                }
                case 3:
                {
                    printf("Enter the position of node you want to delete:");
                    scanf("%d", &pos);
                    deletebetween(&head, pos);
                    break;
                }
                case 4:
                {
                    printdata(head);
                    break;
                }
                case 5:
                {
                    break;
                }
                default:
                    printf("Enter a valid Operation number!!");
                }
                if (ch == 5)
                {
                    break;
                }
            }
        }
        else if (opt == 3)
        {
            break;
        }
    }

    return 0;
}
