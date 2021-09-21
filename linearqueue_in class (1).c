
#include <stdio.h>
#include<stdlib.h>
#define SIZE 6   //the size of the array is 6



typedef struct Queue
{
  
   int Array[SIZE];
  
   int rear;
   int front;
   int capacity;

}Queue;




Queue* init()  
{
   Queue* q=(Queue*)malloc(sizeof(Queue));   

   q->front = 0;
   q ->rear = 0;
   q -> capacity = SIZE;
   return q;
}


void enqueue(Queue *q, int item)
{

   if(q!= NULL)
   {
   
 
     if(q-> rear < q->capacity)  
       q->Array[q->rear]=item;
       (q->rear)++; 
     
     }
     else
     printf("Queue is FULL\n");
   

}

int dequeue(Queue *q) 
{
 if(q!= NULL)
   { 
  
   if(q->rear != q ->front)  
   {
      int retval= q->Array[q->front];
      (q->front)++;
      return retval;
     
   }
   else 
   {
     printf("Queue is EMPTY\n");
     
     return -999;
     }
   }
 else 
   {
     printf("Queue is EMPTY\n");
    
     return -999;
     }

}

void display(Queue *q)
{
  if (q!= NULL)
  {  
     printf("printing the queue:");
     for(int i=q->front; i< q-> rear; i++) 
     
    
         printf("%d ", q->Array[i]);
  }


}

int main()
{
    int choice;
    int data;
    Queue *q = init();  
    while (1)
    {
        printf("\n1.Insert element to queue \n");
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
                enqueue(q,data);  
                display(q);  
                break;
            case 2:
                data = dequeue(q);  
                if(data>=-999)
                    printf("\n%d deleted from queue\n", data);
                display(q); 
                break;
            case 3:
                display(q); 
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        } /*End of switch*/
    } /*End of while*/
    return 0;
} /*End of main()*/

