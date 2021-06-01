    /// Bismillahir Rahmanir Rahim

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
    int main()
    {
        IOS
        int t,cs=0;
        scanf("%d",&t);
        while(t--)
        {
            cs++;
            int n,q;
            scanf("%d%d",&n,&q);
            int arr[n];
            for(int i=0;i<n;i++) scanf("%d",&arr[i]);
            printf("Case %d:\n",cs);
            while(q--)
            {
                int x,y,a,b;
                scanf("%d%d",&x,&y);
                a = lower_bound(arr,arr+n,x)-arr;
                b = upper_bound(arr,arr+n,y)-arr;
                printf("%d\n",b-a);
            }
        }
        return 0;
    }
    ///Alhamdulillah


