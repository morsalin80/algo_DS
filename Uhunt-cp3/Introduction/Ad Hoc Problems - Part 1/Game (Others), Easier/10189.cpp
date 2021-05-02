#include<iostream>
using namespace std;
int main()
{
    int n,m,count,field=0;
    while(1)
    {
        field++;
        bool b = true;
        cin>>n>>m;
        if(n==0&&m==0) break;
        string squares[n];
        for(int i=0;i<n;i++)
            cin>>squares[i];
        if(b && field!=1)cout << endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
               count = 0;
               //cout << "i and j" << i << " "<<j<<endl;
               //cout << "after check\n";
               //cout << squares[i].at(j)<<endl;
               if(i==0 &&j ==0) cout << "Field #"<<field<< ":\n";

            if(squares[i].at(j)=='.'){
                    //cout << "Fuck in\n";
                if(j-1>=0&&squares[i].at(j-1)=='*')
                    count++;
                if(j+1<m&&squares[i].at(j+1)=='*')
                    count++;
                if((i-1>=0&&j-1>=0)&&squares[i-1].at(j-1)=='*')
                    count++;
                if(i-1>=0&&squares[i-1].at(j) == '*')
                    count++;
                if((i-1>=0&&j+1<m)&&squares[i-1].at(j+1)=='*')
                    count++;
                if((i+1<n&& j-1>=0)&&squares[i+1].at(j-1)=='*')
                    count++;
                if(i+1<n&&squares[i+1].at(j)=='*')
                    count++;
                if((i+1<n&&j+1<m)&&squares[i+1].at(j+1)=='*')
                    count++;
                squares[i].at(j) = count + 48;

               }
             cout << squares[i].at(j);
            }
             cout << endl;
        }
        b = false;
    }
    return 0;
}
