#include<iostream>
using namespace std;
int main()
{
    int N,j,game=0;
    while(1){
        cin>> N;
        game++;
        if(N==0) break;
        while(1){
        int code[N];
        int Test[N];
        int guess[N];
        int strong=0,weak=0,guess_counter=0;
        for(int i=0;i<N;i++)
            cin>>code[i];
        Guess:
            guess_counter++;
            bool allzero = true;
            for(int i=0;i<N;i++){
                cin>>guess[i];
                if(guess[i]!=0) allzero = false;
                Test[i] = code[i];
            }
            if(allzero==true) break;
            strong = 0; weak = 0;
            for(int i=0,j=0;i<N;i++,j++)
            {
                if(Test[i]==guess[j]){
                    strong++;
                    Test[i] = -1;
                    guess[j] = -2;
                }
            }
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++){
                    if(Test[i] == guess[j])
                    {
                        weak++;
                        guess[j] = -2;
                        break;
                        //cout << "weak at: i="<<i<<"and j="<<j<<endl;
                    }
                }
            }
            if(guess_counter==1)cout << "Game "<<game<< ":\n";
            cout << "    ("<<strong<<","<<weak<< ")\n";
            goto Guess;
    }}
}
