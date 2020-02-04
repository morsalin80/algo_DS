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
vector<int>computeLcp(string pat){
    int m = pat.size();
    vector<int>lcp(m);
    lcp[0] = 0;
    int len = 0;
    int i = 1;
    while(i<m)
    {
        if(pat[len]==pat[i])
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
int kmp(string txt,string pat)
{
    vector<int>lcp=computeLcp(pat);
    int n=txt.size(),m = pat.size();
    int i = 0,j = 0;
    int cnt = 0;
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            i++;j++;
        }
        if(j==m)
        {
            cnt++;
            j = lcp[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
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
int main()
{
	IOS
    string s,t;
    cin>>s;
    vector<int>lcp;
    lcp=computeLcp(s);
    for(int i=0;i<lcp.size();i++)
        cout << lcp[i]<<" ";
    cout << endl;
    return 0;
}


