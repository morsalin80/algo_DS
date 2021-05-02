#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g=360,h,i,j,k,l,m;
    while(1){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a==0&&b==0&&c==0&&d==0)
            break;
        e=720;
        if(b>a){
        f=b-a;
        f=f*9;
        f=g-f;}
        else if(a==b)
            f=0;
        else{
            f=(b+40)-a;
            f=f*9;
            f=g-f;
        }
        if(c>b){
        h=(40-c)+b;
        h=h*9;
        h=g-h;
       }
        else if(c==b)
            h=0;
        else{
            h=b-c;
            h=h*9;
            h=g-h;
        }
        if(d>c){
            j=d-c;
            j=j*9;
            j=g-j;
    }
    else if(d==c)
        j=0;
        else{

                j=(d+40)-c;
                j=j*9;
                j=g-j;

        }
        k=e+f+h+j+g;
        printf("%d\n",k);


    }
    return 0;
}
