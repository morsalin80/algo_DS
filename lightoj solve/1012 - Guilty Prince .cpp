/// Bismillahir Rahmanir Rahim
/* ID: white_space 
   Name: Mohammad Morsalin
   Study: Dept of ICE, NSTU
   blog: morsalinspace.blogspot.com
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(false);
int dx4[] = {0, 0, 1, -1}; ///direction arrays
int dy4[] = {1, -1, 0, 0};
const int maxn=25;
char s[maxn][maxn];
map<pair<int,int>,int>vis;
int w,h;
int ans;
void init(){
	ans=0;
	vis.clear();
}
void bfs(int posi,int posj){
	pair<int,int>x={posi,posj};
	queue<pair<int,int> > q;
	q.push(x);
	vis[x]=1;
	while(!q.empty()){
		pair<int,int>u=q.front();
		q.pop();
		int x=u.first;
		int y=u.second;
		for(int i=0;i<4;i++){
			int nx=x+dx4[i];
			int ny=y+dy4[i];
			if(nx>=0 && nx<h && ny>=0 && ny<w && s[nx][ny]=='.' && vis[mp(nx,ny)]==0){
				ans++;
				vis[mp(nx,ny)]++;
				q.push(mp(nx,ny));			
			}
		}
	}
}
int tc=0;
///solution
void solution(){
    cin>>w>>h;
    int posi,posj;
    init();
    for(int i=0;i<h;i++){
  		for(int j=0;j<w;j++){
        cin>>s[i][j];
  			if(s[i][j]=='@'){
  				posi=i;
  				posj=j;
  			}
  		}
    }
    bfs(posi,posj);
    cout<< "Case "<< ++tc <<": "<< ans+1 << endl;
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

