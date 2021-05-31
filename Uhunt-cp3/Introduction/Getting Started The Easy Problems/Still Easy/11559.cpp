#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int participant,budget,hotels,weeks,minimum,price;
    while(scanf("%d %d %d %d",&participant,&budget,&hotels,&weeks)==4){
    int price_per[hotels];
    minimum = budget*2;
    int beds[hotels][weeks];
    for(int i=0;i<hotels;i++){
        cin>>price_per[i];
        for(int j=0;j<weeks;j++)
            cin>>beds[i][j];
    }
    for(int i=0;i<hotels;i++)
    {
        if((price_per[i]*participant)<=budget)
        {
            for(int j=0;j<weeks;j++)
                if(beds[i][j]>=participant)
            {
                price = price_per[i] * participant;
                if(price<minimum)
                    minimum = price;
                break;
            }
        }
    }
    if(minimum>budget)
        cout << "stay home\n";
    else
        cout << minimum <<endl;
    }
    return 0;
}
