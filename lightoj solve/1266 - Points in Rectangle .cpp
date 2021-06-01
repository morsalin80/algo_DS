/// Bismillahir Rahmanir Rahim
/* Mohammad Morsalin
   Dept of ICE, NSTU
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
//#define endl "\n"
#define int long long
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ms2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
#define CLR(x) memset(x, -1, sizeof(x))
#define CLR2d(x,m,n) memset(x, -1, sizeof(x[0][0]) * m * n)
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi pair<int,int>
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define bits(n) __builtin_popcount(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define ins insert
#define ALL(v) v.begin(),v.end()
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define fi first
#define se second
#define PI acos(-1)
#define sz(a) (int)a.size();
#define IOS ios::sync_with_stdio(false);

///for debug
vector<string> vec_splitter(string s) {    s += ',';vector<string> res;while(!s.empty()) {res.push_back(s.substr(0, s.find(',')));s = s.substr(s.find(',') + 1);}return res;}
void debug_out( vector<string> __attribute__ ((unused)) args,__attribute__ ((unused)) int idx,__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) { if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";stringstream ss; ss << H;cerr << args[idx] << " = " << ss.str();debug_out(args, idx + 1, LINE_NUM, T...);}
#define XOX
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
///debug template ends


int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const long long MOD = 1000000007;
double sq(double x) {return x*x;}
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
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
///modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
///modular arithmetic template ends

bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}

///solution
const int maxn=1005;
int BIT[maxn][maxn];
int arr[maxn][maxn];
void update(int x,int y){
    while(x<=1001){
        int y1=y;
        while(y1<=1001){
            BIT[x][y1]++;
            y1 += (y1 & -y1);
        }
        x+=(x & -x);
    }
}
int query(int x2, int y2){
    int res=0;
    while(x2>0){
        int y=y2;
        while(y>0){
            res+=BIT[x2][y];
          //  debug(x2,y,res);
            y-=(y & -y);
        }
        x2-=(x2 & -x2);
    }
    return res;
}
int cs=0;
void init(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            BIT[i][j]=0;
            arr[i][j]=0;
        }
    }
}
void solution(){
    int q;
    init();
    scanf("%lld",&q);
    printf("Case %lld:\n",++cs);
    while(q--){
        int c;
        scanf("%lld",&c);
        if(c==0){
            int x,y;
            scanf("%lld%lld",&x,&y);
            x++,y++;
            if(arr[x][y]==0){
                arr[x][y]=1;
                update(x,y);
            }
        }
        if(c==1){
            int x1,y1,x2,y2;
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            x1++,x2++,y1++,y2++;

             /*y  |
                |           --------(x2,y2)
                |          |       |
                |          |       |
                |          |       |
                |          ---------
                |       (x1,y1)
                |
                |___________________________
               (0, 0)                   x-->*/


            int ans=query(x2,y2);
            ans-=query(x2,y1-1);
            ans-=query(x1-1,y2);
            ans+=query(x1-1,y1-1);
            printf("%lld\n",ans);
        }
    }

}
signed main()
{
    IOS
    int t;
    t=1;
    //cin>>t;
    scanf("%lld",&t);
    while(t--){
        solution();
    }
    return 0;
}
///Alhamdulillah

