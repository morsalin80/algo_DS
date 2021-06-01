#include<iostream>
using namespace std;
int main()
{
    int test;
    long long a,b;
    cin>> test;
    for(int i=0;i<test;i++)
    {
        cin>>a>>b;
        if(a==b)
            cout << "=\n";
        if(a>b)
            cout << ">\n";
        if(a<b)
            cout << "<\n";
    }
    return 0;
}
