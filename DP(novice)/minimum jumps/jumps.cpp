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
int n,input[100],noj[100],aj[100];
void jumps(){
    for(int i=0;i<n;i++){noj[i]=highest(int);}
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(i<=j+input[j]){
                noj[i] = min(noj[i],noj[j]+1);
                if(noj[i]==noj[j]+1) aj[i] = j;
            }
        }
    }
}
int main()
{
    IOS
    cout << "number of station: ";
    cin>>n;
    cout << "Enter the "<< n << " station: ";
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    jumps();
    for(int i=0;i<n;i++) cout << noj[i] << "  ";
    cout << endl;
    for(int i=0;i<n;i++){
        cout << aj[i] << "  ";
    }
    cout << endl;
    return 0;
}
///Alhamdulillah
