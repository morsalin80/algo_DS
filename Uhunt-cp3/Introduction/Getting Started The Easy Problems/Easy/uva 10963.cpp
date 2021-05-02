#include<iostream>
using namespace std;
int main()
{
    int test,n,y1,y2,dis,result;
    cin>>test;
    while(test--)
    {
        cin>>n;
        cin>> y1>> y2;
        dis= y1-y2;
        result=0;
        for(int i=1;i<n;i++)
        {
            cin>>y1>>y2;
            if(dis!=y1-y2)
                result=1;
        }
        if(result)
            cout << "no\n";
        else
            cout << "yes\n";
        if(test)
            cout << endl;
    }
    return 0;
}
