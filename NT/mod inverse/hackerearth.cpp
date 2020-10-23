#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll d,x,y;
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
void egcd(ll a,ll b){
    if(b==0){
        d=a;
        x=1;
        y=0;
    }
    else{
        egcd(b,a%b);
        ll temp=x;
        x=y;
        y= temp - (a/b)*y;
    }
}
ll mod_inv(ll a,ll m){
    egcd(a,m);
    return (x%m+m)%m;
}
int main(){
    ll a,b,c,m;
    cin>>a>>b>>c>>m;
    ll res=modularExponentiation(a,b,m);
    //cout << res << endl;
    ll inv=mod_inv(c,m);
    inv%=m;
    ll ans=((res%m)*(inv%m))%m;
    cout << ans << endl;
    return 0;
}
