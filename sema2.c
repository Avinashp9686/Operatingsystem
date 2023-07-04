#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main(){
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1){
        printf("\nEnter ur choice:");
        scanf("%d",&n);
        switch(n){
            case 1:if((mutex==1)&&(empty!=0))
            producer();
            else
            printf("Buffer is full!!");
            break;
            case 2:if((mutex==1)&&(full!=0))
            consumer();
            else
            printf("Buffer is empty!!");
            break;
            case 3:
            exit(0);
            break;
        }
    }
}