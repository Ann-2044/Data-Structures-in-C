#include<stdio.h>
#include<stdlib.h>
struct node 
{
        int data;
        struct node *link;
};
struct node *top=NULL;
void search()
{
	struct node* temp;
        int f=0;
        if(top==NULL)
                printf("\nThe stack is empty,search not posssible.\n");
                else
                {
                        temp=top;
                        int data;
                        printf("Enter the item to search:");
                        scanf("%d",&data);
                        while(temp!=NULL)
                        {
                                if(temp->data==data)
                                {
                                        printf("%d is present in the stack\n",data);
                                        f=1;
                                }
                                temp=temp->link;
                        }
                        if(f==0)
                                printf("the %d element not present in the stack\n",data);
                }
}

void display()
{
        struct node *temp;
        int count=0;
        temp=top;
        if(top==NULL)
        {
                printf("UNDERFLOW");
        }
        else
        {
                printf("Stack Elements are:");   
	       do
                {
                        printf("%d->",temp->data);
                        temp=temp->link;
                }while(temp!=NULL);
		printf("NULL\n");
        }
}
void push()
{
        int item;
        struct node *newNode;
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the item to be inserted\n");
        scanf("%d",&item);
        newNode->data=item;
        newNode->link=top;
        top=newNode;
        printf("%d pushed elements in stack\n",item);
}
void pop()
{
	struct node *temp;
	int item;
	if(top==NULL)
        {
                printf("UNDERFLOW");
        }
	else
	{
	item=top->data;
	temp=top;
	top=top->link;
	free(temp);
	printf("\n %d popped element",item);
}
}
void main()
{
	int ch;
	do{
	printf("\n1.Push\n2.pop\n3.display\n4.Search\n5.Exit\n");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: display();
			break;
		case 4: search();
			break;
		case 5: exit(0);
			break;
		default:  printf("INVALID ENTRY\n");
	}
	}while(ch!=5);
}
