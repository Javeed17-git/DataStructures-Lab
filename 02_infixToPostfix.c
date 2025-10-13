#include<stdio.h>
#include<ctype.h> //for isalnum()
#include<string.h> //for strlen()
#define MAX 100

char stack[MAX];
int top = -1;

//function to push into stack
void push(char c)
{
    if(top == MAX -1)
    {
        printf("Stack Overflow\n");
    }
    else{
        top += 1;
        stack[top] = c;
    }
}

//funtion to pop from stack
char pop()
{
    char val;
    if(top ==-1)
    {
        printf("Stack Underflow\n");
        return -1;

    }
    else{
        val = stack[top];
        top -= 1;
        return val;
    }
}

//function to get peek of stack
char peek()
{
    if(top == -1)
    {
        return '\0';
    }
    return stack[top];
}

//function to check precedence of operators
int precedence(char c)
{
    if(c == '+' || c  == '-') return 1;
    if(c == '*' || c  == '/') return 2;
    if(c == '^') return 3;
    return 0;
}

//funtion to convert infix to postfix
void infixToPosstfix(char infix[],char postfix[])
{
    int i,k = 0;
    char c;
    for(i = 0;infix[i] != '\0' ; i++)
    {
        c = infix[i];
        //if operand,add to postfix expression 
        if(isalnum(c))
        {
            postfix[k] = c;
            k+=1;
        }
        //if '(' ,pussh to stack
        else if(c == '(')
        {
            push(c);
        }
        //if ')', pop until '('
        else if(c == ')')
        {
            while(top != -1 && peek() != '(')
            {
                postfix[k] = pop();
                k+=1;
            }
            pop(); //remove '('
        }
        //if its a operator
        else
        {
            while(top != -1 && precedence(peek()) >= precedence(c))
            {
                postfix[k] = pop();
                k = k+1;
            }
            push(c);
        }

    }

    //pop all remaining operators 
    while(top != -1)
    {
        postfix[k]=pop();
        k += 1;
    }
    postfix[k] = '\0';

}
int main()
{
    char infix[MAX],postfix[MAX];

    printf("Enter a valid paranthesized infix expression: ");
    scanf("%s",infix);

    infixToPosstfix(infix,postfix);

    printf("Postfix Expression: %s\n",postfix);
    return 0;
