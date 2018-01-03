#include<stdio.h>
#include<stdlib.h>
struct node			//creation of a node
{
int data;
struct node *right,*down;       // with 2 pointers right & down
}*head,*c,*r,*t;
void main()
{
head=NULL;			//initializing head to NULL
int i,j,n,p;
char s,ch='y';
while(ch=='y'||ch=='Y')
{
printf("Enter the data:");
struct node* temp=(struct node*)malloc(sizeof(struct node));	//allocating memory to node
scanf("%d",&temp->data);
temp->right=NULL;
temp->down=NULL;
if(head==NULL)
{
	head=temp;
	c=temp;
}
else
{
	c->right=temp;
	c=temp;
}
printf("Do you want to add more nodes:(Y/N)");
scanf(" %c",&ch);
}
c=head;
printf("Final linked list is: ");	
while(c!=NULL)				//displaying final linked list that has been formed
{
	printf("%d ",c->data);
	c=c->right;
}
printf("\n");
printf("Enter the no. of element for the rows: "); //entry of no. of elements for the 1 row
scanf("%d",&n);
c=r=head;
for(i=0;i<n;i++)		
{
r->down=r;						//setting down pointer of first row to point itself
r=r->right;
}
while(r!=NULL)						
{	
	t=c->down;					//swaping the address of down pointer so that next row pointed by above and present to top
	c->down=r;
	r->down=t;
	c=c->right;
	r=r->right;
}
c=head;
while(c!=NULL)
{
i=0;
while(i<n&&c!=NULL)					// printing the updated mesh formed
{
	printf("%d  ",c->data);
	c=c->right;
i++;
}
printf("\n");
}
ch='y';
while(ch=='y'||ch=='Y')
{
printf("Enter the position: ");				//entering the position for traversal
scanf("%d",&p);
printf("Enter the char for traversal: ");		//entering the path for traversal
scanf(" %c",&s);

r=head;
for(i=1;i<p;i++)
r=r->right;
c=r;
if(s=='r')
		{
		while(r!=NULL)
		{
		if(r->right==NULL)
		{printf("OVER\n");break;}
		r=r->right;
		printf("%d ",r->data);
		}
		}
else if(s=='d')
		while(r->down!=c)
		{
		r=r->down;
		printf("%d ",r->data);
		}
else
printf("Wrong Keyword");
printf("Do you want to continue:(Y/N)");
scanf(" %c",&ch);
}
}
