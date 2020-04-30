/// Bismillahir Rahmanir Rahim
/* Author: Mohammad Morsalin (aka white_space)
    Dept of ICE, NSTU
*/
#include<bits/stdc++.h>
#define ll long long
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
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans;
        if(n==1 || n==2 || n==3){
            printf("%lld\n",n);
            continue;
        }
        ///N^(K/N) is largest when N = 3 (N and K being integers)
        ll base=n/3;
        ll rem = n%3;
        bool f=0,t=0;
        if(rem==1 && n>1)
        {
            base--;
            f=1;
        }
        if(rem==2 && n>2){
            t=1;
        }
        ans=Bigmod(3*1ll,base,MOD);
        if(t){
            ans<<=1;
            ans%=MOD;
        }
        if(f){
            ans*=4;
            ans%=MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
///Alhamdulillah
