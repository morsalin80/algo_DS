#include<bits/stdc++.h>
using namespace std;
vector<int>prefix_function(string s){
	int n = (int)s.size();
	vector<int>pi(n);
	for(int i=0;i<n;i++){
		for(int k=0;k<=i;k++){
			if(s.substr(0,k)==s.substr(i-k+1,k))
				pi[i]=k;
		}
	}
	return pi;
}
int main(){
	string s;
	cin>>s;
	vector<int>pi=prefix_function(s);
	for(int i=0;i<(int)pi.size();i++)cout << pi[i] << " ";
		cout << endl;
}