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
vector<int>a,b;
vector<int>computeLcp(){
    int m = b.size();
    vector<int>lcp(m);
    lcp[0] = 0;
    int len = 0;
    int i = 1;
    while(i<m)
    {
        if(b[len]==b[i])
        {
            len++;
            lcp[i] = len;
            i++;
        }
        else{
            if(len!=0)
            {
                len = lcp[len-1];
            }
            else
            {
                lcp[i] = 0;
                i++;
            }

        }
    }
    return lcp;
}
int kmp()
{
    vector<int>lcp=computeLcp();
    int n=a.size(),m = b.size();
    int i = 0,j = 0;
    int cnt = 0;
    while(i<n)
    {
        cout << b[j] << " "<< a[i] << endl;
        if(b[j]==a[i])
        {
            i++;j++;
        }
        if(j==m)
        {
            cnt++;
            j = lcp[j-1];
        }
        else if(i<n && b[j]!=a[i])
        {
            if(j!=0)
            {
                j = lcp[j-1];
            }
            else i++;
        }
    }
    return cnt++;
}
signed main()
{
    IOS
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.pb(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.pb(x);
    }
    for(int i=0;i<n;i++){
        a.pb(a[i]);
    }
    cout << kmp() << endl;
    return 0;
}


