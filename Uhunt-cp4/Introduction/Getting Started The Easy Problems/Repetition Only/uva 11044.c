#include<stdio.h>
int main()
{
    int n,m,t,i,j,k;
    scanf("%d",&t);
    while(t--){
            k=0;
        scanf("%d %d",&n,&m);
        for(i=2;i<n;i=i+3){
            for(j=2;j<m;j=j+3)
                k++;
}
        printf("%d\n",k);
        }
}
