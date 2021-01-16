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
const ll int maxn=100005;
ll n;
ll lazy[4*maxn];
ll tree[4*maxn];
ll arr[maxn];
void init(){
    for(int i=0;i<maxn;i++)
    {
        arr[i]=0;

    }
    for(int i=0;i<4*maxn;i++)
    {
        tree[i]=0;
        lazy[i]=0;
    }
}
void updateRange(ll node,ll start,ll end,ll l,ll r,ll val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=((end - start + 1) * lazy[node]);///update it
        if(start!=end)
        {
            lazy[node*2]+= lazy[node];
            lazy[node*2 +1]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>end || start>r || end<l) return;
    if(start >=l && end<=r)
    {
        tree[node]+=((end - start +1)*val);
        if(start!=end)
        {
            lazy[2*node]+=val;
            lazy[2*node +1 ] += val;
        }
        return;
    }
    ll mid = (start+end)/2;
    updateRange(2*node,start,mid,l,r,val);
    updateRange(2*node+1,mid+1,end,l,r,val);

    tree[node] = tree[2*node]+tree[2*node+1];
}
ll queryRange(ll node,ll start,ll end,ll l,ll r){

    ///if out of range return 0
    if(start>end || start>r || end < l) return 0;
    if(lazy[node]!=0)
    {
        tree[node]+=((end-start+1)*lazy[node]);
        if(start!=end)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(start>=l && end<=r)
        return tree[node];
    ll mid = (start+end)/2;
    ll p1 = queryRange(2*node,start,mid,l,r);
    ll p2 = queryRange(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}
int main()
{
	IOS
    ll t;
    cin>>t;
    while(t--)
    {
        init();
        ll c;
        cin>>n>>c;
        while(c--)
        {
            ll w;
            cin>>w;
            if(w==0)
            {
                ll p,q,v;
                cin>>p>>q>>v;
                updateRange(0,0,n-1,p,q,v);
            }
            else if(w==1)
            {
                ll p,q;
                cin>>p>>q;
                cout << queryRange(0,0,n-1,p,q)<<endl;
            }
        }
    }
    return 0;
}
///Alhamdulillah
