#include<bits/stdc++.h>
using namespace std;
const int n=4;
int board[n][n];
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int x,int y){
    for(int i=0;i<y;i++){
        if(board[x][i]==1){
            return 0;
        }
    }
    for(int i=x,j=y;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1)
            return 0;
    }
    for(int i=x,j=y;i<n && j>=0;i++,j--){
        if(board[i][j]==1)
            return 0;
    }
    return 1;
}
bool nqueen(int y){
    if(y>=n){
        return 1;
    }
    for(int i=0;i<n;i++){
        if(isSafe(i,y)){
            board[i][y]=1;
            if(nqueen(y+1)){
                return 1;
            }
            board[i][y]=0;
        }
    }
    return 0;
}
int main(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    if(!nqueen(0)){
        cout << "No solutions\n";
    }
    else {
        print();
    }
}
