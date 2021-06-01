#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int test;
   while(1){
    cin>>test;
    cin.ignore();
    if(test==0)break;
    string highway;
    getline(cin,highway);
    int minlength=test,j=-test,p=-test,dis;
    for(int i=0;i<test;i++)
    {
        if(highway[i]=='Z'){minlength=0;break;}
        else if(highway[i]=='R'){
            minlength=min(minlength,i-p);
            j=i;
        }
        else if(highway[i]=='D')
        {
            minlength=min(minlength,i-j);
            p=i;
        }
    }
    cout<<minlength<<"\n";
}
    return 0;
}
