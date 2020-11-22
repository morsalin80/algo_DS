    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int test;
        cin>>test;
        for(int i=1;i<=test;i++)
        {
            bool printtest = false;
            stack<string>backw,forw;
            string s,current="http://www.lightoj.com/";
            while(cin>>s)
            {
                if(!printtest){ cout <<"Case " << i << ":\n"; printtest = true;}
                if(s=="QUIT") break;
                if(s=="VISIT"){string url;backw.push(current); cin>>url;current=url;
                    while(!forw.empty()) forw.pop();
                }
                else if(s=="BACK"){ if(!backw.empty())
                    {
                        //string c = backw.top();//cout << c<<endl;
                        forw.push(current);
                        current=backw.top();
                        backw.pop();
                    }
                    else
                        {cout << "Ignored\n"; continue;}
                }
               else if(s=="FORWARD"){
                    if(!forw.empty())
                    {
                        backw.push(current);
                        current=forw.top();
                        forw.pop();

                        }
                    else{
                        cout << "Ignored\n";
                        continue;
                    }
                }
                cout<<current<<endl;

            }
        }
        return 0;
    }


