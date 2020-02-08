#include<bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int k,fof[maxn],f[maxn],ans[maxn],a[maxn],maxf;
struct Query{
    int index,L,R;
    bool operator <(const Query &other) const{
        int block_own = L/k;
        int block_other = other.L/k;
        if(block_own==block_other)
            return R<other.R;
        return block_own<block_other;
    }

}query[maxn];
void init()
{
    memset(a,0,sizeof(a));
    memset(fof,0,sizeof(fof));
    memset(f,0,sizeof(f));
    memset(ans,0,sizeof(ans));

}
void incr(int val)
{
   int x = a[val];
   //cout << x << " "<< fof[f[x]] << endl;
   fof[f[x]]--;
   f[x]++;
   fof[f[x]]++;
   if(fof[maxf+1]>0)maxf++;
}
void decr(int val)
{
    int x = a[val];
    fof[f[x]]--;
    f[x]--;
    fof[f[x]]++;
    if(fof[maxf]==0) maxf--;
}
int main()
{
    int n,q;
    scanf("%d",&n);
    init();
    scanf("%d",&q);
    k = sqrt(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&query[i].L,&query[i].R);
        query[i].index=i;
    }
    sort(query,query+q);
    //cout << "sorted";
    int L=0,R=-1;
    maxf=0;
    for(int i=0;i<q;i++)
    {
        while(R<query[i].R) incr(++R);
        while(L<query[i].L) decr(L++);
        while(R>query[i].R) decr(R--);
        while(L>query[i].L) incr(--L);
        ans[query[i].index]=maxf;
    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
