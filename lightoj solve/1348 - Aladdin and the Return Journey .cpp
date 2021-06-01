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
const int maxx=30005;
int nog[maxx],n,cnter,hight;
vector<int>edge[maxx],start(maxx),parent(maxx),heavy(maxx),endd(maxx);
vector<vector<int> > table;
int dfs(int v,int p){
    start[v]=++cnter;
    table[v][0]=p;
    //debug(v,p);
    int len=1;
    int mxlen=0;
    for(int i=1;i<=hight;i++){
        table[v][i]=table[table[v][i-1]][i-1];
    }
    for(int i=0;i<(int)edge[v].size();i++){
        int u=edge[v][i];
        if(u!=p){
            parent[u]=v;
            int tlen=dfs(u,v);
            len+=tlen;
            if(tlen>mxlen){
                mxlen=tlen;
                heavy[v]=u;
            }
        }
    }

    endd[v]=++cnter;
    return len;
}
int head[maxx],number,index[maxx],position_in_array[maxx],ptr,arr[maxx];
void Heavy_light_decompostion(int current){
    if(head[number]==-1) head[number]=current;
    index[current]=number;
    position_in_array[current]=ptr;
    arr[ptr++]=nog[current];
    if(heavy[current]!=-1) Heavy_light_decompostion(heavy[current]);
    for(int i=0;i<(int)edge[current].size();i++){
        int it=edge[current][i];
        if(it!=parent[current] && it!=heavy[current]){
            number++;
            Heavy_light_decompostion(it);
        }
    }
}
int binary_indexed_tree[maxx];
void update(int x,int val){
    while(x<=ptr){
        binary_indexed_tree[x]+=val;
        x+=(x&-x);
    }
}
bool is_ancestor(int u,int v){
    return start[u]<=start[v] && endd[u]>=endd[v];
}
int longest_common_ancestor(int u, int v){
    if(is_ancestor(u,v))return u;
    if(is_ancestor(v,u)) return v;
    for(int i=hight;i>=0;i--){
        if(!is_ancestor(table[u][i],v)){
            u=table[u][i];
        }
    }
    return table[u][0];
}
int query(int x){
    int res=0;
    while(x>0){
        res+=binary_indexed_tree[x];
        x-=(x&-x);
    }
    return res;
}
int ans;
void tree_query(int u,int v){
    int chain1,chain2=index[v];
    while(1){
        chain1=index[u];
        if(chain1==chain2){
            ans+=(query(position_in_array[u]+1)-query(position_in_array[v]));
            break;
        }
        ans+=(query(position_in_array[u]+1)-query(position_in_array[head[chain1]]));
        u=head[chain1];
        u=parent[u];
    }
}
void init(){
    number=0;
    ptr=0;
    fill(arr,arr+(n+5),0);
    fill(index,index+(n+5),-1);
    fill(head,head+(n+5),-1);
    fill(position_in_array,position_in_array+(n+5),-1);
    for(int i=0;i<n+5;i++)edge[i].clear();
    fill(start.begin(),start.begin()+(n+5),0);
    fill(endd.begin(),endd.begin()+(n+5),0);
    cnter=0;
    hight=ceil(log2(n));
    table.assign(n,vector<int>(hight+1));
    fill(parent.begin(),parent.begin()+(n+5),0);
    fill(heavy.begin(),heavy.begin()+(n+5),-1);
    fill(binary_indexed_tree,binary_indexed_tree+(n+5),0);
}
///solution
void solution(){
    scanf("%lld",&n);
    init();
    for(int i=0;i<n;i++)scanf("%lld",&nog[i]);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dfs(0,0);
    Heavy_light_decompostion(0);
    for(int i=0;i<=ptr;i++){
        update(i+1,arr[i]);
    }
    int q;
    scanf("%lld",&q);
    while(q--){
        int option;
        scanf("%lld",&option);
        if(option==0){
            int u,v;
            scanf("%lld%lld",&u,&v);
            int lca=longest_common_ancestor(u,v);
            tree_query(u,lca);
            tree_query(v,lca);
            ans-=nog[lca];
            printf("%lld\n",ans);
            ans=0;
        }
        else{
            int u,val;
            scanf("%lld%lld",&u,&val);
            update(position_in_array[u]+1,-nog[u]);
            nog[u]=val;
            update(position_in_array[u]+1,nog[u]);
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
    int cs=0;
    while(t--){
        printf("Case %lld:\n",++cs);
        solution();
    }
    return 0;
}
///Alhamdulillah

