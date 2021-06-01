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
    pair<double,double>u,v;
    double w;
    bool operator<(const edge& p)const
    {
        return w<p.w;
    }
};
int n;
map<pair<double,double>,pair<double,double> >pr;
vector<edge>adj;
pair<double,double> find(pair<double,double> r){
    return (pr[r] == r) ? r : find(pr[r]);
}
double mst(){
    sort(adj.begin(),adj.end());
    double res=0.0;
    int cnt=0;
    for(int i=0;i<adj.size();i++){
        pair<double,double>u=find(adj[i].u);
        pair<double,double>v=find(adj[i].v);
       // cout << adj[i].u.first<< " "<< adj[i].u.second<< endl;
       // cout << adj[i].v.first<< " "<< adj[i].v.second<<endl;
      //  cout << adj[i].w<< endl;
        if(u.first!=v.first || u.second!=v.second){
            pr[u]=v;
            cnt++;
            res+=adj[i].w;
    //        cout << res << endl;
            if(cnt==n-1){
                break;
            }
        }
    }
    return res;
}
void init(){
    pr.clear();
    adj.clear();
}
int main()
{
    IOS
    int t;
    bool bl=0;
  //  freopen("input00.txt","r",stdin);
    //freopen("output00.txt","w",stdout);
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        init();
        scanf("%d",&n);
        vector<pair<double,double > > vp;
        for(int i=0;i<n;i++){
            double x,y;
            scanf("%lf%lf",&x,&y);
            vp.pb(mp(x,y));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                edge ed;
                ed.u=vp[i];
                ed.v=vp[j];
                pr[vp[i]]=vp[i];
                pr[vp[j]]=vp[j];
                ed.w = sqrt((ed.u.first-ed.v.first)*(ed.u.first-ed.v.first) + (ed.u.second-ed.v.second)*(ed.u.second-ed.v.second));
                adj.pb(ed);
            }
        }
        cout << fixed<< setprecision(2)<< mst()<<endl;
        if(tc!=t) cout << endl;
    }
    return 0;
}
///Alhamdulillah
