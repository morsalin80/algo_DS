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
int coins[100],n,mon;
int table[105][105];
void coin()
{
    for(int i=0;i<n;i++) table[i][0] = 0;
    for(int i=0;i<=mon;i++) table[0][i] = i;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=mon;j++)
        {
           // cout << table[i-1][j] << endl;
            if(j>=coins[i]){
            //    cout << table[i-1][j] <<" " << table[i][j-coins[i-1]]<<endl;
                table[i][j] = min(table[i-1][j],1+table[i][j-coins[i]]);
            }
            else table[i][j] = table[i-1][j];
        }
    }
}
int main()
{
    IOS
    cout << "enter number of coins: ";
    cin>>n;
    cout << "Enter "<<n << "coins value which have infinite stock: ";
    for(int i=0;i<n;i++)cin>>coins[i];
    cout << "Total money: ";
    cin>>mon;
    coin();
    for(int i=0;i<n;i++){
        for(int j=0;j<=mon;j++){
            cout << table[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "The numbers of coins require is: "<< table[n-1][mon]<<endl;
    cout << "and the coins were: ";
    int i=n-1,j=mon;
    while(1)
    {
      //  cout << i << " "<< j << endl;
        if(j==0) break;
        if(table[i][j]!=table[i-1][j]){
            cout << coins[i] << " ";
            j = j-coins[i];
        }
        else i--;
    }
    return 0;
}
///Alhamdulillah
