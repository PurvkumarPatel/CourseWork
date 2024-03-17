#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 200

char stack[M];
char postfix[M];
char infix[M];
int top = 0;
int RANK = 0;
int k = 0;
int l = 0;
char ans;
void push (char);

void inToPost ();
void print ();
int G (char);
int F (char);
int roe (char);
void add_to_postfix (char);

char pop ();

char
pop ()
{
  ans = stack[top];
  top--;
  return ans;
}


int
main ()
{
  printf ("|>Enter Infix Expresion---------> ");
  scanf ("%s", infix);

  inToPost ();
  return 0;
}


void
push (char data)
{
  top++;
  stack[top] = data;
}


void
print ()
{
  int j;

  for (j = 0; j < strlen (postfix); j++)
    {
      printf ("%c", postfix[j]);
    }

}



void
inToPost ()
{
  int i = 0;
  char NEXT;
  char temp;
  stack[top] = '(';
  for (i = 0; i <= strlen (infix); i++)
    {
      while (G (stack[top]) > F (infix[i]))
	{
	  temp = pop ();
	  add_to_postfix (temp);

	  RANK = RANK + roe (temp);
	  if (RANK < 1)
	    {
	      printf ("INVALID STRING2");
	      exit (1);
	    }
	}

      if (G (stack[top]) != F (infix[i]))
	{
	  push (infix[i]);
	}
      else
	{
	  pop ();
	}
    }
  print ();
}


int
G (char SBL)
{
  switch (SBL)
    {
    case '^':
      return 6;
    case '/':
    case '*':
      return 4;
    case '+':
    case '-':
      return 2;
    case '(':
    case ')':
      return 0;
    default:
      return 8;
    }
}

int
F (char symbol)
{
  switch (symbol)
    {
    case '^':
      return 5;
    case '/':
    case '*':
      return 3;
    case '+':
    case '-':
      return 1;
    case '(':
      return 9;
    case ')':
    case '\0':
      return 0;
    default:
      return 7;
    }
}



int
roe (char c)
{
  switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      return -1;
      break;
    case '(':
    case ')':
      return 0;
      break;
    default:
      return 1;
      break;
    }
}


void
add_to_postfix (char o)
{
  postfix[k] = o;
  k++;
}