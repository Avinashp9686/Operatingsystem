#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,req[50],mov=0,cp;
    printf("Enter the current position");
    scanf("%d",&cp);
    printf("Enter thr number of requests");
    scanf("%d",&n);
    printf("enter the request order:");
    for(i=0;i<n;i++)
    {
    scanf("%d",&req[i]);
    }
    mov=mov+abs(cp-req[0]);
   
    printf("%d->%d",cp,req[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(req[i]-req[i-1]);
        printf("-->%d",req[i]);
    }
    printf("\n");
    printf("total head movement=%d\n",mov);

}
// output
// Enter the current position 50
// Enter thr number of requests7
// enter the request order:82
// 170
// 43
// 140
// 21
// 16
// 190
// 50->82-->170-->43-->140-->21-->16-->190
// total head movement=642