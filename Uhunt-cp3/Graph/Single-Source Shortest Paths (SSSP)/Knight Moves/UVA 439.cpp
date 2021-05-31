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
int cx8[] = {+2,+2,-2,-2,+1,+1,-1,-1};
int cy8[] = {+1,-1,+1,-1,+2,-2,+2,-2};
int str,stc,dsr,dsc;
int vis[9][9];
int level[9][9];
void bfs(){
    queue<pair<int,int> >q;
    q.push(mp(str,stc));
    vis[str][stc]=1;
    level[str][stc]=0;
    while(!q.empty()){
        pair<int,int>u=q.front();
        q.pop();
        if(u.first==dsr && u.second==dsc) return;
        vis[u.first][u.second] = 1;
        for(int i=0;i<8;i++){
            int newr=u.first+cx8[i];
            int newc=u.second+cy8[i];
            if(newr>8 || newr <1 || newc>8 || newc <1 )continue;
            level[newr][newc]=level[u.first][u.second]+1;
            vis[newr][newc]=1;
            q.push(mp(newr,newc));
            if(newr==dsr && newc==dsc) return;
        }
    }
}
int main()
{
    IOS
    string s,t;
    while(cin>>s>>t){
        str=s[0]-'a' +1;
        stc=s[1]-'0';
        dsr=t[0]-'a' +1;
        dsc=t[1]-'0';
        for(int i=1;i<9;i++){
            for(int j=1;j<9;j++) {
                vis[i][j] = 0;
                level[i][j] = 0;
            }
        }
        bfs();
        cout << "To get from "<<s<<" to "<<t<<" takes "<<level[dsr][dsc]<<" knight moves.\n";
    }
    return 0;
}
///Alhamdulillah
