#include<bits/stdc++.h>
using namespace std;

const int size=200;

char infix[size],postfix[size],Stack[size];
int Stack2[size];
int top=-1,Top=-1;

int priority(char ch){
	switch(ch){
		case'$':return 5;
		case'/':return 4;
		case'*':return 4;
		case'+':return 3;
		case'-':return 3;
		default:return 0;
	}
}

void push(char ch){
	if(top!=size-1){
		top++;
		Stack[top]=ch;
	}
}

void Push(int a){
	if(Top!=size-1){
		Top++;
		Stack2[Top]=a;
	}
}

int brackets(char *s){
	int lb=0,rb=0;
	for(int i=0;s[i];i++){
		if(s[i]=='(')
			lb++;
		else 
			if(s[i]==')')
				rb++;
	}
	if(lb==rb)
		return 0;
	else 
		if(lb < rb)
			return 1;
	else 
		return -1;
}

char pop(){
	char r;
	if(top!=-1){
		r=Stack[top];
		top--;
		return r;
	}
	else 
		return '#';
}

int Pop(){
	int w;
	if(Top!=-1){
		w=Stack2[Top];
		Top--;
		return w;
	}


}
char topelement(){
	char ch;
	if (top!=-1)
		ch=Stack[top];
	else ch='#';

	return ch;
}

void evaluation(char *s){
	for(int i=0;s[i]!='\0';i++){
		if(isdigit(s[i]))
			Push(s[i]-'0');
		else{
            int v1 = Pop();
            int v2 = Pop();
						
            switch (s[i]){
             	case '+': Push(v1 + v2); break;
             	case '-': Push(v2 - v1); break;
             	case '*': Push(v1 * v2); break;
             	case '/': Push(v2/v1);   break;
            }
        }
	}
	cout<<"Answer is "<<Pop()<<endl;
}

int main(){
	char ele,elem,st[2];
	int prep,pre,popped,j=0,check=0;
	strcpy(postfix,"");
	cout<<"Enter the infix string: ";
	cin>>infix;
	check=brackets(infix);
	if(check!=0){
		cout<<"Brackets are not balanced";
		return 0;
	}
	for(int i=0;infix[i]!='\0';i++){
		if(infix[i]!='(' && infix[i]!=')' && infix[i]!='$' && infix[i]!='*' && infix[i]!='/' && infix[i]!='+' && infix[i]!='-')
			postfix[j++]=infix[i];

		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')'){
			while((popped=pop())!='('){
				postfix[j++]=popped;
			}
		}
		else{
			elem=infix[i];
			pre=priority(elem);
			ele=topelement();
			prep=priority(ele);
			if(pre>prep) push(elem);
			else{
				while(prep>=pre){
					if(ele=='#')break;
					popped=pop();
					ele=topelement();
					postfix[j++]=popped;
					prep=priority(ele);
				}
				push(elem);
			}
		}
	}
	while((popped=pop())!='#')
		postfix[j++]=popped;
	postfix[j]='\0';
	cout<<"Postfix expression of given expression "<<postfix<<endl;
	evaluation(postfix);
	return 0;
}
