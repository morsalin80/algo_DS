#include<bits/stdc++.h>
using namespace std;
#define pb push_back
///the connected component is a cycle iff the degree of each its vertex equals to 2
const int maxn=200005;
vector<int>edge[maxn],connected;
int vis[maxn],degree[maxn];
int cnt=0;
void dfs(int u){
	vis[u]=1;
	connected.pb(u);
	for(auto it:edge[u]){
		if(vis[it]==0){
			dfs(it);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		edge[u].pb(v);
		edge[v].pb(u);
		degree[u]++;
		degree[v]++;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			connected.clear();
			dfs(i);
			bool ok=1;
			for(auto it:connected){
				if(degree[it]!=2){
					ok=0;
				}
			}
			if(ok){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}