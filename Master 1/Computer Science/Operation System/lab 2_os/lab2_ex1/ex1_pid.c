#include "ex1_pid.h"

int main()
{
    allocate_map();
    int pid_1 = allocate_pid();
    release_pid(pid_1);
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
        printf("unable to allocate a pid");
        return -1;
    }
    else
    {
        printf("%d\n",pid);
        return pid;
    }
}
// Releases a pid
void release_pid(int pid)
{
    map[pid]=0;
}