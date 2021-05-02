#include<iostream>
using namespace std;
int main()
{
    int test;
    cin >> test;
    int hight,width,length;
    for (int i=1;i<=test;i++)
    {
        cin>>hight>>width>>length;
        if(hight<=20 && width<=20 && length<=20)
            cout << "Case "<<i << ": "<< "good\n";
        else
            cout << "Case "<<i << ": "<< "bad\n";
    }
    return 0;
}
