/// Bismillahir Rahmanir Rahim

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
string s;
int n,t[100][100];
void lps(){
    for(int i=0;i<n;i++)t[i][i] = 1;
    for(int k=1;k<n;k++)
    {
        for(int i=0,j=i+k;j<n && i<n;j++,i++){
            if(s[i]==s[j])
                t[i][j] = t[i+1][j-1] + 2;
            else
                t[i][j] = max(t[i+1][j],t[i][j-1]);
        }
    }
}
int main()
{
    IOS
    cout << "enter the size of the string: ";
    cin>>n;
    cout << "Now enter the string: ";
    cin>>s;
    lps();
   /* for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << t[i][j] << "  ";
        }
        cout << endl;
    }*/
    cout << "the lps length is: "<<t[0][n-1]<<endl;
    cout << "the lps is: ";
    string sub="";
    int i=0,j=n-1;
    while(1){
        if(t[i][j]==1){sub.pb(s[i]); break;}
        if(t[i][j]!=t[i][j-1] && t[i][j]!=t[i+1][j]){
            sub.pb(s[i]);
            i++;
            j--;
        }
        else{
            if(t[i][j]==t[i][j-1]){
                j--;
            }
            else{
                i++;
            }
        }
    }
    cout << sub;
    if(sub.size()%2!=0){
        for(int l=sub.size()-2;l>=0;l--)cout << sub[l];
    }
    else{
        reverse(sub.begin(),sub.end());
        cout << sub << endl;
    }
    return 0;
}
///Alhamdulillah
