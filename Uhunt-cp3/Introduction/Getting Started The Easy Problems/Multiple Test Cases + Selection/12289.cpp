#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int num;
    cin>>num;
    string number;
    for(int i=0;i<num;i++)
    {
        cin>>number;
            if(number.length()==3){
            if(number[0]=='o' && number[1]=='n') cout << "1\n";
            else if(number[0]=='o' && number[2]=='e')cout << "1\n";
            else if(number[1]=='n' && number[2]=='e')cout << "1\n";
            else if(number[0]=='t' && number[1]=='w')cout << "2\n";
            else if(number[0]== 't' && number[2]=='o') cout << "2\n";
            else if(number[1]=='w' && number[2]== 'o') cout << "2\n";
            }
            else if(number.length()==5)
                cout << "3\n";

    }
    return 0;
}
