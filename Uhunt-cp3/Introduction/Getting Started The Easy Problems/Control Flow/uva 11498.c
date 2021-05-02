#include<stdio.h>
int main()
{
    int t,k,m,n,x,y;
    while(1){
        scanf("%d",&t);
        if(t==0)break;
        scanf("%d %d",&m,&n);
        while(t--){
            scanf("%d %d",&x,&y);
            if(x==m||y==n)
                printf("divisa\n");
            else if(x>m && y>n)
                printf("NE\n");
            else if(x<m && y>n)
                printf("NO\n");
            else if(x<m && y<n)
                printf("SO\n");
            else if(x>m && y<n)
                printf("SE\n");
        }

    }
    return 0;
}
