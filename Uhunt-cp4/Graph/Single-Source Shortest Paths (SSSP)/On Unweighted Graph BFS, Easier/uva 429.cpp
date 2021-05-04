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
map<string,vector<string> > mms;
string str,dsr;
map<string,int>vis;
map<string,int>dis;
void bfs(){
    queue<string>q;
    q.push(str);
    vis[str]=1;
    while(!q.empty()){
        string u=q.front();
        q.pop();
       // cout << mms[u].size()<< endl;
        vis[u]=1;
        for(int i=0;i<mms[u].size();i++){
            string v=mms[u][i];
         //   cout << v << endl;
            if(vis[v]==0) {
         //       cout << v << endl;
                dis[v]=dis[u]+1;
                vis[v]=1;
                q.push(v);
                if(v==dsr)return;
            }
        }

    }
}
int main()
{
    IOS
    int n;
//    freopen("input00.txt","r",stdin);
  //  freopen("output00.txt","w",stdout);
    cin>>n;
    bool balchal=0;
    while(n--){
        vector<string> vec;
        string s;
        while(1){
            cin>>s;
            if(s=="*") break;
            vec.pb(s);
        }
        cin.ignore();
        for(int i=0;i<(int)vec.size();i++){
            for(int j=0;j<(int)vec.size();j++){
                if(i==j) continue;
                if(vec[i].size()!=vec[j].size()) continue;
                int un=0;
                for(int k=0;k<(int)vec[i].size();k++){
                    if(vec[i][k]!=vec[j][k])un++;
                }
                if(un==1){ mms[vec[i]].pb(vec[j]); }
            }
        }
        if(balchal)cout << endl;
        balchal=1;
        string bal;
        while(getline(cin,bal)&& bal!=""){
            if(bal=="") break;
            stringstream s(bal);
            s>>str>>dsr;
            bfs();
            cout << str << " "<< dsr << " "<< dis[dsr]<<endl;
           // mms.clear();
            vis.clear();
            dis.clear();
        }
        mms.clear();
    }
    return 0;
}
///Alhamdulillah
