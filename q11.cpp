#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
string s1,s2;
int k=0;
cout<<"Enter the main string: ";
cin>>s1;
cout<<"Enter the jumbled string: ";
cin>>s2;
for (int i = 0; i < s1[i]; i++)
{
	if(s1[i]!=s2[i])
	{
		for(int j=i;s1[j];j++)
		{
			if(s1[i]==s2[j] && s1[j]==s2[i])
			{
			
				swap(s2[i],s2[j]);
				k++;
				cout<<"After swap no. "<<k<<" string is: "<<s2<<endl;
			}
		}
	
	}
	
}

/*
int q=0;
while(q!=s1.length())
{
	
	if(s2[q]!=s1[q])
	{
		for(int i=q+1;s2[i];i++)
		{
			if(s1[q]==s2[i])
				{
					if(s1[i]!=s2[i])
					{
					swap(s2[q],s2[i]);
					cout<<s2<<endl;
					q++;k++;
					break;
					}
				}
		}
	}
	else q++;
}

cout<<s2;
cout<<k;
}*/

for(int i=0;i<s1.length()-1;i++)
{	
	if(s1[i]!=s2[i])
	  for(int j=i+1;j<s1.length();j++)
	{
	   if(s2[j]==s1[i] && s2[j]!=s1[j])
	    { swap(s2[i],s2[j]);
	      k++;
	      cout<<"After swap no. "<<k<<" string is: "<<s2<<endl;

	    }
	}
}
cout<<"Total no. of swap required: "<<k<<endl;
return 0;
}