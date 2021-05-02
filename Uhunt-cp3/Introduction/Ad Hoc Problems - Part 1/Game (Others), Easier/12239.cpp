#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,b;
    while(cin>>n>>b)
    {
        if(n==0&&b==0)break;
        bool call[n+1];
        for(int i=0;i<n+1;i++)
            call[i] = false;
        int arr[b];
        for(int i=0;i<b;i++)
            cin>>arr[i];
        int diff;
        for(int i=0;i<b;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(arr[i]>=arr[j])
                    diff = arr[i] - arr[j];
                else
                    diff = arr[j] - arr[i];
                call[diff] = true;
            }
        }
        bool chk = true;
        for(int i=0;i<n+1;i++)
        {
            if(!call[i]) {chk = false;break;}
        }
        if(chk) cout << "Y\n";
        else cout <<"N\n";
    }
    return 0;
}
