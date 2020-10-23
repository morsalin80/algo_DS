#include <bits/stdc++.h>
#define pb push_back
#define MAX 1000006
#define mod 1000000009
#define read freopen("input.txt","r",stdin);
#define base 31
using namespace std;
typedef long long ll;
typedef unsigned long long llu;

llu ary[MAX],ah,bh[MAX];

int main()
{
   // read;
    ary[0]=1;
    for(int i=1; i<=MAX; i++) {ary[i]=ary[i-1]*base;}  //  using hashing
    string a,b;
    int lena,lenb;
    while(cin>>lena>>a>>b)
    {
        lenb=b.size();
        ah=0;
        memset(bh,0,sizeof(bh));
        for(int i=lena-1; i>=0; i--) {ah=ah*base+a[i]; cout << ah << endl;}
        for(int i=lenb-1; i>=0; i--){ bh[i]=bh[i+1]*base+b[i];}
        bool flag=false;
        if(lena<=lenb)
        {

            for(int i=0; i<=lenb-lena; i++)
            {

                llu c=bh[i]-(bh[i+lena]*ary[lena]);
                cout << c << " "<< ah << endl;
                if(ah==c )
                {
                    printf("%d\n",i);
                    flag=true;
                }
            }
        }

        if(!flag) puts("");
    }

    return 0;
}

