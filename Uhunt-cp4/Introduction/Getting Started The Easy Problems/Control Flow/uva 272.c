#include<string.h>
#include<stdio.h>
int main()
{
    char ch[100];
    int l,i,n=0;
    while(gets(ch)){
        l=strlen(ch);
       for(i=0;i<l;i++){

        if(ch[i]=='"'){
           if(n%2==0)
          printf("``");
            else
                printf("''");
                n++;
        }
       else
        printf("%c",ch[i]);
       }
       printf("\n");
    }

return 0;
}
