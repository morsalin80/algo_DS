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
vector<int> adj[21];
int vis[21];
int level[21];
void bfs(int u,int dest){
    queue<int> q;
    q.push(u);
    level[u] = 0;
    vis[u] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u]=1;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(vis[v]==0){
                level[v]=level[u]+1;
                vis[v]=1;
                q.push(v);
                if(v==dest) return;
            }
        }
    }
}
int main()
{
    IOS
    int ts=0;
    //freopen("input00.txt","r",stdin);
    //freopen("output00.txt","w",stdout);
    int num;
    while(cin>>num){
        for(int i=0;i<=20;i++) adj[i].clear();
        for(int i=1;i<=19;i++){
           // int num;
            if(i>1)cin>>num;
            for(int j=0;j<num;j++){
                int v;
                cin>>v;
                adj[i].pb(v);
                adj[v].pb(i);
            }
        }
        int n;
        cin>>n;
        cout << "Test Set #"<<++ts << endl;
        while(n--){
            int a,b;
            cin>>a>>b;
            ms(vis);ms(level);
            bfs(a,b);
            cout << setw(2)<<a<< " to "<<setw(2)<<b<< ": "<<level[b]<<endl;
        }
        cout << endl;
    }
    return 0;
}
///Alhamdulillah
