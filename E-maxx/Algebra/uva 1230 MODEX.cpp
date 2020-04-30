/// Bismillahir Rahmanir Rahim
/* Author: Mohammad Morsalin (aka white_space)
    Dept of ICE, NSTU
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define ALL(v) v.begin(),v.end()
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define PI acos(-1)
#define IOS ios::sync_with_stdio(false);
using namespace std;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
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
///using binary exponential with mod.
/*The idea of binary exponentiation is, that
 we split the work using the binary representation of the exponent*/

ll binpow(ll a,ll b,ll m){
    a%=m;
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%m;
        }
        a*=a;
        a%=m;
        b>>=1;
       // cout << b << " "<< a << " "<<ans << endl;
    }
    return ans;
}
int main()
{
    IOS
    int t;
    scanf("%d",&t);
    while(t--){
        ll x,y,n;
        scanf("%lld %lld %lld",&x,&y,&n);
        printf("%lld\n",binpow(x,y,n));
    }
    int x;
    scanf("%d",&x);
    return 0;
}
///Alhamdulillah
