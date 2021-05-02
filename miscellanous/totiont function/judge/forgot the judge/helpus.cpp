/// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define IOS ios::sync_with_stdio(false);
#define MAX 1000005
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
int phi[MAX];
void sieve(){
    for(int i=2;i<MAX;i++)
    {
        if(phi[i]==0)
        {
            phi[i] = i-1;
            for(int j=i*2;j<MAX;j+=i)
            {
                if(phi[j]==0) phi[j] = j;
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
int main()
{
	IOS
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll x,p;
        cin>>x>>p;
        if(x==1) {cout << p << endl;continue;}
        x*=phi[x];
        x/=2;
        x*=p;
        cout << x << endl;
    }
    return 0;
}
///Alhamdulillah
