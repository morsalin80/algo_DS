#include<iostream>
using namespace std;
int main()
{
    int groups,flag;
    int lumber[10];
    cin >> groups;
   for(int j = 1 ; j<= groups; j++)
    {
        flag = 1;
        for(int i=0;i<10;i++)
        {
            cin >> lumber[i];
        }
        if(lumber[0]>lumber[1])
        {
            for(int i = 1; i<9;i++){
                if(lumber[i]<lumber[i+1]){
                flag = 0; break;}
        }}
        else if(lumber[0]<lumber[1])
        {
            for(int i =1; i<9 ; i++)
            {
                if(lumber[i]>lumber[i+1]){
                    flag = 0; break;
                }
            }
        }
        if(j==1) cout << "Lumberjacks:\n";
        if(flag==0) cout << "Unordered\n";
        if(flag==1) cout << "Ordered\n";
    }
    return 0;
}
