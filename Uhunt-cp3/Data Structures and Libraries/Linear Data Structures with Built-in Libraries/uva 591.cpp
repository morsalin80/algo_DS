/// Bismillahir Rahmanir Rahim

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define IOS ios::sync_with_stdio(false);
using namespace std;
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

    int cs = 0;
    while(1)
    {
        cs++;
        cin>>n;
        if(n==0){break;}
        int sum=0;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        int mean = sum/n;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+= abs(arr[i]-mean);
        }
        cout << "Set #"<<cs<< endl;
        cout << "The minimum number of moves is "<<cnt/2<<".\n";
        cout << endl;
    }
    return 0;
}
///Alhamdulillah
