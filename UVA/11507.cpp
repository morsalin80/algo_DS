#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    int length;
    string s1, s2;
    map<string, map<string, string> >b;

    b["+x"]["+y"]= "+y";
    b["+x"]["-y"]= "-y";
    b["+x"]["+z"]= "+z";
    b["+x"]["-z"]= "-z";
    b["-x"]["+y"]= "-y";
    b["-x"]["-y"]= "+y";
    b["-x"]["+z"]= "-z";
    b["-x"]["-z"]= "+z";
    b["+y"]["+y"]= "-x";
    b["+y"]["-y"]= "+x";
    b["+y"]["+z"]= "+y";
    b["+y"]["-z"]= "+y";
    b["-y"]["+y"]= "+x";
    b["-y"]["-y"]= "-x";
    b["-y"]["+z"]= "-y";
    b["-y"]["-z"]= "-y";
    b["+z"]["+z"]= "-x";
    b["+z"]["-z"]= "+x";
    b["+z"]["+y"]= "+z";
    b["+z"]["-y"]= "+z";
    b["-z"]["+y"] = "-z";
    b["-z"]["-y"]= "-z";
    b["-z"]["+z"]= "+x";
    b["-z"]["-z"]= "-x";

    while(cin>>length, length)
    {
        s1= "+x";
        for(int i=0;i<length-1;i++)
        {
            cin>> s2;
            if(s2!="No")
                s1=b[s1][s2];
        }
        cout << s1 << endl;
    }
    return 0;
}

