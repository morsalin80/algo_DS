/// Bismillahir Rahmanir Rahim
/* Author: Mohammad Morsalin (aka white_space)
    Dept of ICE, NSTU
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define ALL(v) v.begin(),v.end()
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
#define Inf INFINITY
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define PI acos(-1)
#define IOS ios::sync_with_stdio(false);
using namespace std;
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
const long long MOD = 1000000007;
template<typename T>inline T Bigmod(T base, T power, T MOD){
    T ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}

bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
struct node{
    bool endmark;
    node* next[26+1];
    node(){
        endmark=false;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
}*root;
void insert(char *str,int len){
    node* curr=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool search(char *str,int len){
    node* curr=root;
    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}
void del(node* cur){
    for(int i=0;i<26;i++){
        if(cur->next[i]);
            del(cur->next[i]);
    }
    delete(cur);
}
int main()
{
    IOS
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>vec;
        for(int i=0;i<n;i++){
            string x;
            cin>>x;
            vec.pb(x);
        }
        sort(ALL(vec));
    }
    return 0;
}
///Alhamdulillah
