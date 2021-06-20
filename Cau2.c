#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int* array;
int d=0;
int n;
sem_t sem, sem1;
void* procA(void* mess){
    while(1){
        sem_wait(&sem);
        if (d!=0)
            printf("TAKE OUT  | Tong = %d\n", --d);
        else
            printf("Khong co phan tu trong mang!\n");
        sem_post(&sem1);
    }
}
void* procB(void* mess){
    while(1){
        sem_wait(&sem1);
        int r;
        srand((int)time(0));
        r = rand();
        array[d] = r;
        printf("PUT IN    | Tong = %d\n",++d);
        sem_post(&sem);
    }
}
int main(){
    printf("Nhap vao so n: ");
    scanf("%d",&n);
    array = (int*) calloc(n,sizeof(int));
    sem_init(&sem,0,0);
    sem_init(&sem1, 0, n);
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &procA, NULL);
    pthread_create(&pB, NULL, &procB, NULL);
    while(1){}
}
