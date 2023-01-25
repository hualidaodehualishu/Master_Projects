#include "ex2_pid.h"

int main()
{
    allocate_map();
    printf("Starting ... \n");
    int pid = allocate_pid();
    pthread_t thid;
    int number;
    printf("enter a number: ");
    scanf("%d",&number);
    for(int i = 1;i <= number;i++)
    {
        if (pthread_create(&thid, NULL, (void *)thread, NULL) != 0)
        {
            printf("thread creation failed\n");
            exit(1);
        }
        printf("Sleeping for a while ... \n");
        sleep(3);
        printf("Releasing PID!\n");
        release_pid(pid);
    }
    printf("All good, bye!\n");
}

int * thread(void * m)
{
    int pid = allocate_pid();
    unsigned long int thread = pthread_self();
    printf("thread ID = %lu, pid = %d\n", thread,pid);
    return NULL;
}

// Creates and initializes a data structure for representing pids;
// returns -1 if unsuccessful, 1 if successful.
int allocate_map(void)
{
    for(int i = 300;i <= 5000;i++)
    {
        map[i] = 0;
    }
    if(map == NULL)
    {
        printf("Unsuccessful creation\n");
        return -1;
    }
    else
    {
        printf("Created successfully\n");
        return 1;
    }
}
// Allocates and returns a pid;
// returns -1 if unable to allocate a pid (all pids are in use)
int allocate_pid(void)
{
    int pid;
    srand((unsigned)(time(NULL)));
    int upper= MAX_PID-MIN_PID;
    int lower= MIN_PID;
    pid = rand()%upper+lower;
    if(pid == NULL)
    {
        printf("unable to allocate a pid, ");
        return -1;
    }
    else
    {
        return pid;
    }
}
// Releases a pid
void release_pid(int pid)
{
    map[pid]=0;
}
