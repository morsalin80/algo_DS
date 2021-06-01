#include<iostream>
#include<string>
using namespace std;
int main()
{
    int round,stroke,num,count;
    string solution,guess;
    while(cin>>round){
        if(round==-1) break;
        cin>>solution>>guess;
        bool chk;
        int size_of_solution = solution.length();

        int size_of_guess= guess.length();
         for(int i=0;i<size_of_guess-1;i++)
         {
             for(int j=i+1;j<size_of_guess;j++){
                if(guess.at(i) == guess.at(j))
                    guess.at(j) = '-';
             }
         }
         //cout << guess<<endl;
        count= 0;stroke = 0;
        for(int i=0;i<size_of_guess;i++){
                chk = false;
                if(guess.at(i) == '-') chk = true;
            for(int j=0;j<size_of_solution;j++){
                    //cout << "guess and solution are: "<<guess.at(i) << " "<< solution.at(j)<<endl;
                if(guess.at(i)==solution.at(j))
                {
                    count++;
                    solution.at(j) = '0';
                    //cout << "same: guess and solution are: "<<guess.at(i) << " "<< solution.at(j)<< "and count is: "<<count<<endl;
                    chk = true;
                }
            }
            if(!chk){
                stroke++;
                if(stroke==7) break;
            }
        }
        cout<< "Round "<<round<<endl;
        if(count==size_of_solution) cout << "You win.\n";
        else if(stroke==7) cout << "You lose.\n";
        else if(stroke!=7 && count!=size_of_solution) cout << "You chickened out.\n";
    }
    return 0;
}
