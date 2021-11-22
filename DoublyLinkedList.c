#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
}*head,*tail,*temp,*prev;
void create();
void delete_first();
void delete_middle(int);
void delete_end();
void display();
void insert_first(int);
void insert_end(int);
void insert_middle(int,int);

int main(){
    int n,x,y,ch,res,del;
    char str[40];
    do{
    printf("enter the choice :\n 1)create \n 2)insert at first \n 3)insert at end \n 4)insert at middle \n5) delete at first \n 6)delete at end \n7)delete at middle\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        create();
        display();
        break;
        case 2:{
            printf("enter the data to insert :");
            scanf("%d",&x);
            insert_first(x);
            display();
        }
        break;
        case 3:{
            printf("enter the data to insert :\n");
            scanf("%d",&x);
            insert_end(x);
            display();
        }
        break;
        case 4:{
            printf("enter the data to insert : ");
            scanf("%d",&x);
            printf("enter the prev data  : ");
            scanf("%d",&y);
            insert_middle(x,y);
            display();
        }
        break;
        case 5:{
            delete_first();
            display();
        }
        break;
        case 6:{
            delete_end();
            display();
        }
        break;
        case 7:{
            printf("enter the data to delete : ");
            scanf("%d",&del);
            delete_middle(del);
            display();
        }
        break;
    }
    printf("do you want to continue(type anything to continue and \"END\" to end) : ");
    scanf("%s",str);
    res=strcmp(str,"END");
    }while(res!=0);
    return 0;
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("data is %d\n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void create()
{
    int n,i;
    printf("Enter the total number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d",&temp->data);
        temp->prev=NULL;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        
    }
}
void insert_first(int x){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else{
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
 void insert_end(int x){
     struct node *t=head;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=NULL;
     temp->prev=NULL;
     while(t->next!=NULL)
        t=t->next;
    t->next=temp;
    temp->prev=t;
 }
 
 void insert_middle(int x,int y){
     struct node *t=head;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=x;
     temp->prev=NULL;
     temp->next=NULL;
     while(t->data!=y)
        t=t->next;
    temp->next=t->next;
    temp->prev=t;
    t->next->prev=temp;
    t->next=temp;
 }
void delete_first()
{
    if(head==NULL)
    {
        printf("The linked list is empty");
        return;
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}
void delete_middle(int n)
{
    if(head==NULL)
    {
        printf("The linked list is empty");
        return;
    }
    else
    {
        temp=head;
        while(temp->data!=n)
        {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        temp->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}
void delete_end()
{
    if(head==NULL)
    {
        printf("The linked list is empty");
        return;    
    }
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}


/*
		OUTPUT
		
enter the choice :
 1)create
 2)insert at first
 3)insert at end
 4)insert at middle
5) delete at first
 6)delete at end
7)delete at middle
1
Enter the total number of elements : 3
Enter the data : 10
Enter the data : 20
Enter the data : 30
data is 10
data is 20
data is 30

do you want to continue(type anything to continue and "END" to end) : r
enter the choice :
 1)create
 2)insert at first
 3)insert at end
 4)insert at middle
5) delete at first
 6)delete at end
7)delete at middle
2
enter the data to insert :40
data is 40
data is 10
data is 20
data is 30

do you want to continue(type anything to continue and "END" to end) : r
enter the choice :
 1)create
 2)insert at first
 3)insert at end
 4)insert at middle
5) delete at first
 6)delete at end
7)delete at middle
3
enter the data to insert :
50
data is 40
data is 10
data is 20
data is 30
data is 50

do you want to continue(type anything to continue and "END" to end) : r
enter the choice :
 1)create
 2)insert at first
 3)insert at end
 4)insert at middle
5) delete at first
 6)delete at end
7)delete at middle
4
enter the data to insert : 60
enter the prev data  : 20
data is 40
data is 10
data is 20
data is 60
data is 30
data is 50

do you want to continue(type anything to continue and "END" to end) : r
enter the choice :
 1)create
 2)insert at first
 3)insert at end
 4)insert at middle
5) delete at first
 6)delete at end
7)delete at middle
5
data is 10
data is 20
data is 60
data is 30
data is 50

do you want to continue(type anything to continue and "END" to end) : r
enter the choice :
 1)create
 2)insert at first
 3)insert at end
 4)insert at middle
5) delete at first
 6)delete at end
7)delete at middle
6
data is 10
data is 20
data is 60

do you want to continue(type anything to continue and "END" to end) : r
enter the choice :
 1)create
 2)insert at first
 3)insert at end
 4)insert at middle
5) delete at first
 6)delete at end
7)delete at middle
7
enter the data to delete : 20
data is 10
data is 60

do you want to continue(type anything to continue and "END" to end) : END


*/
