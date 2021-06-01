#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,result,temp;
    while(cin >> a>>b)
    {
        if(a==-1 && b==-1)
            break;
        if(a>b)
        {
            temp = b;
            b = a;
            a = temp;
        }
        c = b - a;
        d =  (100+a)-b;
        if(c>d)
            result = d;
        else
            result = c;
        cout << result<<endl;
    }
    return 0;
}
