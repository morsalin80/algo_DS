#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	while(1){
		cin>>n;
		if(n==0){
			break;
		}
		///just has to check n is a perfect square or not? because all of the perfect square only
		///has odd number of factors. and if number of factors is odd then it will be on.
		ll xx= sqrt(n);
		if(xx*xx==n){
			cout << "yes\n";
		}
		else cout << "no\n";
	}
	return 0;
}