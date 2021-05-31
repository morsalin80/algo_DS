#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define IOS ios::sync_with_stdio(false);
using namespace std;
map<ll,vector<ll> > adj;
map<ll,ll>level;
map<ll,ll>vis;
ll bfs(ll node,ll l)
{
    queue<ll> Q;
    Q.push(node);
    ll no=1;
    while(!Q.empty())
    {
        ll u = Q.front();
        ll lv=level[u];
        if(lv>l) return no;
        Q.pop();
        vis[u] = 1;
        for(int i=0;i<adj[u].size();i++)
        {
            ll v = adj[u][i];
            if(vis[v]!=1)
            {
                level[v]=level[u]+1;
                if(level[v]>l) return no;
              // cout << "level: "<<level[v]<< " node : "<< v << " is visible\n";
                vis[v] = 1;
                no++;
                Q.push(v);
            }
        }
    }
    return no;
}
int main()
{
	IOS
    ll n;
    ll tc=0;
    while(cin>>n)
    {
        ll k = n;
        if(n==0) break;
        set<ll>st;
        adj.clear();
        while(k--)
        {
            ll u,v;
            cin>>u>>v;
        //    cout << n << endl;
            st.ins(u);
            st.ins(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        while(1)
        {
            ll node,q;
            cin>>node>>q;
            if(node==0 && q==0) break;
            vis.clear();
            level.clear();
            ll no = bfs(node,q);
            cout << "Case "<<++tc<<": "<<st.size()-no<<" nodes not reachable from node "<<node<<" with TTL = "<<q<<".\n";
        }
    }
    return 0;
}
