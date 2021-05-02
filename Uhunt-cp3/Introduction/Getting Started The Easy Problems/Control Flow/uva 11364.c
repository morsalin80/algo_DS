#include<stdio.h>
int main(){
    int a,b[100],i,t,l,h,p;
    scanf("%d",&t);
    while(t--){
            h=0;p=0;
        scanf("%d",&a);
        for(i=0;i<a;i++){
            scanf("%d",&b[i]);
        }
        l=b[0];
        h=b[0];
        for(i=1;i<a;i++){
            if(l>b[i]){
                l=b[i];
            }
            if(h<b[i]){
                h=b[i];
            }
        }
        p=h-l;
        p=p*2;
        printf("%d\n",p);
    }
    return 0;
}
