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
string s1,s2;
int table[101][101],n,m;
void min_edit_dist(){
    n= s1.size();
    m = s2.size();
    cout << n << " "<< m << endl;
    for(int i=0;i<=n;i++){
        table[i][0] = i;
    }
    for(int i=0;i<=m;i++){
        table[0][i]= i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j]){
                table[i][j]=table[i-1][j-1];
            }
            else
            {
                table[i][j]= 1+min(table[i-1][j-1],min(table[i][j-1],table[i-1][j]));
            }
        }
    }
}
int main()
{
    IOS
    cout << "Put 2 string to check their minimum edit distance: ";
    cin>>s1>>s2;
    min_edit_dist();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << table[i][j] << "  ";
        }
        cout << endl;
    }
    cout << table[n][m] << endl;
    return 0;
}
///Alhamdulillah
