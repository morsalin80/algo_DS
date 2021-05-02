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
int main()
{
    IOS
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        bool table[1005][1005];
        for(int i=0;i<=k;i++) table[0][i]=0;
        for(int i=0;i<=n;i++) table[i][0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++)
            {
                if(j<arr[i-1]){
                        table[i][j] = table[i-1][j];
                }
                else{
                    if(table[i-1][j]) table[i][j]=1;
                    else if(table[i-1][j-arr[i-1]]) table[i][j] = 1;
                    else table[i][j] = 0;
                }
            }
        }
       /* for(int i=0;i<n;i++)
        {
            for(int j=0;j<=k;j++)
                cout << table[i][j] << "  ";
            cout << endl;
        }*/
        if(table[n-1][k]) cout << 1 << endl;
        else  cout << 0 << endl;
    }
    return 0;
}
///Alhamdulillah
