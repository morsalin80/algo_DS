#include<iostream>
using namespace std;
int main()
{
    int n,m,c,sum,k=0,max_sum;
    while(cin >> n>>m>>c)
    {
        if(n==0 && m==0 && c == 0)
            break;
        k++;
        int device[n],count;
        max_sum = -1000;
        sum=0;
        int operations[m];
        for(int i=0;i<n;i++)
            cin >> device[i];
        for(int i = 0;i<m;i++)
            cin >> operations[i];
        cout << "Sequence "<<k<<endl;
        for(int i=0;i<m;i++)
        {
            count = 1;
            for(int j = 0;j <i;j++)
            {
                if(operations[i]==operations[j])
                    count++;
            }
            if(count%2==0){
                sum -= device[operations[i]-1];
                if(sum>max_sum)
                    max_sum = sum;
            }
            if(count%2!=0)
            {
                sum += device[operations[i]-1];
                if(sum>max_sum)
                    max_sum = sum;
            }
            cout << "i = "<< i<< " count = "<< count << " operations[i] = "<< operations[i] << " sum = "<< sum << " max_sum = "<<max_sum<<endl;
            if(sum>c)
            {
                cout << "Fuse was blown.\n";
                break;
            }

        }
        if(sum<=c)
        {
            cout << "Fuse was not blown\n";
            cout << "Maximal power consumption was "<<max_sum<< " amperes.\n";
        }
        cout << endl;
    }
    return 0;
}
