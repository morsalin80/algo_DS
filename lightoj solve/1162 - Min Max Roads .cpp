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
//#define int long long
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
const int maxx=100005;
int n,cnter,ht,mx,mn;
vector<pair<int,int> > edge[maxx];
vector<int>start,endd,height,cost;
vector<vector<int> > table,maxi,mini;
void dfs(int v,int p){
    start[v]=++cnter;
    table[v][0]=p;
    maxi[v][0]=cost[p];
    mini[v][0]=cost[p];
    for(int i=1;i<=ht;i++){
        table[v][i]=table[table[v][i-1]][i-1];
        maxi[v][i]=max(maxi[table[v][i-1]][i-1],maxi[v][i-1]);
        mini[v][i]=min(mini[table[v][i-1]][i-1],mini[v][i-1]);
    }
    for(auto u:edge[v]){
        if(u.fi!=p){
            height[u.fi]=height[v]+1;
            cost[v]=u.se;
            dfs(u.fi,v);
        }
    }
    endd[v]=++cnter;
}
void init(){
    start.resize(n);
    endd.resize(n);
    cost.resize(n);
    height.resize(n);
    cnter=0;
    ht=ceil(log2(n));
    maxi.assign(n,vector<int>(ht+1,lowest(int)));
    mini.assign(n,vector<int>(ht+1,highest(int)));
    table.assign(n,vector<int>(ht+1));
    for(int i=0;i<n;i++){
        edge[i].clear();
    }
}
bool is_ancestor(int u,int v){
    return start[u]<=start[v] && endd[u]>=endd[v];
}
int longest_common_ancestor(int u,int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u))return v;
    for(int i=ht;i>=0;i--){
        if(!is_ancestor(table[u][i],v)){
            u=table[u][i];
        }
    }
    return table[u][0];
}
void get_min_max(int v,int diff){
    for(int i=ht;i>=0;i--){
        if(!(diff&(1<<i)))continue;
        mx=max(mx,maxi[v][i]);
        mn=min(mn,mini[v][i]);
        v=table[v][i];
    }
}
void get_ans(int u,int v){
    int lca=longest_common_ancestor(u,v);
    get_min_max(u,height[u]-height[lca]);
    get_min_max(v,height[v]-height[lca]);
}
///solution
void solution(){
    scanf("%d",&n);
    init();
    for(int i=0;i<n-1;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        u--,v--;
        edge[u].pb(mp(v,w));
        edge[v].pb(mp(u,w));
    }
    dfs(0,0);
    int q;
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        mx=lowest(int);
        mn=highest(int);
        get_ans(u,v);
        printf("%d%d\n",mn,mx);
    }
}
signed main()
{
    IOS
    int t;
    t=1;
    //cin>>t;
    int cs=0;
    scanf("%d",&t);
    while(t--){
        printf("Case %d:\n",++cs);
        solution();
    }
    return 0;
}
///Alhamdulillah
