#include<bits/stdc++.h>
using namespace std;
int total_wt;
int total_item;
int value[100];
int wt[100];
int dp[100][100];
void knapsack()
{
    for(int i=0;i<total_item;i++)
    {
        for(int j=1;j<=total_wt;j++)
        {
            if(j<wt[i]){
                if(i==0)
                dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j];
            }
            else {
                    if(i==0) dp[i][j] = value[i];
                    else dp[i][j] = max(value[i]+dp[i-1][j-wt[i]],dp[i-1][j]);
            }
        }
    }
}
void backk()
{
    int i=total_item-1;
    int j=total_wt;
    cout << "item chosen: ";
    while(dp[i][j]!=0)
    {
        if(dp[i][j]!=dp[i-1][j])
        {
            cout << i+1 << " ";
            j-=wt[i];
            i--;
        }
        else
        {
            i--;
        }
    }
}
int main()
{
    cout << "Put total wt: ";
    cin>>total_wt;
    cout << "Give total item: ";
    cin>>total_item;
    cout << "Give "<< total_item << " value and weight respectively: ";
    for(int i=0;i<total_item;i++){
        cin>>wt[i]>>value[i];
        dp[i][0]=0;
    }
    knapsack();
    for(int i=0;i<total_item;i++)
    {
        for(int j=0;j<=total_wt;j++)
            cout << dp[i][j] << "  ";
        cout << endl;
    }
    ///for get what items choosen
    backk();
}
