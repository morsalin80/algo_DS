#include<iostream>
#include<string>
using namespace std;
int main()
{
    int test;
    cin>> test;
    for(int i=1;i<=test;i++)
    {
        string res;
        cin>>res;
        int len;
        len= res.size();
        if(res=="1"||res=="4"||res=="78")
            cout << "+\n";
        else if(res[len-2]=='3'&& res[len-1]=='5')
            cout << "-\n";
        else if(res[0]=='9' && res[len-1]=='4')
            cout << "*\n";
        else
            cout << "?\n";

    }
    return 0;
}
