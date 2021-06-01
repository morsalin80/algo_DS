#include<stdio.h>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++){
        int n;
        double R,theta,r,k,l;
        cin>>R>>n;
        theta=(acos(-1))/n;
        k=sin(theta);
        r=(k*R)/(1+k);
        printf("Case %d: %0.10lf\n",i,r);
    }
    return 0;
