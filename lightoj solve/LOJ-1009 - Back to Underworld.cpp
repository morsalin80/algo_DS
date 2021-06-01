/// Bismillahir Rahmanir Rahim
/* ID: white_space 
   Name: Mohammad Morsalin
   Study: Dept of ICE, NSTU
   blog: morsalinspace.blogspot.com
*/
#include<bits/stdc++.h>
using namespace std;
#define f0(n) for(int i=0;i<n;i++)
#define pb push_back
#define IOS ios::sync_with_stdio(false);
const int maxn=20004;
vector<int>adj[maxn];
int vis[maxn];
///solution
void init(){
    f0(maxn){
        adj[i].clear();
        vis[i]=0;
    }
}
int bfs(int x){
    queue<int>q;
    int va=0,ly=0;
    q.push(x);
    vis[x]=1;
    va++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(vis[v]==0){
                if(vis[u]==1){
                    vis[v]=2;
                    ly++;
                }
                else {vis[v]=1;va++;}
                q.push(v);
            }
        }
    }
    return max(va,ly);
}
int tc=0;
void solution(){
    init();
    int n;
    cin>>n;
    f0(n){
    	int u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    int ans=0;
    for(int i=1;i<=20000;i++){
    	if(vis[i]==0 && !adj[i].empty()){
            ans+=bfs(i);
        }
    }
    cout << "Case "<<++tc << ": " << ans << endl;
}
signed main()
{
	IOS
    int t;
    t=1;
    cin>>t;
    while(t--){
        solution();
    }
    return 0;
}
///Alhamdulillah

