#include<bits/stdc++.h>
using namespace std;
int n;
int arr[105];
int part(int low,int high){
    int pivot=arr[low];
    int i=low,j=high;
    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quick(int low,int high){
    if(low<high){
        int p=part(low,high);
        quick(low,p);
        quick(p+1,high);
    }
}
int main(){
    cout << "Enter number of elements: ";
    cin>>n;
    cout << "Enter "<< n << "elements respectively: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr[n]=1000000;///boro value as a infinity;
    quick(0,n);
    for(int i=0;i<n;i++)cout << arr[i] << " ";
    cout << endl;
}
