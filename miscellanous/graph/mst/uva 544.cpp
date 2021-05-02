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
    string u, v;
    int w;
    bool operator<(const edge& p) const
    {
        return w > p.w;
    }
};
const int MAXN=100000;
map<string,string>pr;
map<string,int>vis;
vector<edge> e;
int n, m;
string str,dsr;
map<pair<string,string>,int>paisa;
map<string,vector<string> > mms;
int mini=highest(int);
void bfs(){
   queue<string>q;
   q.push(str);
   vis[str]=1;
   while(!q.empty()){
        string u=q.front();
        vis[u] =1;
        q.pop();
        //cout << u << endl;
        for(int i=0;i<mms[u].size();i++){
            string v=mms[u][i];
            if(vis[v]==0){
          //      cout << u << " "<< v << endl;
                vis[v] = 1;
                if(mms[v].size()>1 && v!=dsr){
                    q.push(v);
                    mini=min(mini,max(paisa[{u,v}],paisa[{v,u}]));
                }else if(v==dsr){
                    mini=min(mini,max(paisa[{u,v}],paisa[{v,u}]));
                    return;
                }
            //     cout << mini << endl;
            }

        }
   }
}

string find(string r)
{
    return (pr[r] == r) ? r : find(pr[r]);
}
int mst()
{
    sort(e.begin(), e.end());
    int count = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++) {
        string u = find(e[i].u);
        string v = find(e[i].v);
        if (u != v) {
          //  cout << e[i].u << " "<< e[i].v << endl;
            mms[e[i].u].pb(e[i].v);
            mms[e[i].v].pb(e[i].u);
            pr[u] = v;
            count++;
            s += e[i].w;
            if (count == n - 1)
                break;
        }
    }
    return s;
}
void init(){
    pr.clear();
    vis.clear();
    e.clear();
    paisa.clear();
    mms.clear();
    mini=highest(int);
}
int main()
{
    IOS
    int tc=0;
    while(cin >> n >> m){
        if(n==m && m==0){break;}
        cin.ignore();
        init();
    for (int i = 1; i <= m; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        pr[u]=u;
        pr[v]=v;
        paisa[mp(u,v)]=w;
        paisa[mp(v,u)]=w;
        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }
    cin>>str>>dsr;
    mst();
    bfs();
    cout <<"Scenario #"<<++tc<<endl;
    cout << mini << " tons\n"<<endl;
    }
    return 0;
}
///Alhamdulillah
