#include<stdio.h>
int main()
{
    char ch[100],cl[100];
    int a,b,c,i;
    scanf("%d",&a);
    while(a--){
        scanf("%d",&b);
        b=b*567;
        b=b/9;
        b=b+7492;
        b=b*235;
        b=b/47;
        b=b-498;
        sprintf(ch,"%d",b);
        c=strlen(ch);
        for(i=0;i<c;i++){
            cl[i]=ch[i];
        }
        printf("%c\n",cl[c-2]);
    }
    return 0;
}
