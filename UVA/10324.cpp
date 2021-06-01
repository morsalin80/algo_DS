#include<iostream>
using namespace std;
int main()
{
    char str[1000000],in;
    int n,chk,temp,cas=0;
    while(cin>>str){
            cas++;
        cin>>n;
        int i[n],j[n];
        for(int k=0;k<n;k++){
                chk=0;
            cin >> i[k] >> j[k];
            if(k==0)
                 cout << "Case "<< cas << ":\n";
            if(i[k]>j[k])
            {
                temp = i[k];
                i[k] = j[k];
                j[k] = temp;
            }
            in = str[i[k]];
            for(int l=i[k]++;l<=j[k];l++){
                if(str[l]!=in){
                    chk=1;
                    break;
                }
            }

            if(chk==0)
                {
                    cout << "Yes\n";
                }
            if(chk==1)
            {
                cout << "No\n";
            }
        }

    }
    return 0;
}
