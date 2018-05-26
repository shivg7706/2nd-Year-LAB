#include<bits/stdc++.h>
struct node{
	int data;
	node *next;
	
};
using namespace std;
int main()
{
	cout<<"Enter the size\n";
	int n;
	cin>>n;
	int a[n][n],b[n];
	node *head[n];
	for(int i=0;i<n;i++){
		head[i] = NULL;
	}
	cout<<"Enter the values of nodes\n";
	for(int i=0;i<n;i++)
		cin>>b[i];
	cout<<"Enter the Adjaceny Matrix\n";
	for(int i=0; i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];

	for(int i=0; i<n;i++){
		node *c;
		node *temp = new node();
		temp->next= NULL;
		if(head[i] == NULL){
			temp->data = b[i];
			head[i] = temp;
			c = temp;
		}
		for(int j=0;j<n;j++){
			
			if(a[i][j] == 1){
				node *temp = new node();
				temp -> data = b[j];
				temp->next = NULL;
				c->next = temp;
				c = temp;
			}
		}		
	}
	for(int i = 0;i<n;i++){

		node *c = head[i];
		while(c!=NULL){
			cout<<c->data<<" ";
			c = c->next;
		}
		cout<<endl;
	}
	return 0;
}