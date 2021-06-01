#include<bits/stdc++.h>
using namespace std;
vector<int>prefix_function(string s){
	int n=s.size();
	vector<int>pi(n);
	for(int i=1;i<n;i++){
		int j=pi[i-1];       ///length of the best suffix for i−1
		while(j>0 && s[i]!=s[j]){ ///checking whether j matches
			j=pi[j-1];				///reducing j
		}
		if(s[i]==s[j])j++;
		pi[i]=j;
	}
	return pi;
}
int main(){
	string s;
	cin>>s;
	vector<int>pi=prefix_function(s);
	for(int i=0;i<(int)pi.size();i++){
		cout << pi[i] << " ";
	}
	cout << endl;
}