#include <stdio.h>
#include <pthread.h>
int x= 0;
void* procA(void* mess){
    while(1){
        x=x+1;
        if(x==20)
            x=0;
        printf("A | %d\n",x);
    }
}
void* procB(void* mess){
    while(1){
        x=x+1;
        if (x==20)
            x=0;
        printf("B | %d\n",x);
    }
}
int main(){
    pthread_t pA, pB;
    pthread_create(&pA,NULL,procA,NULL);
    pthread_create(&pB,NULL,procB,NULL);
    while(1){}
} 
