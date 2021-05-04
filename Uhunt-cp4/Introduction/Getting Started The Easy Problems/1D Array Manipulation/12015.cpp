#include<iostream>
using namespace std;
int main()
{
    int test,big;
    string url[10];
    int rele[10];
    cin >> test;
    for(int i = 1;i <=test; i++)
    {
        big = 0;
        for(int j = 0; j<10; j++)
        {
            cin >> url[j] >> rele[j];
            if(big<rele[j]) big = rele[j];
        }
        cout << "Case #"<<i<< ":\n";
        for(int j = 0; j<10; j++)
        {
            if(rele[j]==big){
                cout << url[j]<<endl;
            }
        }
    }
    return 0;
}
