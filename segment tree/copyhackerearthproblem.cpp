#include<bits/stdc++.h>
using namespace std;
const int maxx=300005;
int segT[maxx];
void build(int arr[],int lo,int hi,int pos){
    if(hi==lo){
        segT[pos]=arr[lo];
    }
    else{
        int mid=(hi+lo)/2;
        build(arr,lo,mid,2*pos+1);
        build(arr,mid+1,hi,2*pos+2);
        segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);
    }
}
int MinQ(int ql,int qr,int nodel,int noder,int pos){
    if(ql>noder || qr<nodel) return numeric_limits<int>::max();
    if(ql<=nodel && qr>=noder){
        return segT[pos];
    }
    int mid=(nodel+noder)/2;
    return min(MinQ(ql,qr,nodel,mid,2*pos+1),MinQ(ql,qr,mid+1,noder,2*pos+2));
}
void update(int *arr,int nodel,int noder,int pos,int x,int val){
    if(nodel==noder and x==nodel){
            arr[x]=val;
            segT[pos]=val;
    }
    //printf("1\n");
    else{
    int mid=(nodel+noder)/2;
    if(nodel<=x && x<=mid) update(arr,nodel,mid,2*pos+1,x,val);
    else update(arr,mid+1,noder,2*pos+2,x,val);
    segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);
    }
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    build(arr,0,n-1,0);
   // printf("%d\n\n",q);
    while(q--){
        //printf("%d\n",q);
        char ch;
        getchar();
        scanf("%c",&ch);
        //printf("%c\n",ch);
        if(ch=='q'){
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r--;
            printf("%d\n",MinQ(l,r,0,n-1,0));
        }
        if(ch=='u'){
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            update(arr,0,n-1,0,x,y);

        }
    }

    return 0;
}
