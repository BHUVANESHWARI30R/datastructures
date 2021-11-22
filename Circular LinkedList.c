#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  int data;
  struct node *next;
} *head, *temp, *tail;


void
creation ()
{
  int choice = 1;
  head = 0;
  while (choice)
    {
      temp = (struct node *) malloc (sizeof (struct node));
      printf ("enter the data : ");
      scanf ("%d", &temp->data);
      temp->next = head;
      if (head == NULL)
	{
	  head = tail = temp;
	}
      else
	{

	  tail->next = temp;
	  tail = temp;
	}
      printf ("\ndo you want to continue (0 for no / 1 for yes)");
      scanf ("%d", &choice);
    }
  printf ("\n\n");
}

void
insert_at_beginning (int n)
{
  temp = (struct node *) malloc (sizeof (struct node));
  temp->data = n;
  // temp->next=NULL;
  if (head == NULL)
    head = temp;
  else
    {
      tail->next = temp;
      temp->next = head;
      head = temp;
    }
}

void
insert_at_middle (int n1, int pre)
{
  temp = (struct node *) malloc (sizeof (struct node));
  temp->data = n1;
  temp->next = NULL;
  struct node *t = head;
  while (t->data != pre)
    t = t->next;
  temp->next = t->next;
  t->next = temp;
}

void
insert_at_end (int x)
{
  temp = (struct node *) malloc (sizeof (struct node));
  temp->data = x;
  // temp->next=head;
  struct node *t = head;
  while (t->next != head)
    t = t->next;
  t->next = temp;
  temp->next = head;
}

void
delete_at_first ()
{
  if (head == NULL)
    printf ("list empty");
  // else if(head->next==NULL)
  // {
  //     free(head);
  //     head=NULL;
  // }
  else
    {
      temp = head;
      head = head->next;
      tail->next = head;
      free (temp);
    }
}

void
delete_at_middle (int x)
{
  struct node *t;
  temp = head;
  while (temp->next->data != x)
    temp = temp->next;

  t = temp->next;
  temp->next = t->next;
  free (t);
}

void
delete_at_end ()
{
  struct node *t;
  temp = head;
  while (temp->next != head)
    {
      t = temp;
      temp = temp->next;
    }
  if (temp == head)
    head = NULL;
  else
    t->next = head;
  free (temp);
}

void
display ()
{
  temp = head;
  while (temp->next != head)
    {
      printf ("data is : %d\n", temp->data);
      temp = temp->next;
    }
  printf ("data is : %d\n", temp->data);
}

int
main ()
{
  int n, n1, pre, choice, del, res;
  //char str[10] = {'E','N','D'};
  char str1[40];
  creation ();
  do
    {
      printf
	("enter the choice \n 1)insertion at beginning \n 2)insertion at middle \n 3)insertion at end \n 4)deletion at begining \n 5)deletion at middle \n 6)deletion at end \n");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  {
	    printf ("enter the number to insert at beggining : ");
	    scanf ("%d", &n);
	    insert_at_beginning (n);
	    display ();
	  }
	  break;

	case 2:
	  {
	    printf ("enter the number to insert at middle : ");
	    scanf ("%d", &n1);
	    printf ("enter the before number of desired position : ");
	    scanf ("%d", &pre);
	    insert_at_middle (n1, pre);
	    display ();
	  }
	  break;

	case 3:
	  {
	    printf ("enter the number to insert at end : ");
	    scanf ("%d", &n);
	    insert_at_end (n);
	    display ();
	  }
	  break;

	case 4:
	  {
	    delete_at_first ();
	    printf ("first node deleted successfully\n");
	    display ();
	  }
	  break;

	case 5:
	  {
	    printf ("enter the data to delete : ");
	    scanf ("%d", &del);
	    delete_at_middle (del);
	    printf ("node deleted successfully\n\n");
	    display ();
	  }
	  break;

	case 6:
	  {
	    delete_at_end ();
	    printf ("last node deleted successfully\n\n");
	    display ();
	  }
	default:
	  printf ("enter correct option");
	}
      printf ("do you want to continue (type \"END\" to end): ");
      scanf ("%s", str1);
      res = strcmp (str1, "END");
    }
  while (res != 0);
  return 0;
}

/*

		OUTPUT
		
enter the data : 10

do you want to continue (0 for no / 1 for yes)1
enter the data : 20

do you want to continue (0 for no / 1 for yes)1
enter the data : 30

do you want to continue (0 for no / 1 for yes)0


enter the choice
 1)insertion at beginning
 2)insertion at middle
 3)insertion at end
 4)deletion at begining
 5)deletion at middle
 6)deletion at end
1
enter the number to insert at beggining : 40
data is : 40
data is : 10
data is : 20
data is : 30
do you want to continue (type "END" to end): r
enter the choice
 1)insertion at beginning
 2)insertion at middle
 3)insertion at end
 4)deletion at begining
 5)deletion at middle
 6)deletion at end
2
enter the number to insert at middle : 50
enter the before number of desired position : 20
data is : 40
data is : 10
data is : 20
data is : 50
data is : 30
do you want to continue (type "END" to end): r
enter the choice
 1)insertion at beginning
 2)insertion at middle
 3)insertion at end
 4)deletion at begining
 5)deletion at middle
 6)deletion at end
3
enter the number to insert at end : 60
data is : 40
data is : 10
data is : 20
data is : 50
data is : 30
data is : 60
do you want to continue (type "END" to end): r
enter the choice
 1)insertion at beginning
 2)insertion at middle
 3)insertion at end
 4)deletion at begining
 5)deletion at middle
 6)deletion at end
4
first node deleted successfully
data is : 10
data is : 20
data is : 50
data is : 30
do you want to continue (type "END" to end): r
enter the choice
 1)insertion at beginning
 2)insertion at middle
 3)insertion at end
 4)deletion at begining
 5)deletion at middle
 6)deletion at end
5
enter the data to delete : 50
node deleted successfully

data is : 10
data is : 20
data is : 30
do you want to continue (type "END" to end): r
enter the choice
 1)insertion at beginning
 2)insertion at middle
 3)insertion at end
 4)deletion at begining
 5)deletion at middle
 6)deletion at end
6
last node deleted successfully

data is : 10
data is : 20
enter correct optiondo you want to continue (type "END" to end): END

*/
