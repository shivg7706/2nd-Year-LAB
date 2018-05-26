// Program description
// This program implements Binary Searching

#include<bits/stdc++.h>
using namespace std;

class Program{
private:
    int n,x;
    int *a;
public:
    Program(int k){
        n=k;
        a=new int [k]; 
        for(int i=0;i<k;i++){
            a[i]=rand()/1000000;
        }
    }
    void sorting();
    void binarySearch();
};
void Program::sorting(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}
void Program::binarySearch(){

    int x=rand()/1000000;
    int count = 0,l=0,r=n-1;
    while (l <= r){
        count++;
        int m = l + (r-l)/2;

        // Check if x is present at mid
        if (a[m] == x){
                cout<<"No. of Comparison "<<count<<" ";
                cout<<"Position of the element is "<<m+1<<endl;
                return;
        }

        // If x greater, ignore left half
        if (a[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    cout<<"No. of Comparison "<<count<<" \n";
    cout<<"Element not found\n";
}
int main(){
    int size;
    cout<<"Enter the Size of the array: ";
    cin>>size;
    Program p(size);
    p.sorting();
    p.binarySearch();
}