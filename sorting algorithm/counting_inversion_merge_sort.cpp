#include<bits/stdc++.h>
using namespace std;
int n;
int arr[105];
int mergee(int temp[],int left,int mid,int right){
    int i=left,j=mid,k=left;
    int cnt=0;
    while((i<=mid-1)&& (j<=right)){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
            cnt+=(mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }
    return cnt;
}
int real_merge(int temp[], int low,int high){
    int mid,cnt=0;
    if(low<high){
        mid=(low+high)/2;
        cnt+=real_merge(temp,low,mid);
        cnt+=real_merge(temp,mid+1,high);
        cnt+=mergee(temp,low,mid+1,high);
    }
    return cnt;
}
int merge_sort(){
    int temp[n];
    return real_merge(temp,0,n-1);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int noi=merge_sort();
    cout << noi << endl;
}
