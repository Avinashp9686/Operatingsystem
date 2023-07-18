#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define NUM_PHILOSOPHERS 5
#define NUM_CHOPSTICKS 5

void dine(int n);
pthread_t philosopher[NUM_PHILOSOPHERS];
pthread_mutex_t
chopstick[NUM_CHOPSTICKS];

int main()
{
    int i, status_message;
    void *msg;
    for( i=1;i<NUM_CHOPSTICKS;i++)
    {
        status_message = pthread_mutex_init(&chopstick[i],NULL);
        if(status_message==-1)
        {
            printf("\nMutex initialization failed");
            exit(1);
        }
    }
    for(i=1;i<=NUM_PHILOSOPHERS;i++)
    {
        status_message= pthread_create(&philosopher[i],NULL,(void *)dine,(int *)i);
         if(status_message!=0)
        {
            printf("\nThread creation error");
            exit(1);
        }
    }
    for(i=1;i<=NUM_PHILOSOPHERS;i++)
    {
        status_message= pthread_join(philosopher[i],&msg);
         if(status_message!=0)
        {
            printf("\nThread joine failed");
            exit(1);
        }
    }
    for(i=1;i<=NUM_CHOPSTICKS;i++)
    {
        status_message= pthread_mutex_destroy(&chopstick[i]);
         if(status_message!=0)
        {
            printf("\nMutex destroyed");
            exit(1);
        }
    }
    return 0;
}
void dine(int n){
    printf("\nPhilosopher %d is thinking",n);
    pthread_mutex_lock(&chopstick[n]);
    pthread_mutex_lock(&chopstick[(n+1)%NUM_CHOPSTICKS]);
    printf("\nPhilosopher %d is eating ",n);
    sleep(3);
    pthread_mutex_unlock(&chopstick[(n+1)%NUM_CHOPSTICKS]);
    printf("\n Philosopher %d Finished eating ",n);
}
