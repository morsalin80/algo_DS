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
int mark[1000][1000];
int r,c;
int n;
int str,stc,dsr,dsc;
int vis[1000][1000];
int level[1000][1000];
void bfs(){
    queue<pair<int,int> >q;
    q.push(mp(str,stc));
    vis[str][stc] = 1;
    level[str][stc] = 0;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        vis[u.first][u.second]=1;
        for(int i=0;i<4;i++){
            int newr=u.first+dx4[i];
            int newc=u.second+dy4[i];
            if(newr>=r || newr<0 || newc>=c || newc<0) continue;
            if(mark[newr][newc]==0 && vis[newr][newc]==0){
                vis[newr][newc]=1;
                level[newr][newc]=level[u.first][u.second]+1;
                q.push(mp(newr,newc));
                if(newr==dsr && newc==dsc) return ;
            }
        }
    }
}
int main()
{
    IOS
    while(cin>>r>>c){
        if(r==0 && c==0){break;}
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mark[i][j]=0;
                vis[i][j]=0;
                level[i][j]=0;
            }
        }
       cin>>n;
       for(int i=0;i<n;i++){
            int rn,nb;
            cin>>rn>>nb;
            for(int j=0;j<nb;j++){
                int col;
                cin>>col;
                mark[rn][col]=1;
            }
       }

       cin>>str>>stc>>dsr>>dsc;
       bfs();
       cout << level[dsr][dsc]<<endl;
    }
    return 0;
}
///Alhamdulillah
