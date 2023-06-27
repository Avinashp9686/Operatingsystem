#include<stdio.h>
#include<string.h>
int main(){
    int i=0,pno[10],bt[10],n,wt[10],temp=0,j,tt[10];
    float sum,at;
    printf("\n Enter the no of process: ");
    scanf("%d", &n);
    printf("\nEnter the burst time of each process");
    for(i =0;i<n;i++){
        printf("\np%d: ", i);
        scanf("%d", &bt[i]);
        for(i = 0;i<n-1;i++){
            for(j=i;j<n;j++){
                if(bt[i]>bt[j]){
                    temp=bt[i];
                    bt[i]=bt[j];
                    bt[j]=temp;
                    temp = pno[i];
                    pno[i] = pno[j];
                    pno[j]=temp;
                }
            }
        }
        wt[0]=0;
        for(i=1;i<n;i++){
            wt[i]=bt[i-1]+wt[i-1];
            sum=sum+wt[i];
        }
        printf("\nProcess no\t burst time\twaiting time\t turn around time\n");
        for(i=0;i<n;i++){
            tt[i] = bt[i] + wt[i];
            at += tt[i];
            printf("\np%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tt[i]);
        }
        printf("\n\n\tAverage waiting time %f\n\tAverage turn around time %f",sum,at);
    }
}
