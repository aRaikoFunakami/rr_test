#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 4

void *thread_func(void *param)
{
    int *array = param;
    int r;
    struct timespec ts;

    if (timespec_get(&ts, TIME_UTC) == 0) {
        exit(1);
    }
    srandom(ts.tv_nsec ^ ts.tv_sec);
    r = random()%10;  

    if(0 < r && r < SIZE){
        array[r] = 0;
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

    sleep(1);
    for(int i=0; i<SIZE; i++){
        printf("100/array[%d] = %d\n", i, 100/array[i]);
    }


    ret = pthread_join(thread, NULL);
    if (ret != 0){
        exit(1);
    } 

	return 0;
}
