/// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
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
struct edge {
    ll u, v;
    ll w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
vector<edge>adj;
ll res;
map<int,int> pr;
int n;
int find(int r){
    return (pr[r] == r) ? r : find(pr[r]);
}
ll mst(){
    sort(adj.begin(),adj.end());
    int cnt=0;
 /*   for(int i=0;i<adj.size();i++){
        cout << adj[i].u << " " << adj[i].v << " "<< adj[i].w << endl;
    }*/
    for(int i=0;i<adj.size();i++){
        int u=find(adj[i].u);
        int v=find(adj[i].v);
        if(u!=v){
            pr[u]=v;
            res+=adj[i].w;
           // cout << res << endl;
            cnt++;
            if(cnt==n-1) break;
        }
    }
    return res;
}
void init(){
    adj.clear();
    pr.clear();
    res=0;
}
int main()
{
    IOS
    bool bal=0;
    //freopen("input00.txt","r",stdin);
    //freopen("output00.txt","w",stdout);
    while(scanf("%d",&n)==1){
        init();
        ll ans=0;
        for(int i=0;i<n-1;i++){
            ll u,v,w;
            scanf("%lld%lld%lld",&u,&v,&w);
            ans+=w;
        }
        int k;
        scanf("%d",&k);
        ll uu[k],vv[k],ww[k];
        for(int i=0;i<k;i++){
            scanf("%lld%lld%lld",&uu[i],&vv[i],&ww[i]);
        }
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            edge ed;
            scanf("%lld%lld%lld",&ed.u,&ed.v,&ed.w);
            pr[ed.u]=ed.u;
            pr[ed.v]=ed.v;
            adj.pb(ed);
        }
        for(int i=0;i<k;i++){
            edge ed;
            ed.u=uu[i];ed.v=vv[i];ed.w=ww[i];
            pr[ed.u]=ed.u;
            pr[ed.v]=ed.v;
            adj.pb(ed);
        }
        if(bal)printf("\n");
        bal=1;
        printf("%lld\n%lld\n",ans,mst());
    }
    return 0;
}
///Alhamdulillah
