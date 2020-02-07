#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxx = 100005;
typedef long long ll;
vector<ll>a;
vector<ll>stree[4*maxx];
vector<ll>pre[4*maxx];
void merGe(int idx)
{
    vector<ll>L,R;
    L = stree[2*idx+1];
    R = stree[2*idx+2];
    //for(int i=0;i<L.size();i++) cout<<L[i]<<" ";
    //cout<<endl;
   // for(int i=0;i<R.size();i++) cout<<R[i]<<" ";
 //   cout<<endl;
    int n1 = L.size();
    int n2 = R.size();
    pre[idx].assign(n1+n2+1,0);
    int i=0,j=0,k=1;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j]){
            stree[idx].pb(L[i]);
            pre[idx][k] = pre[idx][k-1]+L[i];
            i++;
            k++;
        }
        else {
            stree[idx].pb(R[j]);
            pre[idx][k] = pre[idx][k-1] + R[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        stree[idx].pb(L[i]);
        pre[idx][k] = pre[idx][k-1] + L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        stree[idx].pb(R[j]);
        pre[idx][k] = pre[idx][k-1] + R[j];
        j++;
        k++;
    }
}
void buildTree(int idx,int ss,int se)
{
    if(ss==se){
        pre[idx].assign(2,0);
        stree[idx].pb(a[ss]);
        pre[idx][1]=a[ss];
        return ;
    }
    int mid = (ss+se)/2;
    buildTree(2*idx+1,ss,mid);
    buildTree(2*idx+2,mid+1,se);
    merGe(idx);
    //for(int i=0;i<stree[idx].size();i++) cout<<stree[idx][i]<<" ";
    //cout<<endl;
    //cout<<pre[idx][(int)stree[idx].size()]<<endl;
}
ll queryRec(int node,int start,int end,int ss,int se,int k)
{
    if(ss>end || start>se || ss>se)
    {
        return 0;
    }
    if(ss<=start && se>=end)
    {
        //cout<<stree[node][0]<<endl;
        ll w = upper_bound(stree[node].begin(),stree[node].end(),k)-stree[node].begin();
     //   cout<<"w: "<<w <<" prew"<<pre[node][w]<<endl;
        ll range=(w-1)>=0?pre[node][w]:0;
        return (w*k - (range));
    }
    int mid = (start+end)/2;
    ll p1 = queryRec(2*node+1,start,mid,ss,se,k);
    ll p2 = queryRec(2*node+2,mid+1,end,ss,se,k);
    return p1+p2;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        ll x;
        scanf("%lld",&x);
        a.push_back(x);
    }
    //for(int )
    buildTree(0,0,n-1);
    while(m--)
    {
        ll l,r;
        ll cap;
        scanf("%lld%lld%lld",&l,&r,&cap);
        l--,r--;
        printf("%lld\n",queryRec(0,0,n-1,l,r,cap));
    }
}
