#include<iostream>
using namespace std;
int main()
{
    int test;
    cin>>test;
    long long farmers,sum,budget_per;
    while(test--)
    {
        sum = 0;
        cin>>farmers;
        long long farmyard[farmers],animals[farmers],eco[farmers];
        for(long long i=0;i<farmers;i++)
        {
            cin>>farmyard[i]>>animals[i]>>eco[i];
        }
        for(long long i=0;i<farmers;i++)
        {
            budget_per = farmyard[i]*eco[i];
            sum +=budget_per;

        }
        cout<<sum<<endl;
    }
    return 0;
}
