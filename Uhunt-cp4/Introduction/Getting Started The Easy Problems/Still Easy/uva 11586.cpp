#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    for(int i=1;i<=t;i++)
    {
        string piece;
        int l,j,count=0;
        getline(cin,piece);
        l=piece.size();
        for(string::iterator itr=piece.begin();itr!=piece.end();++itr)
        {
            if(*itr== 'M')++count;
            if(*itr== 'F')--count;
        }
        if(count==0 && l>3)cout<< "LOOP\n";
        else
            cout << "NO LOOP\n";
    }
    return 0;
}
