// Program description
// This program performs inorder, preorder and postorder traversals on a tree.

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left,*right;
}*root=NULL;
node* getnode(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
node* insert(node* root, int i, int n)
{
	if(i<n)
	{
		int d;
		cout<<"Enter the data "<<i+1<<" node: ";
		cin>>d;
		node *temp = getnode(d);
		root = temp;
		root->left = insert(root->left, 2*i+1, n);
		root->right = insert(root->right, 2*(i+1), n);
	}
	return root;
}
void inOrder(node* root)
{
	if(root != NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
void postOrder(node* root)
{
	if(root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}
void preOrder(node* root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void levelOrder(node* root)
{
	
	if(root == NULL)
	 	return ;
	queue <node *> q;
	q.push(root);
	while(!q.empty())
	{
		node *curr=q.front();
		cout<<curr->data<<" ";
		if(curr->left!=NULL)q.push(curr->left);
		if(curr->right!=NULL)q.push(curr->right);
		q.pop();
	}
}
int main()
{
	int value,n;
	cout<<"Enter the no. of nodes of binary tree: \n";
	cin>>n;
	node *root=insert(root, 0, n);
	cout<<"InOrder: ";
	inOrder(root);
	cout<<"\nPreOrder: ";
	preOrder(root);
	cout<<"\nPostOrder: ";
	postOrder(root);
	cout<<"\nLevelOrder: ";
	levelOrder(root);
	cout<<endl;


}

