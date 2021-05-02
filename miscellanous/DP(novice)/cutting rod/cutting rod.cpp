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
int n,size[100],val[100],rod;
int t[100][100];
void rod_cutting(){
    for(int i=0;i<=n;i++){
        t[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=rod;j++){
            cout << val[i] << " val::i "<<i << endl;
            if(j>=i){
                t[i][j] = max(t[i-1][j],val[i]+t[i][j-i]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
}
int main()
{
    IOS
    cout << "Enter number of rod: ";
    cin>>n;
    cout << "enter the size and value of the rod: ";
    for(int i=1;i<=n;i++){
        cin>>size[i]>>val[i];
    }
    cout << "enter the length of the main rod: ";
    cin>>rod;
    rod_cutting();
   /* for(int i=0;i<=n;i++){
        for(int j=0;j<=rod;j++){
            cout << t[i][j] << "  ";
        }
        cout << endl;
    }*/
    cout << "the maximum profit is: "<< t[n][rod] << endl;
    return 0;
}
///Alhamdulillah
