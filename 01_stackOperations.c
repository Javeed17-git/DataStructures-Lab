#include<stdio.h>
int size= 5;
int stack[5];
int top = -1;
void push(int item)
{
    if(top == size-1)
    {
        printf("The stack is overflown!!");
        return;
    }
    else{
        top +=1;
        stack[top] = item;
    }
}
void pop()
{
    if(top == -1)
    {
        printf("The stack is underflown!!");
        return ;
    }
    else{
        int ele = stack[top];
        top -= 1;
        printf("The element which was poped is %d",ele);
    }
}
void display()
{
    if(top == -1)
    {
        printf("Nothing to display, Stack is empty!");
    }
    else{
        printf("The stack from top to bottom is :");
        for(int i = top;i>=0;i--)
        {
            printf("%d, ",stack[i]);
        }
    }
}
int getPeek()
{
    if(top == -1)
    {
        printf("The stack is empty!!");
        return ;
    }
    else{
        printf("The peek element is %d ",stack[top]);
    }
}
int main()
{
    while(1)
    {
        printf("\n\nChoose any of the following operations : ");
        printf("\n1.PUSH ");
        printf("\n2.POP");
        printf("\n3.DISPLAY ");
        printf("\n4.PEEK ");
        printf("\n5.EXIT \n");
        
        int choice ;
        scanf("%d",&choice);
        if(choice == 1)
        {
            int item;
            printf("Enter the element you want to push : \n");
            scanf("%d",&item);
            push(item);
            printf("%d is added to the stack.",item);
        }
        else if(choice  == 2)
        {
           pop();
           
        }
        else if(choice == 3)
        {
            
            display();
        }
        else if(choice == 5)
        {
            printf("Exiting the program !!");
            break;
        }
        else if(choice == 4)
        {
            getPeek();
        }
        else{
            printf("Enter a valid choice");
        }

    }
    return 0;
}