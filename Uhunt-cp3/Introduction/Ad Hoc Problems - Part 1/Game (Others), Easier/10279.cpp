#include<iostream>
using namespace std;
int main()
{
    int Test,game_num,n,count;
    cin>>Test;
    game_num = Test;
    bool flag;
    while(Test--)
    {
        //cout<< "While e dhukse\n";
        cin>> n;
        string game[n],touch[n];
        for(int i=0;i<n;i++)
            cin>> game[i];
        for(int i=0;i<n;i++)
            cin>> touch[i];
        flag = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                count = 0;
                if(touch[i].at(j)=='x')
                {
                    if(game[i].at(j) == '*') flag = false;
                    else if(game[i].at(j) == '.'){
                       if((i-1>=0 && j-1>=0)&& game[i-1].at(j-1)=='*') count++;
                       if(i-1>=0 && game[i-1].at(j)=='*') count++;
                       if((i-1>=0&&j+1<n)&& game[i-1].at(j+1)=='*') count++;
                       if(j-1>=0 && game[i].at(j-1)=='*') count++;
                       if(j+1<n && game[i].at(j+1)== '*') count++;
                       if((i+1<n && j-1>=0)&& game[i+1].at(j-1)=='*') count++;
                       if(i+1<n && game[i+1].at(j)=='*') count++;
                       if((i+1<n&& j+1<n) && game[i+1].at(j+1) =='*') count++;
                       game[i].at(j) = count+48;
                    }

                }
            }
        }
        if(flag){
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(game[i].at(j)=='*')
                        game[i].at(j) = '.';
                }
            }
        }
        for(int i=0;i<n;i++)
            cout << game[i] <<endl;
         if(Test!=game_num && Test>0){
            cout << "\n";
        }
    }
}
