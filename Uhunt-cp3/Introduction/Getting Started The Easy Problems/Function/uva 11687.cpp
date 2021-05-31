#include<iostream>
#include<string>
using namespace std;
int main()
{
    string number;
    int length;
    while(cin>>number,number!="END")
    {
        length=number.size();
        if(number=="1")
            cout<<"1"<<endl;
        else
        {
            if(length==1) cout<< "2\n";
            else if(length>1 && length<10) cout << "3\n";
            else if(length>=10) cout << "4\n";
        }

    }
    return 0;
}
