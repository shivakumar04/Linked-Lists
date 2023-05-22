#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

void insertion_at_beginning(int data)
{
    struct node *newnode;
    newnode=(struct node *)malloc(1*sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

void insertion_at_end(int data)
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(1*sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertion_at_position(int data, int pos)
{
    struct node*newnode,*temp;
    newnode=(struct node *)malloc(1*sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    temp=head;
    while(pos-2)
    {
        temp = temp->next;
        pos--;
    }
    newnode->next = temp->next;
    temp->next=newnode;
}

void delete_at_beginning()
{
    struct node *delnode,*temp;
    temp=head;
    if(head==NULL)
    {
        printf("no node to delete");
    }
    else
    {               
        delnode=head;
        head=head->next;
        free(delnode);
    }
}

void delete_at_position(int pos)
{
    struct node *temp,*delnode;
    temp = head ;
    while(pos-2)
    {
        temp= temp->next;
        pos--;
    }
    delnode=temp->next;
    temp->next = temp->next->next;
    free(delnode);
}

void delete_at_end()
{
    struct node *delnode,*temp;
    temp=head;
    if(head==NULL)
    {
        printf("no node to delete");
    }
    else if(head->next==NULL)
    {
        delnode=head;
        head = NULL;
        free(delnode);
    }
    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;

        }
        delnode=temp->next;
        temp->next=NULL;
        free(delnode);
    }
} 

void display()
{
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}


int main()
{
	int ch=0;
	char ch1;
    printf("\nEnter 1 - Insertion at ending of the  linked list");
	printf("\nEnter 2 - Insertion at beginning of the linked list");
	printf("\nEnter 3 - Insertion at a position in the linked list");
	printf("\nEnter 4 - Deletion at ending of the  linked list");
	printf("\nEnter 5 - Deletion at beginning of the linked list");
	printf("\nEnter 6 - Deletion at a position in the linked list");
	printf("\nEnter 7 - Display linked list");
	printf("\nEnter 8 - Exit");
	while(1)
	{
		printf("\nenter the choice of the operation to perform on linked list:- ");
		scanf("%d",&ch);
		switch(ch)
		{
            case 1:
			{
				int data;
                printf("\nenter data:- ");
                scanf("%d",&data);
				insertion_at_end(data);
			    break;
			}
			case 2:
			{
                int data;
                printf("\nenter data:- ");
                scanf("%d",&data);
				insertion_at_beginning(data);
			    break;
			}
			case 3:
			{
				int value,pos;
				printf("\nenter data:- ");
				scanf("%d",&value);
                printf("\nenter position:- ");
                scanf("%d",&pos);
				insertion_at_position(value,pos);
				break;
			}
			case 4:
			{
				delete_at_end();
				break;
			}
			case 5:
			{
				delete_at_beginning();
				break;
			}
			case 6:
			{
                int pos;
                printf("\nenter position:- ");
                scanf("%d",&pos);
				delete_at_position(pos);
				break;
			}
			
			case 7:
			{
				display();
				break;
			}
			case 8:
			{
                printf("****End of the program****");
				exit(1);
				{
					default:printf("\n****please enter correct choice****\n");
				}
			}	
		}
	}
}