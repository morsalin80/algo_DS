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
struct edge{
    pair<int,int>u,v;
    double w;
    bool operator < (const edge &p) const{
        return w<p.w;
    }
};
map<pair<int,int>,pair<int,int> > pr,chk;
map<pair<int,int>,int>len;
vector<edge>adj;
int n,r;
pair<int,int>root(pair<int,int>r){
    return (pr[r]==r)?r:root(pr[r]);
}
void w_u(pair<int,int>a,pair<int,int>b){
    pair<int,int>root_a,root_b;
    root_a=root(a);
    root_b=root(b);
    if(root_a==root_b) return;
    if(len[root_a]>len[root_b]){
        pr[root_b] = root_a;
        len[root_a]+=len[root_b];
    }
    else {
        pr[root_a]=root_b;
        len[root_b]+=len[root_a];
    }
}
double road,rail;
pair<int,int>find(pair<int,int>i){
    return (chk[i]==i)?i:find(chk[i]);
}
void mst()
{
    sort(adj.begin(),adj.end());
    int cnt=0;
    for(int i=0;i<adj.size();i++){
        pair<int,int>u,v,x,y;
        u=find(adj[i].u);
        x=root(adj[i].u);
        y=root(adj[i].v);
        v=find(adj[i].v);
        if(u!=v){
            if(x!=y){
                rail+=adj[i].w;
            }
            else road+=adj[i].w;

            cnt++;
            chk[u]=v;
            if(cnt==n-1) return;
        }
    }
}
void init(){
    pr.clear();
    chk.clear();
    adj.clear();
    len.clear();
    road=0;rail=0;
}
int main()
{
    IOS
    int t;
    freopen("input00.txt","r",stdin);
    freopen("output00.txt","w",stdout);
    cin>>t;
    int tc=0;
    while(t--){
        cin>>n>>r;
        init();
        vector<pair<int,int> >vp;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            pair<int,int>u={x,y};
            vp.pb(u);
            pr[u]=u;
            chk[u]=u;
        }
        for(int i=0;i<vp.size();i++){
            for(int j=0;j<vp.size();j++){
                if(i==j) continue;
                pair<int,int>u,v;
                u=vp[i];
                v=vp[j];
                double w = sqrt((u.first-v.first)*(u.first-v.first) + (u.second-v.second)*(u.second-v.second));
                if(w<=r){
                    w_u(u,v);
                }
                edge ed;
                ed.u=u;
                ed.v=v;
                ed.w=w;
                adj.pb(ed);
            }
        }
        set<pair<int,int> > st;
        for(int i=0;i<vp.size();i++){
            pair<int,int>p=root(vp[i]);
            st.insert(p);
        }
        mst();
        cout << "Case #"<<++tc<<": "<<st.size() << " "<< round(road) << " "<< round(rail) << endl;
    }
    return 0;
}
///Alhamdulillah
