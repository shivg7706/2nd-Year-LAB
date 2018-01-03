#include <stdio.h>
void main()
{
int a[10][10],n,c,d,i,j;                      //Declration of variables
char ch='y';
while(ch=='y'||ch=='Y')
{
printf("\nEnter the size of the square matrix\n");
scanf("%d",&n);					     //order input
if(n>0)
{
printf("\nEnter the elements of the matrix\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
	printf("[%d,%d]-",i+1,j+1);
        scanf("%d",&a[i][j]);                       //input elements
    }
}
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        printf(" %d ",a[i][j]);                     //printing of final matrix
    }
printf("\n\n");
}
c=0;
d=n-1;
while(c<=n/2 && d>=n/2)
{
	for(i=c;i<d;i++)			//upper row 		
		printf(" %d :",a[c][i]);
	for(i=c;i<d;i++)			//right side column
		printf(" %d :",a[i][d]); 
	for(i=d;i>c;i--)			//lower row
		printf(" %d :",a[d][i]);
	for(i=d;i>c;i--)			//left side column
		printf(" %d :",a[i][c]);
c++;
d--;
}
if(n%2==1)   				//center element if present
printf(" %d",a[n/2][n/2]);
}
else
printf("Order is wrong\n ");
printf("Do You Continue:/Y or N/");
scanf(" %c",&ch);
}
}
