#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *right,*down;
}*head,*c,*r,*t;
void main()
{
head=NULL;
int i,j,n,p;
char s,ch='y';
while(ch=='y'||ch=='Y')
{
printf("Enter the data:");
struct node* temp=(struct node*)malloc(sizeof(struct node));
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
while(c!=NULL)
{
	printf("%d ",c->data);
	c=c->right;
}
printf("\n");
printf("Enter the no. of element for the rows: ");
scanf("%d",&n);
c=r=head;
for(i=0;i<n;i++)
{
r->down=r;
r=r->right;
}
while(r!=NULL)
{	
	t=c->down;
	c->down=r;
	r->down=t;
	c=c->right;
	r=r->right;
}
c=head;
while(c!=NULL)
{
i=0;
while(i<n&&c!=NULL)
{
	printf("%d  ",c->data);
	c=c->right;
i++;
}
printf("\n");
}

printf("Enter the position: ");
scanf("%d",&p);
printf("Enter the char for next position: ");
scanf(" %c",&s);
r=head;
for(i=1;i<p;i++)
r=r->right;
if(s=='r')
		{
		r=r->right;
		printf("%d\n",r->data);
		}
else if(s=='d')
		{
		r=r->down;
		printf("%d\n",r->data);
		}
else
printf("Wrong Keyword");
}

