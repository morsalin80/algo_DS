#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f0(n) for(int i=0;i<n;i++)
#define ms(x) memset(x,0,sizeof(x))
#define ins insert
#define IOS ios::sync_with_stdio(false);
using namespace std;
int main()
{
    //IOS
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,m;
        cin>>n>>m;
        list<int>q;
        cout<< "Case "<< tc <<":\n";
        while(m--)
        {
            string s;
            cin>>s;
            if(s=="pushLeft")
            {
                int x;
                cin>>x;
                if(q.size()==n) {cout << "The queue is full\n"; continue;}
                q.push_front(x);
                cout << "Pushed in left: "<<x<<endl;
            }
            else if(s=="pushRight"){
                int x;
                cin>>x;
                if(q.size()==n) {cout << "The queue is full\n"; continue;}
                q.push_back(x);
                cout << "Pushed in right: "<<x << endl;
            }
            else if(s=="popLeft")
            {
                if(q.empty())
                {
                    cout << "The queue is empty\n"; continue;
                }
                int x = q.front();
                q.pop_front();
                cout << "Popped from left: " << x<< endl;
            }
            else if(s=="popRight"){
                if(q.empty())
                {
                    cout << "The queue is empty\n"; continue;
                }
                int x = q.back();
                q.pop_back();
                cout << "Popped from right: " << x<< endl;
            }
        }
    }
    return 0;
}
