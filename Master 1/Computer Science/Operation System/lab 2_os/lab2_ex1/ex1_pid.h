#include <sys/types.h>
#include<stdlib.h>
#include <stdio.h>
#include<time.h>

#define MIN_PID 300
#define MAX_PID 5000

int map[MAX_PID-MIN_PID];
int allocate_map(void);
int allocate_pid(void);
void release_pid(int pid);