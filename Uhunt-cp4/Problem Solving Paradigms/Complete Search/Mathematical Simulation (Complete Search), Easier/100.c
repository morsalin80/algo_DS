#include<stdio.h>
int main()
{
    int i,j,k,p,t,n;
    while(scanf("%d %d",&i,&j)!=EOF){

            t=0;
            if(i<j){
    for(n=i;n<=j;n++){
        p=1;
        k=n;

   while(k!=1)

    {
        if(k%2==0)
            k=k/2;
        else
            k=(3*k)+1;
        p++;
    }

    if(p>t)
        t=p;
}
     printf("%d %d %d\n",i,j,t);
    }
    else
        {
            for(n=j;n<=i;n++){
        p=1;
        k=n;

    do{
        if(k%2==0)
            k=k/2;
        else
            k=(3*k)+1;
        p++;
    }
    while(k!=1);
    if(p>t)
        t=p;


    }
     printf("%d %d %d\n",i,j,t);
        }
    }
    return 0;
}
