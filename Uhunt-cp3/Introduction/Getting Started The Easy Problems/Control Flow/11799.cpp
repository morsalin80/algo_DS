#include<iostream>
using namespace std;
int main()
{
    int test,number,biggest;
    cin >> test;
    for(int i = 1;i<=test ; i++)
    {
        biggest = 0;
        cin >> number;
        int speed[number];
        for(int j = 0; j< number ; j++)
        {
            cin >>speed[j];
        }
        for(int j = 0; j < number ; j++)
        {
            if(speed[j]>biggest) biggest= speed[j];
        }
        cout << "Case "<<i << ": "<<biggest<<endl;
    }
    return 0;
}
