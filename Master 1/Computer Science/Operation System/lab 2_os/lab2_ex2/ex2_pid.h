#include <sys/types.h>
#include<stdlib.h>
#include <stdio.h>
#include<time.h>
#include<pthread.h>
#include<unistd.h>


#define MIN_PID 300
#define MAX_PID 5000
int * thread(void * m);

int map[MAX_PID-MIN_PID];
int allocate_map(void);
int allocate_pid(void);
void release_pid(int pid);