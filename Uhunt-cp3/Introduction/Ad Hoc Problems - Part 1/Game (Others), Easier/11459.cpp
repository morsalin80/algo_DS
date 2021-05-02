#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test,a,b,c;
    cin>>test;
    while(test--){
        cin>>a>>b>>c;
        int player[a];
        for(int i=0;i<a;i++)
            player[i] = 1;
        int position[b][2];
        for(int i=0;i<b;i++)
            for(int j=0;j<2;j++)
                cin>>position[i][j];
        int turn,die;
        bool game_over = false;
        for(int roll=0;roll<c;roll++)
        {
            cin>>die;
            if(game_over)continue;
            turn = roll%a;
            player[turn]+=die;
            //cout << game_over<<endl;
            for(int i=0;i<b;i++)
            {
                if(player[turn]==position[i][0]){
                    player[turn]=position[i][1];
                    break;
                }
            }
            if(player[turn]>=100) game_over=true;
           // cout << "Player>>"<<player[turn] <<" game:"<<game_over<<endl;
        }
        for(int i=0;i<a;i++)
            cout << "Position of player "<<i+1<< " is " << player[i]<<"."<<endl;
    }
    return 0;
}
