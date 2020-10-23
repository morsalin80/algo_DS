#include<bits/stdc++.h>
using namespace std;
const int maxn = 300005;
int k,cnt[maxn],ans[maxn],a[maxn],dt;
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
    memset(cnt,0,sizeof(cnt));
    memset(ans,0,sizeof(ans));

}
void incr(int val)
{
   int x = a[val];
   cnt[x]++;
   if(cnt[x]==1)dt++;
}
void decr(int val)
{
    int x = a[val];
    cnt[x]--;
    if(cnt[x]==0) dt--;
}
int main()
{
    int t,tc=0;
    scanf("%d",&t);
    while(t--){
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
            query[i].L--;
            query[i].R--;
        }
        sort(query,query+q);
        //cout << "sorted";
        int L=0,R=-1;
        dt=0;
        for(int i=0;i<q;i++)
        {
            while(R<=query[i].R) incr(++R);
            while(L<query[i].L) decr(L++);
            while(R>query[i].R) decr(R--);
            while(L>query[i].L) incr(--L);
            ans[query[i].index]=dt;
        }
        printf("Case %d:\n",++tc);
        for(int i=0;i<q;i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
