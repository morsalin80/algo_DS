#include<iostream>
using namespace std;
int main()
{
    int test=0;
    string str;
    while(true)
    {
        test++;
        cin>>str;
        if(str=="*")break;
        else if(str=="Hajj")
            cout << "Case "<<test<< ": Hajj-e-Akbar"<<endl;
        else if(str=="Umrah")
            cout << "Case "<<test<< ": Hajj-e-Asghar"<<endl;
    }
    return 0;
}
