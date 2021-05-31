#include<iostream>
using namespace std;
int main()
{
    int test,call,mguni,jguni,mile,juice;
    cin >> test;
    for(int i=1; i<=test; i++)
    {
        cin >> call;
        int duration[call];
        mile=0;juice=0;
        for(int j = 0; j<call; j++)
        {
            mguni=1;jguni=1;
            cin >> duration[j];
            mguni+=duration[j]/30;
            jguni+=duration[j]/60;
            mile+=mguni*10;
            juice+=jguni*15;
        }
        cout << "Case "<<i<<": ";
        if(mile<juice)
            cout << "Mile "<<mile<<endl;
        else if(mile > juice) cout << "Juice "<<juice<<endl;
        else if(mile==juice) cout << "Mile Juice "<< juice<<endl;
    }
}
