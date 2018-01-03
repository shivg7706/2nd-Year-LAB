#include<iostream>
using namespace std;
class matrix
{
private:
int n,m;
int a[20][20];
public:
void entry();
void transpose(matrix);
void show();
int check(matrix);
matrix operator *(matrix);
};
void matrix::entry()		//Function for enter of the matrix
{
	int i,j;
	cout<<"Enter the size of the matrix: ";
	cin>>m>>n;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
		cout<<"Enter the element of matrix ("<<i<<","<<j<<")=";
		cin>>a[i][j];
		}
}
void matrix::transpose(matrix m4) //Function for the transposing the matrix
{
m=m4.n;
n=m4.m;
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		a[j][i]=m4.a[i][j];

}
int matrix::check(matrix m3)		//function for check wheather 2 matrix are applicable for multiplication
{
if(n==m3.m)
return 1;
else
return 0;
}
void matrix::show()			//function for printing of matrix
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		cout<<a[i][j]<<" ";
	cout<<"\n";
	}
}
matrix matrix::operator*(matrix m6)		//operator overloading function
{
matrix temp;
temp.m=m;
temp.n=m6.n;
int i,j,k;
for(i=0;i<m;i++)
	for(j=0;j<m6.n;j++)
	{
	temp.a[i][j]=0;
	for(k=0;k<n;k++)
	temp.a[i][j]+=(a[i][k]*m6.a[k][j]);
	}
return temp;
}
int main()
{
matrix m1,m2,m3,m5;		//declaring different object
cout<<"Enter Matrix A\n";
m1.entry();			//m1 for matrix A
cout<<"Matrix A is as\n";	//m2 for transpose of matrix A
m1.show();			//m3 for matrix B
m2.transpose(m1);		//m5 to store multiplied matrix
cout<<"Transpose of Matrix A\n";
m2.show();
cout<<"Enter Matrix B\n";
m3.entry();
cout<<"Matrix B is as\n";
m3.show();
int a=m1.check(m3);
if(a)
{
m5=m1*m3;
cout<<"Product of the matrix A and B is:\n";
m5.show();
}
else
cout<<"Multiplication is not applicable\n";
}
