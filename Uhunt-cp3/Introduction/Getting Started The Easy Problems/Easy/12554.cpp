#include<iostream>
using namespace std;
int main()
{
    int people,f,i,j;
    string wishme[16]={ "Happy","birthday","to","you",
                        "Happy", "birthday", "to", "you",
                        "Happy", "birthday", "to", "Rujia",
                        "Happy","birthday","to","you"
                        };
    while(cin>>people){
            f=1;
        string wish[people];
        for( i = 0;i<people;i++)
            cin >> wish[i];
        f=f+people/16;
        i=0;
        for(int k=0;k<f;k++){
        for(j=0;j<16;j++)
            {
                cout << wish[i] << ": "<<wishme[j]<<endl;
                i++;
                if(i==people)
                    i=0;
            }}
    }
    return 0;
}
