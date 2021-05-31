#include<iostream>
using namespace std;
int main()
{
    int test,instr,same,phase;
    cin >> test;
    while(test--)
    {
        cin>>instr;
        phase = 0;
        string instruct[instr],str;
        for(int i =0;i<instr;i++){
            cin >> instruct[i];
            if(instruct[i]=="SAME"){
                cin>>str>>same;
                instruct[i]=instruct[same-1];
            }
            cout<<instruct[i]<<endl;
            if(instruct[i]=="LEFT")
                phase--;
            if(instruct[i]=="RIGHT")
                phase++;
        }
        cout <<phase<< endl;
    }
    return 0;
}
