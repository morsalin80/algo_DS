#include<bits/stdc++.h>
using namespace std;
int p[1003],w[1003];
int dp[1003][35];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(p,0,sizeof(p));
        memset(w,0,sizeof(w));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>p[i]>>w[i];
        }
        int g;
        cin>>g;
        long long ans=0;
        while(g--)
        {
            for(int i=0;i<n;i++)
            {
                dp[i][0] = 0;
            }
            int mw;
            cin>>mw;
            for(int i=0;i<n;i++)
            {
                for(int j=1;j<=mw;j++)
                {
                    if(j<w[i]){
                        if(i==0) dp[i][j] = 0;
                        else dp[i][j] = dp[i-1][j];
                    }
                    else{
                        if(i==0) dp[i][j] = p[i];
                        else dp[i][j] = max(p[i]+dp[i-1][j-w[i]] , dp[i-1][j]);
                    }
                }
            }
            ans+= dp[n-1][mw];
        }
        cout << ans << endl;
    }
}
