#include <stdio.h>
#include <stdlib.h>
#define MAX 200
char stack_arr[MAX];

char str[MAX];

int top = 0;


void
push (char data)
{

top++;

stack_arr[top] = data;

}

char

pop ()
{

char value;

value = stack_arr[top];

top = top - 1;

return value;

}



int
main ()
{


stack_arr[top] = 'c';



printf ("\n---Enter String--->:");

gets (str);

int i = 0;

while (str[i] != 'c')

    {

if (str[i] == ' ')

	{

printf ("STRING is Invalid");

exit (1);

}

      else

	{

push (str[i]);

}

i++;

}

i++;

while (stack_arr[top] != 'c')

    {

char NEXT, X;

NEXT = str[i];

X = pop ();

if (NEXT != X)

	{

printf ("STRING is Invalid");

exit (1);

}


i++;

}

i++;

if (str[i] == ' ')

printf ("STRING is Valid");

  else

printf ("STRING is Invalid");
printf ("\n------------------------------");

return 0;

}

