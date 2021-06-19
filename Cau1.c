
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
int sell=0;
int product=0;
sem_t sem, sem1;
void* procA(void* message){
    while(1){
        sem_wait(&sem);
        sell++;
        printf("SELLS = %d\n",sell);
        sem_post(&sem1);
    }
}
void* procB(void* message){
    while(1){
        sem_wait(&sem1);
        product++;
        printf("PRODUCTS= %d\n", product);
        sem_post(&sem);
    }
}
int main(){
    sem_init(&sem,0,0);
    sem_init(&sem1, 0,99);
    pthread_t pA, pB;
    pthread_create(&pA,NULL,&procA,NULL);
    pthread_create(&pB, NULL, &procB, NULL);
    while(1){}
}
