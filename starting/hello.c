/* 
To execute this file, you must pass this command:
gcc -g -c hello.c -o hello.o && gcc -g hello.o -o hello.exe -lpthread && ./hello.exe
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> /* For working with threads */
#include <unistd.h> /* For pause and sleep */

static void * thread_fn_callback(void *arg){
    char *input = (char *) arg;
    while (1)
    {
        printf("Input string = %s \n", input); 
        sleep(1);
    }
    
}

void thread1_create()
{
    pthread_t pthread1;
    static char *thread_input = "I am on thread no 1 \n";
    int rc = pthread_create(&pthread1, NULL, thread_fn_callback, (void *)thread_input );
    /* Return 0 on success, otherwise return errorcode , all pthread functions
     return -ve error code on failure, they do not set global 'erreo' variable*/
    if (rc != 0){
        printf("error occured, thread could not be created, erron = %d \n", rc); 
        exit(0);
    }
}

int main()
{
    thread1_create();
    printf("main fin paused\n");
    pause();
    return 0;
}