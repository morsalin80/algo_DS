/// Bismillahir Rahmanir Rahim
/* Mohammad Morsalin
   Dept of ICE, NSTU
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define int long long
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ms2d(x,m,n) memset(x, 0, sizeof(x[0][0]) * m * n)
#define uniq(vec) vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi pair<int,int>
#define tc(t) int t;cin>>t;while(t--)
#define bits(n) __builtin_popcount(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define ins insert
#define ALL(v) v.begin(),v.end()
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define fi first
#define se second
#define PI acos(-1)
#define sz(a) (int)a.size();
#define IOS ios::sync_with_stdio(false);
using namespace std;
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
//typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const long long MOD = 1000000007;
double sq(double x) {return x*x;}
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
const int maxx=1000006;
unsigned int precal[maxx],hh[maxx];
signed main()
{
    IOS
    precal[0]=1;
    unsigned int p=31;
    for(int i=1;i<=maxx;i++){
        precal[i]= precal[i-1]*p;
    }
    unsigned int a,b;
    string sa,sb;
    while(cin>>a>>sa>>sb){
        unsigned int h=0;
        for(int i=a-1;i>=0;i--){
            h = h*p+sa[i];
         //  	cout << "h: "<< h << endl;
        }
        ms(hh);
        for(int i=(int)sb.size()-1;i>=0;i--){
            hh[i]=hh[i+1]*p+sb[i];
           // cout << hh[i] << " ";
            //debug(hh[i]);
        }
        bool ok=0;
        b=sb.size();
        if(a<=b){
            for(int i=0;i<=b-a;i++){
                unsigned int cur_h=hh[i]-(hh[i+a]*precal[a]);
                //cout << cur_h << " " << h << endl;
                //debu(cur_h,h);
                if(cur_h==h){
                    cout << i << endl;
                    ok=1;
                }
            }
        }
        if(!ok)cout << endl << endl;
    }
    return 0;
}
///Alhamdulillah
