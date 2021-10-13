#include <stdio.h>
#include <pthread.h>
int products = 0;
pthread_mutex_t mutex;
void *procA(void *message)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (products > 0)
            products--;
        printf("SELLS | products = %d\n", products);
        pthread_mutex_unlock(&mutex);
    }
}
void *procB(void *message)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        products++;
        printf("PRODUCTS | products =  %d\n", products);
        pthread_mutex_unlock(&mutex);
    }
}
int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &procA, NULL);
    pthread_create(&pB, NULL, &procB, NULL);
    while (1)
    {
    }
}
