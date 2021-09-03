#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 4

void *thread_func(void *param)
{
    int *array = param;
    for(int i=0; i < SIZE; i++){
        array[i] = 0;
        sleep(1);
    }
}

int main(int argc, char **argv)
{
    pthread_t thread;
    int ret = 0;
    int array[SIZE] = {10, 20, 30, 40};

    ret = pthread_create(&thread, NULL, thread_func, array);
    if (ret != 0){
        exit(1);
    }

    sleep(2);
    for(int i=0; i<SIZE; i++){
        printf("100/array[%d] = %d\n", i, 100/array[i]);
    }


    ret = pthread_join(thread, NULL);
    if (ret != 0){
        exit(1);
    } 

	return 0;
}