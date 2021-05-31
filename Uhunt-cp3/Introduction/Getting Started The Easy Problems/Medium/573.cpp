#include<iostream>
using namespace std;
int main()
{
    float climb,climb_per,af_slide;
    int h,u,d,f,day;
    float fatiq;
    while(true)
    {
        cin>>h>>u>>d>>f;
        if(h==0)break;
        day=1;
        climb=0;
        climb_per=u;
        fatiq = (float(f)* float(u)/100) ;
        //cout << fatiq << endl;

       while(1)
        {
            climb+=climb_per;
            if(climb_per>0)
                climb_per-=fatiq;
            //cout << " day = "<< day << " climb per day = "<< climb_per << " climb = "<< climb << endl;
            if(climb>h)
            {
                cout << "success on day "<< day<< endl;break;
            }
            climb = climb - d;
             if(climb<0)
            {
                cout << "failure on day " << day << endl; break;
            }
            day++;
       }

    }
}
