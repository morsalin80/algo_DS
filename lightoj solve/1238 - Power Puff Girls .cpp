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
#define endl "\n"
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

///solution
const int maxn=30;
char s[maxn][maxn];
int n,m;
int mark[maxn][maxn];
int dist[maxn][maxn];
int par[maxn][maxn];
void init(){
    ms(mark);
    ms(dist);
}

void bfs(int i,int j){
    queue<pair<int,int> >q;
    q.push(mp(i,j));
    mark[i][j]=1;
    dist[i][j]=0;
    while(!q.empty()){
        pair<int,int>xy=q.front();
        q.pop();
        int x=xy.fi;
        int y=xy.se;
        for(int k=0;k<4;k++){
            int xi=x+dx4[k];
            int yi=y+dy4[k];
            if(xi>=0 && yi>=0 && xi<m && yi<n && s[xi][yi]!='#' && s[xi][yi]!='m' && mark[xi][yi]==0){
                mark[xi][yi]=1;
                dist[xi][yi]=dist[x][y]+1;
                q.push(mp(xi,yi));
            }
        }
    }
}
void solution(){
    init();
    scanf("%d%d",&m,&n);getchar();
    int srcx,srcy;
    for(int i=0;i<m;i++){
        scanf("%s",s[i]);getchar();
    }
    int ans=0;
    vpii points;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s[i][j]=='a' || s[i][j]=='b' || s[i][j]=='c'){
                points.pb({i,j});
            }
            if(s[i][j]=='h') srcx=i,srcy=j;
        }
    }
    bfs(srcx,srcy);
    for(auto it:points){
        ans=max(ans,dist[it.fi][it.se]);
    }
    printf("%d\n",ans);
}
signed main()
{
   // IOS
    int t;
    t=1;
    //cin>>t;
    scanf("%d",&t);
    int cs=0;
    while(t--){
        printf("Case %d: ",++cs);
        solution();
    }
    return 0;
}
///Alhamdulillah

