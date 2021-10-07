#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> /* For working with threads */
#include <unistd.h> /* For pause and sleep */

void* myturn(void * arg){
    while (1)
    {
        sleep(1);
        printf("My Turn!\n"); 
    }
    return NULL;
}

void yourturn(){
    while (1)
    {
        sleep(2);
        printf("your Turn!\n"); 
    }
}



int main()
{
    pthread_t newthread; 

    pthread_create(&newthread, NULL, myturn, NULL );
    yourturn();
    
    return 0;
}


