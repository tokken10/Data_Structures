/*
* C Program to Implement an array based linear Queue 
using array, rear and front
*/
#include <stdio.h>
#include<stdlib.h>
#define MAX 50
int queue_array[MAX];
int rear = 0;
int front = 0;


void enQueue(int add_item)
{
    if (rear <MAX)
    {
        queue_array[rear] = add_item;
        rear = rear + 1;
        printf("\nAdded to queue");
    }
    else
    {
        printf("Queue Overflow \n");
    }
} /*End of insert()*/

int deQueue()
{
    if(front==rear)
    {
        printf("\n Empty. ");
        return -9999;
    }
    else
        return queue_array[front++];
} /*End of delete() */

void display()
{
    int i;
    if (front == rear)
    printf("Queue is empty \n");
    else
    {
        printf("\nQueue is : \n");
        for (i = front; i < rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n\n");
    }
} /*End of display() */



int main()
{
    int choice;
    int data;
    while (1)
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nWhat data you want to put in the queue?: ");
                scanf("%d", &data);
                enQueue(data);
                display();
                break;
            case 2:
                data = deQueue();
                if(data>=-999)
                    printf("\n%d deleted from queue\n", data);
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
    return 0;
} /*End of main()*/

