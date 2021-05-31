#include<stdio.h>
int main()
{
    int a,b,c,n,d=1;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&a,&b,&c);
      if(a>b){
        if(a>c){
            if(b>c)
                 printf("Case %d: %d\n",d,b);
            else
                 printf("Case %d: %d\n",d,c);
        }
        else if(c>a)
             printf("Case %d: %d\n",d,a);
      }
      else if(b>a){
        if(b>c){
            if(c>a)
                 printf("Case %d: %d\n",d,c);
            else
                 printf("Case %d: %d\n",d,a);
        }
        else if(c>b)
        {
             printf("Case %d: %d\n",d,b);
        }
      }
     d++;
    }
    return 0;
}
