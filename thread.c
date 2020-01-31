#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];

void* doSomeThing(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0]))
    {
        printf("\n First thread processing\n");
    }
    else
    {
        printf("\n Second thread processing\n");
    }

    for(i=0; i<(0xFFFFFFFF);i++);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    pthread_create(&(tid[0]), NULL, &doSomeThing, NULL);
    pthread_create(&(tid[1]), NULL, &doSomeThing, NULL);

    pthread_join(&(tid[0]), NULL);
    pthread_join(&(tid[1]), NULL); 

    return 0;
}