#include<iostream>
#include<string>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main()
{
    string name1,name2;
    int length1,length2,sum1,sum2,rem,temp;
    float result;
    while(getline(cin,name1)){
        getline(cin,name2);
        length1=name1.size();
        length2 = name2.size();
        sum1=0;sum2=0;
        for(int i = 0;i<length1;i++)
        {
            if(name1[i]>=65 && name1[i]<=122){
                  //  cout << name1[i] << " = " <<endl;
                if(name1[i]>=65 && name1[i]<91)
                    sum1 += name1[i]-64;//cout << sum1 <<endl;}
                else if(name1[i]>=97)
                    sum1 += name1[i]-96;//cout << sum1 << endl;}
            }

        }
        for(int i =0;i<length2;i++)
        {
            if(name2[i]>=65 && name2[i]<=122){
                    // cout << name2[i] << " = " <<endl;
                if(name2[i]>=65 && name2[i]<91)
                    sum2 +=name2[i] - 64;//cout << sum2 <<endl;}
                else if(name2[i]>=97)
                    sum2 += name2[i] - 96;//cout << sum2 <<endl;}
            }
        }
        while(sum1>=10)
        {
            rem = sum1%10;
            sum1 = sum1/10;
            sum1 +=rem;
        }
        while(sum2>=10)
        {
            rem = sum2%10;
            sum2 = sum2/10;
            sum2 +=rem;
        }
        if(sum1>sum2)
        {
            temp = sum1;
            sum1 = sum2;
            sum2 = temp;
        }
       // cout << "final sums are "<<sum1<<" "<<sum2<<endl;
        result = (float(sum1)/float(sum2))*100.00;
        cout <<fixed<<setprecision(2)<<result<< " %\n";
    }
    return 0;
}
