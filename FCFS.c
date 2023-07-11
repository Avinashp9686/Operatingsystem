#include<stdio.h>
int main(){
    char pn[10][10];
    int arr[10], bur[10], star[10], finish[10], tat[10],wt[10],i,n;
    int totwt=0,tottat=0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter the process Name,Arrival Time &burst time:");
        scanf("%s%d%d",pn[i],&arr[i],&bur[i]);
    }
    for(i=0;i<n;i++){
        if(i==0){
            star[i] = arr[i];
            wt[i] = star[i]- arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];
        }
        else{
            star[i]=finish[i-1];
            wt[i]=star[i]-arr[i];
            finish[i]=star[i]+bur[i];
            tat[i]=finish[i]-arr[i];
        }
    }
    printf("\nPName\tArrtime\tBurtime\tstart\tTAT Finish");
    for(i=0;i<n;i++){
        printf("\n%s\t%6d\t%6d\t%6d\t%6d\t%6d",pn[i],arr[i],bur[i],star[i],tat[i],finish[i]);
        totwt +=wt[i];
        tottat +=tat[i];
    }
    printf("\nAverage Waiting time: %f", (float)totwt/n);
    printf("\nAverage Turn Around Time: %f\n",(float)tottat/n);
}

/*
Enter the number of processes: 3
Enter the process Name,Arrival Time &burst time:a 2 3
Enter the process Name,Arrival Time &burst time:b 5 6
Enter the process Name,Arrival Time &burst time:c 6 7

PName   Arrtime Burtime start   TAT Finish
a            2       3       2       3       5
b            5       6       5       6      11
c            6       7      11      12      18
Average Waiting time: 1.666667
Average Turn Around Time: 7.000000
*/