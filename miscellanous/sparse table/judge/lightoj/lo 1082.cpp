#include<bits/stdc++.h>
using namespace std;
const int maxn =100005;
int sparse[maxn][(int)log2(maxn)+1];
int arr[maxn];
void pre(int n){
    for(int i=0;i<n;i++)
    {
        sparse[i][0] = i;
    }
    for(int j=1;(int)pow(2,j)<=n;j++)
    {
        for(int i=0;i+(int)pow(2,j)-1<n;i++)
        {
            if(arr[sparse[i][j-1]]<arr[sparse[i+(int)pow(2,j-1)][j-1]]){
                sparse[i][j] = sparse[i][j-1];
            }
            else
                sparse[i][j] = sparse[i+(int)pow(2,j-1)][j-1];
        }
    }
}
int rmq(int low,int high)
{
    int l = high-low +1;
    int k = log2(l);
    return min(arr[sparse[low+l-(int)pow(2,k)][k]],arr[sparse[low][k]]);
}
void init()
{
    for(int i=0;i<maxn;i++)
    {
        arr[i] = 0;
        for(int j=0;j<(int)log2(maxn)+1;j++)
            sparse[i][j] = 0;
    }

}
int main()
{
    int t;
    scanf("%d",&t);
    int cs=0;
    while(t--)
    {
       init();
       printf("Case %d:\n",++cs);
       int n,q;
       scanf("%d%d",&n,&q);
       for(int i=0;i<n;i++)
       {
           scanf("%d",&arr[i]);
       }
       pre(n);
       while(q--)
       {
           int l,r;
           scanf("%d%d",&l,&r);
           l--,r--;
           printf("%d\n",rmq(l,r));
       }
    }
    return 0;
}
