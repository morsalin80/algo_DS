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
int n,coins[100],t[100][100],tot;
void coinway(){
    for(int i=1;i<=n;i++){
        t[i][0] = 1;
        for(int j=1;j<=tot;j++){
            if(j>=coins[i]){
                t[i][j] = t[i-1][j] + t[i][j-coins[i]];
            }
            else t[i][j] = t[i-1][j];
        }
    }
}
int main()
{
    IOS
    cout << "Number of different coins: ";
    cin>>n;
    cout << "Put "<< n << " coins respectevly: ";
    for(int i=1;i<=n;i++)cin>>coins[i];
    cout << "Now put the tot: ";
    cin>>tot;
    coinway();
    cout << t[tot-1][tot-1] << endl;
    return 0;
}
///Alhamdulillah
