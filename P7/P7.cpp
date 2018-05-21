#include<bits/stdc++.h>
using namespace std;
class MergeSort{
    int n;
    int *arr;
public:
    MergeSort(int n){
        this->n = n;
        arr = new int [n];
    }
    void input(){
        cout<<"Enter the elements:\n";
        for(int i=0;i<n;i++)
            cin>>arr[i];
    }
    void merging(int low, int mid, int high){
    
    int n1 = mid - low + 1;
    int n2 =  high - mid;
 
    int Leftarr[n1], Rightarr[n2];
    for (int i = 0; i < n1; i++)
        Leftarr[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        Rightarr[j] = arr[mid + 1+ j];
 
    
    int i = 0, j= 0, k = low; 
    while (i < n1 && j < n2){
        if (Leftarr[i] <= Rightarr[j]){
            arr[k] = Leftarr[i];
            i++;
        }else{
            arr[k] = Rightarr[j];
            j++;
        }
        k++;
    }
        while (i < n1){
            arr[k] = Leftarr[i];
            i++;
            k++;
        }
        while (j < n2){
            arr[k] = Rightarr[j];
            j++;
            k++;
        }
    }
 
    
    void sorting(int low, int high){
        if(low < high){
            int mid = (low + high)/2;
            sorting(low, mid);
            sorting(mid+1, high);

            merging(low, mid, high);
        }       
    }
    void printing(){
        cout<<"Array after sorting is: ";
        for (int i = 0; i < n; ++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){

    int size;
    cout<<"Enter the no. of elments: ";
    cin>>size;
    MergeSort m(size);
    m.input();
    m.sorting(0, size-1);
    m.printing();
}