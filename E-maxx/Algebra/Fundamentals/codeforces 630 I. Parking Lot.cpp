/// Bismillahir Rahmanir Rahim
/* Author: Mohammad Morsalin (aka white_space)
    Dept of ICE, NSTU
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
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
    int n;
    while(cin>>n){
        ///this problems editorial is attach below:
        /*When n cars of the same make are the first or the last, there are 4 ways to choose the make of these n cars,
        then there are 3 ways to choose the make of one car adjacent to them (the make should be different from the make of n cars)
        and there are 4 ways to choose the make of each of the remaining n-3 cars. So the formula for the case of n cars of the same
        make on either end of the parking lot is 4*3*(4^n-3).

        When n cars of the same make are situated somewhere in the middle, there are 4 ways to choose the make of these n cars,
        then there are 3 ways to choose the make of each of two cars adjacent to them (the makes of these two cars should be different
        from the make of n cars) and there are 4 ways to choose the make of each of the remaining n-4 cars. So the formula for the case
        of n cars of the same make on a given position somewhere in the middle of the parking lot is 4*3*2*(4^n-4).

        There are 2 positions of n cars of the same make in the end of the parking lot and there are n-3 positions of n cars of the same
         make somewhere in the middle of the parking lot. So the final formula is 2*4*3*(4^n-3)+(n-3)4*(3^2)*(4^n-4).*/



         ll ans=24*pow(4,n-3);
         if(n>=4) ans+=(36*pow(4,n-4)*(n-3));
         cout << ans << endl;
    }
    return 0;
}
///Alhamdulillah
