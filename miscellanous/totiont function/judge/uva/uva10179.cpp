/// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define IOS ios::sync_with_stdio(false);
using namespace std;
const long long MOD = 1000000007;
template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}

bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
bool prime(ll n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
void phi(ll n)
{
    ll i,mul=1,holder,fre=0;
    if(prime(n)) mul = n-1;
    else{
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0){
                    n/=i;
                    holder = i;
                    fre++;
            }
            mul*=(pow(holder,fre-1))* (holder-1);
            fre=0;
        }
    }
    if(n!=1)
    {
        mul*=(n-1);
    }
    }
    cout << mul << endl;
}
int main()
{
	IOS
    while(1)
    {
        ll n;
        cin>>n;
        if(n==0) break;
        if(n==1) {cout << 1 << endl;continue;}
        phi(n);
    }
    return 0;
}
///Alhamdulillah
