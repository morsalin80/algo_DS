#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n1,n2;
int dp[110][110];
ll arr1[110];
ll arr2[110];
void lcs()
{
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(arr1[i]==arr2[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
int main()
{
    ll cs=0;
    while(1)
    {
        cin>>n1>>n2;
        if(n1==0 && n2==0) break;
        memset(arr1,0,sizeof arr1);
        memset(arr2,0,sizeof arr2);
        for(int i=1;i<=n1;i++)
        {
            cin>>arr1[i];
        }
        for(int i=1;i<=n2;i++)
        {
            cin>>arr2[i];
        }
        memset(dp,0,sizeof(dp[0][0])*110*110);
        lcs();
        cout << "Twin Towers #"<<++cs<<endl;
        cout <<"Number of Tiles : "<<dp[n1][n2] <<endl;
        cout << endl;
    }
    return 0;
}
