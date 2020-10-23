#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll modularExponentiation(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
bool MR_prime(ll n){
    if(n%2==0 || n==3)return true;
    if(n<=1 && n==4)return false;
    ll d=n-1;
    ll r=1;
    while(d%2==0){
        d/=2;
    }
    cout << r << " "<< d << endl;
    ll k=10;
    for(int i=0;i<k;i++){
        ll a=(rand()+2)%(n-4);
        cout << a << " :a: \n";
        ll x=modularExponentiation(a,d,n);
        ll dd=d;
        if(x==1 && x==n-1)continue;
        while (dd != n-1)
        {
            cout << x << " ";
            x = (x * x) % n;
            dd *= 2;
            if (x == n-1) continue;
            if (x == 1)   return false;
        }
        cout << endl;
        //return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(MR_prime(n)){
            cout << "prime\n";
        }
        else {
            cout << "composite\n";
        }
    }
}
