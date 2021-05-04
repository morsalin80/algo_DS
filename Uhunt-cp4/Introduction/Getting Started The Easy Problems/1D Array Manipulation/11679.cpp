#include<iostream>
using namespace std;
int main()
{
    int banks,deventures,debtor,creditor,value;
    while(true)
    {
        cin>>banks>>deventures;
        if(banks==0 && deventures==0)
            break;
        int reserve[banks];
        for(int i=0;i<banks;i++)
            cin>>reserve[i];
        for(int i=0;i<deventures;i++){
                cin >> debtor >> creditor>> value;
                reserve[debtor-1]-=value;
                reserve[creditor-1]+=value;
        }
        int count=0;
        for(int i=0;i<banks;i++)
        {
            if(reserve[i]<0){ count = 1;break;}
        }
        if(count == 0)
            cout << "S\n";
        else
            cout<< "N\n";
    }
    return 0;
}
