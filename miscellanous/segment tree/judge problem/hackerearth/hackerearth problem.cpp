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
int n,q;
const int maxn=100005;
int arr[maxn];
int tree[2*maxn];
void build(int node,int start,int endd){
    if(start==endd)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start+endd)/2;
        build(2*node+1,start,mid);
        build(2*node+2,mid+1,endd);
        tree[node]=min(tree[2*node+1],tree[2*node +2]);
    }
}
int query(int node,int start,int endd,int l,int r){
    //cout << "node: "<< node <<" start: "<<start << " end: "<<endd << endl;
    if(start>r || endd<l)
    {
        return highest(int);
    }
    else if( start>=l && endd<=r)
    {
       // cout << "node: "<< node <<" start: "<<start << " end: "<<endd << endl;
        return tree[node];
    }
    int mid=(start+endd)/2;
    int p1=query(2*node+1,start,mid,l,r);
    int p2=query(2*node+2,mid+1,endd,l,r);
    //cout << "P1: "<<p1 << " p2: "<<p2<<endl;
    return min(p1,p2);
}
void update(int node,int start,int endd,int x,int y){
    if(start==endd && start==x)
    {
        arr[x] = y;
        tree[node] = y;
    }
    else {
        int mid=(start+endd)/2;
        if(start<=x && x<=mid)update(2*node+1,start,mid,x,y);
        else update(2*node +2,mid+1,endd,x,y);
        tree[node]= min(tree[2*node+1],tree[2*node+2]);
    }
}
int main()
{
	IOS
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1);
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch=='q'){
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout << query(0,0,n-1,l,r)<<endl;
        }
        else if(ch=='u')
        {
            int x,y;
            cin>>x>>y;
            x--;
            update(0,0,n-1,x,y);
        }
    }
    return 0;
}
///Alhamdulillah
