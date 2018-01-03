#include<iostream>
using namespace std;
class matrix
{
private:
int n;
int a[10][10];
public:
void entry();
void transpose();
void printb();
void printa();
void operator *(matrix);
};
void matrix::entry()
{
	int i,j;
	cout<<"Enter the size of the matrix: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		cout<<"Enter the element of matrix ("<<i<<","<<j<<")=";
		cin>>a[i][j];
		}
	}
}
void matrix::transpose()
{
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
		swap(a[i][j],a[j][i]);
}
void matrix::printb()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<a[i][j]<<" ";
	cout<<"\n";
	}
}
void matrix::operator*(matrix m)
{
int i,j,k;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	m.a[i][j]=0;
	for(k=0;k<n;k++)
	.a[i][j]+=(a[i][k]*m.a[k][j]);
	}

}
int main()
{
matrix m1,m2,m3;
cout<<"Enter Matrix A\n";
m1.entry();
cout<<"Matrix A is as\n";
m1.printb();
m1.transpose();
cout<<"Matrix after transpose\n";
m1.printb();
cout<<"Enter Matrix B\n";
m2.entry();
cout<<"Matrix B is as\n";
m2.printb();
m3=m1*m2;
cout<<"Product of the matrix is:\n";
m3.printb();
}
