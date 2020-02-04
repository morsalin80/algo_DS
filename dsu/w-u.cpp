/// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define IOS ios::sync_with_stdio(false);
using namespace std;
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
int arr[1005];
int size[1005];
void init()
{
    for(int i=0;i<1005;i++)
    {
        arr[i] = i;
        size[i] = 1;
    }
}
int root(int i)
{
    while(arr[i]!=i)
    {
        i = arr[arr[i]];
        i = arr[i];
    }
    return i;
}
void w_union(int a,int b)
{
    int root_a = root(a);
    int root_b = root(b);
    if(root_a==root_b) return;
    if(size[root_a]<size[root_b])
    {
        arr[root_a] = arr[root_b];
        size[root_b] += size[root_a];
    }
    else
    {
        arr[root_b] = arr[root_a];
        size[root_a] += size[root_b];
    }
}
bool Find(int a,int b)
{
    if(arr[a]==arr[b])
        return true;
    else
        return false;

}
int main()
{
	IOS
    int n,m;
    while(cin>>n>>m)
    {
        init();
        while(m--){
        int x,y;
        cin>>x>>y;
        w_union(x,y);
        vector<int>vec;
        int visited[1005];
        ms(visited);
        for(int i=1;i<=n;i++)
        {
            int r = root(i);
            if(visited[r]==0)
            {
                vec.pb(size[r]);
                visited[r] = 1;
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
        }
    }
    return 0;
}
