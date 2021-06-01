#include<iostream>
using namespace std;
int digit(long long n);
int main()
{
    long long n;
    while(true){
    cin>> n;
    if(n==0)break;
    digit(n);
    }
}
int digit(long long n)
{
    int digit_counter=0,counter;
    if(n<10)
    {
         cout << n<<endl;
         return 0;
    }
    else
    {
        while(n!=0)
        {
            counter = n%10;
            digit_counter+=counter;
            n/=10;
        }
        digit(digit_counter);
    }
}
