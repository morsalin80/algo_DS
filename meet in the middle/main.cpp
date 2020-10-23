#include<bits/stdc++.h>
using namespace std;
int x[200005],y[200005];
void calc(int a[],int x[],int n,int c){
    for(int i=0;i<(1<<n);i++){

        int s=0;
        for(int j=0;j<n;j++){
           if(i&(1<<j)){
                s+=a[j+c];
           }
        }
        x[i]=s;
    }
}
int mim(int a[],int n,int s){
    calc(a,x,n/2,0);
    calc(a,y,(n-n/2),n/2);
    int szx=(1<<(n/2));
    int szy=(1<<(n-n/2));
    sort(y,y+szy);
    int maxx=0;
    for(int i=0;i<szx;i++){
        if(x[i]<=s){
            int p=lower_bound(y,y+szy,s-x[i])-y;
            if(p==szy || y[p]!=(s-x[i]))p--;
            if(maxx<x[i]+y[p]){
                maxx=x[i]+y[p];
            }
        }
    }
    return maxx;
}
int main(){
    int a[] = {3, 34, 4, 12, 5, 2};
    int n=sizeof(a)/sizeof(a[0]);
    int s = 10;
    cout << mim(a,n,s)<< endl;
}
