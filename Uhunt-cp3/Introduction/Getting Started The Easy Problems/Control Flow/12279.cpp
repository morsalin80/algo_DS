#include<iostream>
using namespace std;
int main()
{
    int test=0;
    while(true)
    {
        test++;
        int n;
        cin>>n;
        if(n==0)break;
        int event[n],reason=0,treat=0;
        for(int i=0;i<n;i++)
        {
            cin>>event[i];
            if(event[i]==0) treat++;
            else if(event[i]>0 && event[i]<100) reason++;
        }
        int balance;
        balance = reason - treat;
        cout << "Case "<<test<< ": "<<balance<<endl;
    }
    return 0;
}
