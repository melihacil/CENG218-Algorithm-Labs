#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


// Program that uses a stack to convert an infix to postfix state
struct Stack {
    int top;
    int maxSize;
    int* array;     // Takes the element as an ascii code (ex : A,B)
};
struct Stack* create(int max)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->maxSize = max;
    stack->top = -1;
    stack->array = (int*)malloc(stack->maxSize * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
    if(stack->top == stack->maxSize - 1){
        printf("Max!!!\n");
    }
    return stack->top == stack->maxSize - 1;
}

//Adds an element to the stack (Push function)
void push(struct Stack* stack, char item)
{
	if(stack->top == stack->maxSize - 1 )
	{
		printf("\nMaximum size\n");
	}
	else
	{
		stack->array[++stack->top] = item;
	}
}

//Removes an element from the stack (pop function)
int pop(struct Stack* stack)
{
    if (stack->top == -1)
        return INT_MIN;
    return stack->array[stack->top--];
}

int searchAndGet(struct Stack* stack)
{
    if (stack->top == -1)
        return INT_MIN;
    return stack->array[stack->top];
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isEmpty(struct Stack* stack) {return stack->top == -1;}

int oncelikSirasi(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int converttoPostfix(char* expression)    //Function to convert it to postfix
{
    int i;
    int j;

    struct Stack* stack = create(strlen(expression));
    for (i = 0, j = -1; expression[i]; ++i)
    {

        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(stack, expression[i]);
        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && searchAndGet(stack) != '(')
                expression[++j] = pop(stack);
            if (!isEmpty(stack) && searchAndGet(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else // if an operator
        {
            while (!isEmpty(stack) && oncelikSirasi(expression[i]) <= oncelikSirasi(searchAndGet(stack)))
                expression[++j] = pop(stack);
            push(stack, expression[i]);
        }

    }

    //Last step to make stack empty

    while (!isEmpty(stack))
        expression[++j] = pop(stack);

    expression[++j] = '\0';

}

void reverse(char *exp){

    int size = strlen(exp);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(exp[i]!='\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp,temp);
}
void parentezCevirici(char* exp){
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            exp[i]=')';
        else if(exp[i]==')')
            exp[i]='(';
        i++;
    }
}

void prefix(char *str){

    int size = strlen(str);
    int j = size, i=0;
    char temp[size];
    temp[j--]='\0';
    while(str[i]!='\0')
    {
        temp[j] = str[i];
        j--;
        i++;
    }
    strcpy(str,temp);
    parentezCevirici(str);
    converttoPostfix(str);
}

void removeSpace(char* s) {
    char* d = s;
    do {
        if (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int main()
{
    struct timeval stop, start; //To calculate how long the function takes
    gettimeofday(&start, NULL);

    printf("The infix is: ");
    char expression[] = "(A-B/C) * (A/K-L)";
    removeSpace(expression);
    printf("%s\n",expression);
    prefix(expression);
    printf("The prefix is: ");
    int size = strlen(expression);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(expression[i]!='\0')
    {
        temp[j] = expression[i];
        j--;
        i++;
    }
    strcpy(expression,temp);
    printf("%s\n",expression);
    //sleep(1);
     clock_t end = clock();

    gettimeofday(&stop, NULL);
    printf ("Total time = %f seconds\n",(double) (stop.tv_usec - start.tv_usec) / 1000000 + (double) (stop.tv_sec - start.tv_sec)); //second
    printf("Time milliseconds = %lu\n", ((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec));         //milliseconds
    printf("Time nanoseconds = %lu\n", (((stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec))* 1000); //mircoseconds
    //printf("The elapsed time is %f seconds", time_spent);
    return 0;
}
