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
matrix operator *(matrix);
};
void matrix::entry()
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
void matrix::transpose(matrix m4)
{
m=m4.n;
n=m4.m;
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		a[j][i]=m4.a[i][j];

}
void matrix::show()
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		cout<<a[i][j]<<" ";
	cout<<"\n";
	}
}
matrix matrix::operator*(matrix m6)
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
matrix m1,m2,m3,m5;
cout<<"Enter Matrix A\n";
m1.entry();
cout<<"Matrix A is as\n";
m1.show();
m2.transpose(m1);
cout<<"Transpose of Matrix A\n";
m2.show();
cout<<"Enter Matrix B\n";
m3.entry();
cout<<"Matrix B is as\n";
m3.show();
m5=m1*m3;
cout<<"Product of the matrix A and B is:\n";
m5.show();
}
