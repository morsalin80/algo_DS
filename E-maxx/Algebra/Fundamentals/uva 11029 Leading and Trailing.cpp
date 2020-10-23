/// Bismillahir Rahmanir Rahim
/* Author: Mohammad Morsalin (aka white_space)
    Dept of ICE, NSTU
*/
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
ll bigmod(ll b, ll p, ll m){
    if(p==0)return 1;
    ll xx=bigmod(b, p/2, 1000);
    xx=(xx*xx)%1000;
    if(p%2==1)xx=(xx*b)%1000;
    return xx;
}
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ///for first 3 digits we will use logarithms.below method will describe the thing,these text is copied from geeksforgeeks
        /*
        The next method involves using logarithms to calculate the first k digits. The method and steps are explained below:

        Let product = nn. Take logarithm base 10 on both sides of the equation. We get log10(product) = log10(nn), which we can also
        write as n*log10(n)
        In this example, we get log10(product) = 3871.137516. We can split the RHS as 3871 + 0.137516, so our equation can now be
        written as log10(product) = 3871 + 0.137516
        Raise both sides with base 10, and using the above example, we get product = 103871 x 100.137516. 103871 will not make a
        difference to our first k digits as it only shifts decimal points. We are interested in the next part, 100.137516, as this
        will determine the first few digits.
        In this case, the value of 100.137516 is 1.37251.
        Hence our required first 5 digits would be 13725.*/

        double x=k*(log10(n));
        x=x-(int)x;              // taking fraction value only
        double ans=pow(10, x);
        ans=ans*100;
        cout<<(int)ans<<"...";
        ///for the last 3 digits we will just use binary exponential modulo 1000;
        printf("%03d\n", bigmod(n, k, 1000));
    }
    return 0;
}
///Alhamdulillah
