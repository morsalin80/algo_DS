#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,cas=0;
    float res,maximum;
    string maxi;
    string got= "  X   hU  an  mK  X gU  oh C  Gd   Q Ui";
    while(cin>>n>>m)
    {
        cas++;
        cin.ignore();
        //cout << n << " "<<m <<endl;
        if(n==0 && m == 0)
        {
            break;
        }
        string requirment[n];
        maximum = 0;
        for(int i = 0;i<n;i++){
            getline(cin,requirment[i]);
                        //cout << requirment[i] <<endl;
          }
        string proposals[m];
        int r[m];
        float d[m],max_price=10000000;
        for(int i = 0; i<m;i++){
            getline(cin,proposals[i]);
            //cout << proposals[i] << endl;
            cout << "\n"<<i<<"\n";
            if(proposals[i]==got)
            {
                cout << "\n\n\n\nFUCK\n"<<proposals[i]<<endl;
                cout << "\n\n" << i << "\n\n";
            }
            cin >> d[i]>>r[i];
            //cout << d[i] << " "<< r[i]<< endl;
            res = float(r[i])/float(n);
            cout << "result and maximum are " << res << " "<< maximum <<endl;

          if(res>=maximum){
                maximum=res;
                if(res==maximum)
                    {
                        if(d[i]<max_price){
                            maxi = proposals[i];
                            max_price = d[i];
                        }
                    }
                    else
                    maxi = proposals[i];}
            cout << "maxi = " << maxi <<endl;
            string rmet[r[i]];
            cin.ignore();
            for(int j=0;j<r[i];j++){
                getline(cin,rmet[j]);
            //    cout << rmet[j]<< endl;
            }
    }
    cout << "RFP #"<<cas<<endl;
    cout << maxi << endl;
    cout << endl;
    }
     return 0;
}

