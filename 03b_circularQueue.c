#include<stdio.h>
#define MAX 5 //maximum size of queue
int queue[MAX];
int front = -1,rear = -1;

//functions to insert an element in the circular queue
void insert(int value)
{
    if(front == (rear + 1) % MAX)
    {
        printf("Queue Overflow ! Cannot insert %d ",value);
    }
    else
    {
        if(front == -1)
        {
            //first insertion
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = value;
        printf("%d inserted into queue : \n",value);
    }
}

//function to delete an element from the queue
void delete()
{
    if(front == -1)
    {
        printf("Queue Underflow!Queue is empty\n");

    }
    else
    {
        printf("Deleted element :%d\n",queue[front]);
        if(front == rear)
        {
            //queue becomes empty
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front +1 ) % MAX;
        }
    }
}

//functtion to display elements of the circular queue
void display()
{
    if(front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements : ");
        int i = front;
        while(1)
        {
            printf("%d\n",queue[i]);
            if(rear == i)
            {
                break;

            }
            i = (i + 1) % MAX;
        }
    }
}

void displayFront()
{
    printf("The Element at front is %d",queue[front]);
}
void displayRear()
{
    printf("The Element at front is %d",queue[rear]);
}

//main function
int main()
{
    int choice,value;
    while(1)
    {
        printf("\n Circular Queue Operations : \n");
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n5.Display Front\n6.Display Rear\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1 : 
                    printf("Enter value to insert : ");
                    scanf("%d",&value);
                    insert(value);
                    break;
            case 2 : 
                    delete();
                    break;
            case 3 : 
                    display();
                    break;
            case 4:
                    printf("Exiting program.\n");
                    return 0;
            default:
                    printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}