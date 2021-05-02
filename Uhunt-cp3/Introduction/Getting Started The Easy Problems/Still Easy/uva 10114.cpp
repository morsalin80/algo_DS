#include<iostream>
using namespace std;
int main()
{
    int months,records;
    float down_payment,amount,monthly_payment,car_value,loan_payable;

    while(1)
    {
        cin>>months>>down_payment>>amount>>records;
        if(months<0)
            break;
        car_value=amount+down_payment;
        int record_months[records],j;
        float dep[records];
        float depri=0.0;
        loan_payable=amount;
        monthly_payment=float (amount/float (months));
        for(int i=0;i<records;i++)
        {
            cin>>record_months[i];
            cin >> dep[i];
        }
        j=0;
        for(int i = 0;i<=months;i++)
        {
            if(i>0)
            loan_payable-=monthly_payment;
            if(i==record_months[j])
            {
                depri=dep[j];
                j++;
            }
            car_value=car_value - (car_value*depri);
            if(car_value>loan_payable)
            {
                if(i==1)
                    cout << i << " month\n";
                else
                    cout << i << " months\n";
                break;
            }
        }
    }
    return 0;
}
