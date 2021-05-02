#include<iostream>
using namespace std;
int main()
{
    int test,walls,lowjump,highjump;
    cin>>test;
    for(int i = 1;i<=test;i++)
    {
        lowjump=0;
        highjump = 0;
        cin>>walls;
        int hight[walls];
        for(int j = 0;j< walls; j++)
        {
            cin>> hight[j];
        }
        for(int j = 0; j<walls-1 ; j++)
        {
            if(hight[j]>hight[j+1]) lowjump++;
            if(hight[j]<hight[j+1]) highjump++;
        }
        cout << "Case "<<i << ": "<< highjump << " " << lowjump <<endl;

    }
}
