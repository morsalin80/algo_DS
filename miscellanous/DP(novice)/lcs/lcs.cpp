#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
string s1,s2;
void lcs()
{
    for(int i=0;i<s1.size();i++)
    {
        dp[i][0] = 0;
    }
    for(int i=0;i<s2.size();i++)
    {
        dp[0][i]=0;
    }
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
}
void lcs_back(){
    string s="";
    int i=s1.size();
    int j=s2.size();
    while(dp[i][j]!=0)
    {
        cout << s << endl;
        if(dp[i][j]!=dp[i-1][j]&& dp[i][j]!=dp[i][j-1] &&dp[i][j]==dp[i-1][j-1]+1)
        {
            s.push_back(s1[i-1]);
            i--;j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            j--;
        }
        else i--;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
}
int main()
{
    cout << "enter two string one by one: \n";
    cin>>s1>>s2;
    cout << "the lcs of these two string is: \n";
    lcs();
    lcs_back();
}
