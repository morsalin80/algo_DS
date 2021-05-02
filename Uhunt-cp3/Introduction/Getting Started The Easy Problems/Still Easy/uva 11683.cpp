#include<iostream>
using namespace std;
int main()
{
    int a,c,d,count;
    int x[10000];
    while(cin>>a>>c, a)
    {
        count = 0;
        for(int i=0;i<c;i++)
        {
            cin >> x[i];
        }
        for(int i=0;i<c;i++)
        {
            if(i==0){count = a-x[i];
            d=x[i];}
            else if(x[i]<d)
            {
                count +=(d-x[i]);
            }
            d=x[i];
        }
        cout << count << endl;

    }
     return 0;
}
