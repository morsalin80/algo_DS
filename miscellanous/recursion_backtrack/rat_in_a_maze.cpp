#include<bits/stdc++.h>
using namespace std;
const int n=4;
int sol[n][n];
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int maze[n][n],int x,int y){
    return (x>=0 && x<n && y>=0 && y<n && maze[x][y]==1);
}
bool mazeS(int maze[n][n],int x,int y){
    if(x==n-1 && y==n-1 && maze[x][y]==1){
        sol[x][y]=1;
        return 1;
    }
    if(isSafe(maze,x,y)){
        sol[x][y]=1;
        if(mazeS(maze,x+1,y)){
            return 1;
        }
        if(mazeS(maze,x,y+1)){
            return 1;
        }
        sol[x][y]=0;
        return 0;
    }
    return 0;
}
int main()
{
    int maze[n][n]={ { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sol[i][j]=0;
        }
    }
    if(!mazeS(maze,0,0)){
        cout << "No solution\n";
    }
    else{
        print();
    }
}
