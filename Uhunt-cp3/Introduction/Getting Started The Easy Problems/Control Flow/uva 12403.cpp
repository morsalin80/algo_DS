#include<iostream>
#include<string>
using namespace std;
int main()
{
    int test,amount=0,donation;
    string operations;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        cin>> operations;
        if(operations=="donate")
        {
            cin>> donation;
            amount+=donation;
        }
        if(operations=="report")
            cout << amount<<endl;

    }
    return 0;
}

