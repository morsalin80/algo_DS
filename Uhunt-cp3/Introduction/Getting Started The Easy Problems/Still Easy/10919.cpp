#include<iostream>
using namespace std;
int main()
{
    int k,m,take,must_take,cot,chk;
    int course[105];
    while(cin>>k>>m){
            if(k==0 || m==0)
            break;
        int courses[k];
        chk=1;
        for(int i = 0;i<k;i++)
            cin>>courses[i];
            int take[m],must_take[m];
            for(int i = 0;i<m;i++)
            {
                cin>>take[i]>>must_take[i];
                  for(int j=0;j<take[i];j++)
                {
                    cin>>course[j];
                }
            }
            for(int l=0;l<m;l++){
                for(int i=0;i<take[l];i++)
                {
                    cot = 0;
                    cout << "\nTake course: "<<course[i]<<endl;
                    for(int j=0;j<k;j++)
                    {
                        cout << " courses  " <<courses[j] << " ";
                        if(course[i]==courses[j]){
                            cot++;
                        cout << "count = "<< cot << " must_take: "<< must_take[l]<<endl;
                    }}
                    if(cot<must_take[l])
                            {
                                chk=0;
                                goto check;
                            }
                }
            }
            check:
              if(chk==1){
                cout << "yes\n";
            }
            else if(chk==0)
                cout << "no\n";
    }
    return 0;
}
