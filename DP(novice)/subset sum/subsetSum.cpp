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
int arr[101], tot,n;
bool t[101][101];
bool subsetSum(){

    for(int i=0;i<n;i++)
    {
        t[i][0] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=tot;j++){
            if(j<arr[i])t[i][j] = t[i-1][j];
            else {
                if(t[i-1][j]) t[i][j] = true;
                else if(t[i-1][j-arr[i]]) t[i][j] = true;
                else t[i][j] = false;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=tot;j++){
            cout << t[i][j] << "   ";
        }
        cout << endl;
    }
    if(t[n-1][tot]) return true;
    else return false;
}
int main()
{
    IOS
    cout << "give a set, firstly number of elements of the set: ";
    cin>>n;
    cout << "give "<< n << " elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "now give the total: ";
    cin>>tot;
    bool ans =subsetSum();
    if(ans) cout << "YES\n";
    else cout << "NO\n";
    if(ans){
        cout << "and the subset is: ";
        int i=n-1,j=tot;
        while(1){
            if(j==0) break;
            else{
                if(t[i][j]!=t[i-1][j]){
                    cout << arr[i] << " ";
                    j-=arr[i];
                    i--;
                }
                else{
                    i=i-1;
                }

            }
        }
    }
    return 0;
}
///Alhamdulillah
