#include<stdio.h>
int main()
{
    int a,b,c,i,x,y;
    scanf("%d",&a);
    while(a--){
        scanf("%d",&b);
        int arr[10000],brr[10]={0,0,0,0,0,0,0,0,0};
        for(i=0;i<b;i++){
            arr[i]=i+1;
            if(arr[i]<10){
                brr[i+1]++;
            }
          loop1:
              if(arr[i]>=10){
                if(arr[i]>=10 && arr[i]<100){

                        x=arr[i]/10;
                        brr[x]++;
                        y=arr[i]%10;
                        brr[y]++;
               }
                else{
                    y=arr[i]%10;
                    brr[y]++;
                    arr[i]=arr[i]/10;
                    goto loop1;}}}
        for(i=0;i<10;i++)
        printf("%d ",brr[i]);
        printf("\n");
    }



    return 0;
}
