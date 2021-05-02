#include<bits/stdc++.h>
using namespace std;
int xmove[8]={+2,+1,-1,-2,-2,-1,+1,+2};
int ymove[8]={+1,+2,+2,+1,-1,-2,-2,-1};
int sol[8][8];
void print(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout << sol[i][j]<<" ";
        }
        cout << endl;
    }
}
bool isSafe(int x,int y){
    return (x>=0 && x<8 && y>=0 && y<8 && sol[x][y]==-1);
}
bool solvek(int x,int y,int mov){
    int nx,ny;
    if(mov==8*8)return 1;
    for(int i=0;i<8;i++){
        nx=x+xmove[i];
        ny=y+ymove[i];
        if(isSafe(nx,ny)){
            //cout << mov << endl;
            sol[nx][ny]=mov;
            if(solvek(nx,ny,mov+1)==1){
                return 1;
            }
            else {
                sol[nx][ny]=-1;
            }
        }
    }
    return 0;
}
int main(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            sol[i][j]=-1;
        }
    }
    sol[0][0]=0;
    if(!(solvek(0,0,1))){
        cout << "no solution\n";
    }
    else{
        print();
    }
}
