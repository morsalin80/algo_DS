#include<bits/stdc++.h>
using namespace std;
const int k=26; //all char
struct vertex{
	int next[k];
	bool leaf=false;
	vertex(){
		fill(begin(next),end(next),-1);
	}
};
vector<vertex>trie(1);
void add_string(string const &s){
	int v=0;
	for(auto ch:s){
		int c=ch-'a';
		if(trie[v].next[c]==-1){
			trie[v].next[c] = trie.size();
			trie.emplace_back();
		}
		v=trie[v].next[c];
	}
	trie[v].leaf=true;
}
int main(){

}