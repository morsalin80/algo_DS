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

int main()
{
    IOS
    int n;
    freopen("input00.txt","r",stdin);
    freopen("output00.txt","w",stdout);
    int cs=0;
    while(1){
        cin >>n;
        if(n==0) break;
        int arr[n+1][10];
        int cc[n+1];
        int aa[n+1];
        int bb[n+1];
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            cc[i]=c;
            aa[i] = a;
            bb[i] = b;
        }
        int stat[n+1];
        int aw[n+1],sl[n+1];
        ms(aw);ms(sl);
        int noa=0,nos=0;
        for(int i=1;i<=n;i++){
            if(cc[i]<=aa[i]){ stat[i]=1;aw[i] = cc[i];noa++;}
            else if(cc[i]>aa[i]) {stat[i]=2;sl[i]=cc[i]-aa[i];nos++;}
        }
        bool got=0;
        //cout << nos << " "<< noa << endl;
        cout << "Case "<<++cs << ": ";
        for(int i=1;i<1000;i++){
            if(noa==n){
                got=1;
                cout << i << endl;
                break;
            }
         //   cout << i << "::\n";
            int tema=0,tems=0;
            for(int j=1;j<=n;j++){
              //  cout << stat[j] << " ";

                if(stat[j]==1){

                   // cout << "awake: " <<aw[j] << endl;
                    if(aw[j]==aa[j]){
                        if(nos>noa){
                            aw[j] = 0;
                            stat[j] = 2;
                            sl[j]++;
                            tems++;
                            tema--;
                        }
                        else{
                            aw[j] = 1;
                        }
                    }
                    else aw[j]++;
                }
                else if(stat[j]==2){
                //   cout << "sleep: "<<sl[j] << endl;
                    if(sl[j]==bb[j]){
                        sl[j]=0;
                        stat[j] = 1;
                        aw[j]++;
                        tema++;
                        tems--;
                    }
                    else sl[j]++;
                }
            }
            nos+=tems;
            noa+=tema;
        }
        if(!got) cout << "-1\n";
    }
    return 0;
}
///Alhamdulillah
