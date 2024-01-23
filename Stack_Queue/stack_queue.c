#include <stdio.h>
void queue_(int);
void stack_(int);

// Main Function
int main()
{
    int n;
    while (1)
    {
        printf("Enter what process you want to start\n STACK:1 \t QUEUE:2\t EXIT:3 \n->");
        scanf("%d", &n);
        if (n == 1)
        {
            stack_(1);
        }
        else if (n == 2)
        {
            queue_(1);
        }
        else if (n == 3)
        {
            break;
        }
    }
    return 0;
}

// Stack Function
void stack_(int n)
{
    int x, num, ch, top = -1, i;
    printf("Enter the number of elements you want to input:");
    scanf("%d", &num);
    int a[num];
    while (1)
    {
        printf("\nPUSH:1\tPOP:2\tQUIT:3\tPRINT ARRAY:4\n=>");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            if (top == (num - 1))
            {
                printf("Overflow\n");
            }
            else
            {
                top++;
                printf("Enter element:");
                scanf("%d", &a[top]);
            }
            break;
        }
        case 2:
        {
            if (top == -1)
            {
                printf("Underflow\n");
                continue;
            }
            x = a[top];
            top--;
            break;
        }
        case 3:
        {
            return;
        }
        case 4:
        {
            if (top == -1)
            {
                printf("Underflow\n");
                continue;
            }
            else
            {
                for (i = top; i >= 0; --i)
                {
                    printf("%d ", a[i]);
                }
            }
            break;
        }
        }
    }
}

// Queue Function
void queue_(int n)
{
    int x, num, ch, front = -1, rear = -1, i;
    printf("Enter the number of elements you want to input:");
    scanf("%d", &num);
    int a[num];
    while (1)
    {
        printf("\nChoose the operation you want to perform in QUEUE:\n1:Enqueue\t2:Dequeue\t3:Print QUEUE\t4:EXIT\n=>");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            if (rear == (num - 1))
            {
                printf("Overflow\n");
            }
            else if (front == -1 && rear == -1)
            {
                rear = 0;
                front = 0;
                printf("Enter element:");
                scanf("%d", &a[rear]);
            }
            else
            {
                rear++;
                printf("Enter element:");
                scanf("%d", &a[rear]);
            }
            break;
        }
        case 2:
        {
            if (front == -1 && rear == -1)
            {
                printf("Underflow\n");
                continue;
            }
            else if (front == rear)
            {
                x = a[front];
                printf("Removed Element:%d", x);
                front = rear = -1;
            }
            else
            {
                x = a[front];
                printf("Removed Element:%d", x);
                ++front;
            }
            break;
        }
        case 3:
        {
            if (front == -1 && rear == -1)
            {
                printf("Underflow\n");
                continue;
            }
            else
            {
                for (i = front; i <= rear; ++i)
                {
                    printf("%d ", a[i]);
                }
            }
            break;
        }
        case 4:
        {
            return;
        }
        }
    }
}
