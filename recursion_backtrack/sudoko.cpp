#include<bits/stdc++.h>
using namespace std;
const int n=9;
bool isSafe(int grid[n][n]){
    map<int,int>row[9],col[9],box[3][3];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int r=row[i][grid[i][j]]++;
            int c=col[j][grid[i][j]]++;
            int b=box[i/3][j/3][grid[i][j]]++;
            if(r>1 || c>1 || b>1 ){
                return false;
            }
        }
    }
    return true;
}
void print(int grid[n][n]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool sudoko(int grid[n][n],int i,int j){
    if(i==n-1 && j==n){
        if(isSafe(grid)){
            print(grid);
            return true;
        }
        else{
            return false;
        }
    }
    if(j==n){
        i++;j=0;
    }
    if(grid[i][j]!=0){
        return sudoko(grid,i,j+1);
    }
    for(int k=1;k<=9;k++){
        grid[i][j]=k;
        if(sudoko(grid,i,j+1)) return true;
        grid[i][j]=0;
    }
    return false;
}
int main(){
    int grid[9][9]={ { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
                       { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
                       { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
                       { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
                       { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
                       { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
                       { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
                       { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
                       { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
    if(!sudoko(grid,0,0)){
        cout << "No solution exists\n";
    }
    return 0;
}
