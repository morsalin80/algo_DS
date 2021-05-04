#include<iostream>
using namespace std;
int main()
{
    int test;
    while(cin>>test && test!=0)
    {
        int t=1,b=6,e=4,w=3,n=2,s=5,temp1,temp2;
        string direction;
        for(int i=0;i<test;i++){
            cin>>direction;
            if(direction=="north")
            {
                temp1 = n;
                n = t;
                t = s;
                temp2 = b;
                b = temp1;
                s = temp2;
            }
            else if(direction=="east"){
                temp1 = t;
                t = w;
                e = temp1;
                temp2 = b;
                b = e;
                w = temp2;
            }
            else if(direction=="south"){
                temp1 = s;
                s = t;
                t = n;
                temp2 = b;
                b = temp1;
                n = temp2;
            }
            else if(direction=="west"){
                temp1 = w;
                w = t;
                t = e;
                temp2 = b;
                b = temp1;
                e = b;
            }
            cout << "North="<<n<<" south="<<s<< " east="<<e<< " west="<<w<<" ####top="<<t<<" bottom="<<b<<endl;
        }
        cout << t<<endl;
    }
    return 0;
}
