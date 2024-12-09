#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node* head=NULL;
void insertBeginning(int value);
void insertEnd(int value);
void insertAtPosition(int value,int position);
void deleteBeginning();
void deleteEnd();
void deleteAtPosition(int position);
void display();
void display()
{
	if(head==NULL)
	{
		printf("\nThe list is Empty\n");
		return;
	}
	struct node* temp=head;
	printf("\nLinked List Elements are:");
	while(temp->next!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
void insertBeginning(int value)
	{
		struct node* newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==NULL)
			{
				printf("\nMemory Allocation Failed");
				return;
			}
			newnode->data=value;
			newnode->next=head;
			head=newnode;
			printf("\n%d inserted at the beginning",value);
			display();
	}
void insertEnd(int value)
	{
		 struct node* newnode=(struct node*)malloc(sizeof(struct node));
		 if(newnode==NULL)
                        {
                                printf("\nMemory Allocation Failed");
                                return;
                        }
		newnode->data=value;
                newnode->next=NULL;
		if(head==NULL)
		{
			head=newnode;
		}
		else
		{
			struct node* temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
				temp->next=newnode;
		}
			printf("\n %d inserted at the end",value);
			display();
	}
void insertAtPosition(int value,int position)
	{
		if(position<1)
		{
			printf("\nInvalid position\n");
			return;
		}
		if(position==1)
		{
			insertBeginning(value);
			return;
		}
		 struct node* newnode=(struct node*)malloc(sizeof(struct node));
                 if(newnode==NULL)
                        {
                                printf("\nMemory Allocation Failed");
                                return;
                        }
			newnode->data=value;
			struct node* temp=head;
			for(int i=1;i<position-1 && temp!=NULL;i++)
			{
				temp=temp->next;
			}
			if(temp==NULL)
			{
			printf("\nPosition %d is out of bound.Node not inserted \n",position);
			free(newnode);
			return;
			}
			newnode->next=temp->next;
			temp->next=newnode;
			printf("\n%d inserted at position %d\n",value,position);
			display();
		}
void deleteBeginning()
{
		if(head==NULL)
		{
			printf("\nList is Empty:Nothing to delete\n");
			return;
		}
		struct node* temp=head;
		head=head->next;
		free(temp);
		printf("\nNode deleted from Beginning\n");
		display();
	}
void deleteEnd()
	{
		if(head==NULL)
                {
                        printf("\nList is Empty:Nothing to delete\n");
                        return;
                }
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
			printf("\nNode deleted from the end\n");
			display();
			return;
		}
		struct node* temp=head;
		struct node* prev=NULL;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		free(temp);
		prev->next=NULL;
		printf("\nNode deleted from the end\n");
		display();
	}
void deleteAtPosition(int position)
{
	if(position<1)
                {
                        printf("\nInvalid position\n");
                        return;
                }
                if(position==1)
                {
			deleteBeginning();
			return;
		}
		struct node* temp=head;
		struct node* prev=NULL;
		for(int i=1;i<position && temp!=NULL;i++)
		{
			prev=temp;
			temp=temp->next;
		}
			if(temp==NULL)
			{
					printf("\nposition %d is out of bounds.Node not deleted\n",position);
					return;
			}
			prev->next=temp->next;
			free(temp);
			printf("\nNode deleted from position %d",position);
			display();
}
int main()
{
	int choice,subchoice,value,position;
	do
	{
		printf("\nChoose an operation:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nChoose Insertion Method:\n1.Insertion at Beginning\n2.Insertion at End\n3.Insertion at Specific Position\n");
				scanf("%d",&subchoice);
				switch(subchoice)
				{
					case 1:
						printf("\nEnter the value to insert at beginning:");
						scanf("%d",&value);
						insertBeginning(value);
						break;
					case 2:
						printf("\nEnter the value to insert at End:");
                                                scanf("%d",&value);
                                                insertEnd(value);
                                                break;
					case 3:
						printf("\nEnter position and value to insert at specific position:");
                                                scanf("%d%d",&position,&value);
                                                insertAtPosition(value,position);
                                                break;
					default:
						printf("\nInvalid Insertion Choice!");
				}
				break;
		case 2:
                                printf("\nChoose Deletion Method:\n1.Deletion from  Beginning\n2.Deletion  at End\n3.Deletion at Specific Position\n");
                                scanf("%d",&subchoice);
                                switch(subchoice)
				{
					case 1:
						deleteBeginning();
						break;
					case 2:
						deleteEnd();
						break;
					case 3:
						printf("\nEnter the position to delete from");
						scanf("%d",&position);
						deleteAtPosition(position);
						break;
					default:
						printf("\nInvalid Deletion Choice!");
				}
				break;
		case 3:
				display();
				break;
		case 4:
				exit(0);
				break;
		}
	}while(choice!=4);
	return 0;
}
