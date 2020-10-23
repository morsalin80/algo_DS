#include<bits/stdc++.h>
using namespace std;
const int maxn=1000006;
int cnt;
int chk[maxn+5];
void seive(int n){
    if(n>1)cnt++; // for 2
    for(int i=4;i<=n;i+=2){
        chk[i]=1;
    }
    for(int i=3;i*i<=n;i+=2){
        if(chk[i]==0){
            for(int j=i+i;j<=n;j+=i){
                chk[j]=1;
            }
        }
    }
    for(int i=3;i<=n;i+=2){
        if(chk[i]==0)cnt++;
    }
}
int main()
{
    int n;
    cin>>n;
    seive(n);
    cout << cnt << endl;
    return 0;
}
