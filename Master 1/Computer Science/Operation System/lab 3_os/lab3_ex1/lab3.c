#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_LINE 1024 /* The maximum length command */
#define MAX_ARGS 128 /* The maximum number of arguments */
void judge_at(char *s,int *a,unsigned long b);
void initial_line(char *line);
void initial_args(char *args[]);
void fresh_args(char *args[]);
int line_to_args(char *line,char *args[],unsigned long length,int *judge);


int main(void)
{
    int count_history = -1;
    char line[MAX_LINE];
    int *judge=malloc(sizeof(int)*2);
    char *args[MAX_ARGS]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */
    initial_line(line);
    initial_args(args);
    while (should_run)
    {
        int count_args;
        *judge = 1;
        fresh_args(args);
        printf("lldm>");
        fflush(stdout);
        fflush(stdin);
        if (!fgets(line, 1024, stdin))
            return 0;
        unsigned long a = strlen(line);
        count_args = line_to_args(line, args, a, judge);
        if (!count_args) {
            printf("Please write some commands\n");
            continue;
        }else if (strcmp(line, "exit") == 0) {
            should_run=0;
        } else {
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork the fail");
                exit(0);
            } else if (pid == 0) {
                if (execvp(args[0], args) == -1) {
                    printf("\n Something went wrong :( ...\n");
                    exit(1);
                }
            } else if (pid == 1) {
                if (*judge == 0) {
                    wait(NULL);
                }
            }
        }
    }
    return 0;
}
void judge_at(char *s,int *a,unsigned long b)
{
        *a = 0; //make a mark to the father process
        s[b-1] = '\0'; // change &
        s[b-2] = '\0'; // change ' '
}

void initial_line(char *line)
{
    for(int i = 0; i < MAX_LINE; i++)
    {
        line[i]='\0';
    }
}

void initial_args(char *args[])
{
    for(int i =0; i < MAX_ARGS;i++)
    {
        args[i]=NULL;
    }
}

void fresh_args(char *args[])
{
    while(*args)
    {
        *args++=NULL;
    }
}

int line_to_args(char *line,char *args[],unsigned long length,int *judge)
{
    if(line[length-2]== '&')
    {
        judge_at(line,judge,length);
    }
    char s = ' ';
    int number = 0;
    for(int i = 0; i <= strlen(line);i++) // counter of spaces
    {
        if (line[i] == s)
        {
            number = number + 1;
        }
    }
    if(number == 0 && *judge==1 && strcmp(line,"\n")!=0)
    {
        line[strlen(line)-1]='\0';
        args[0] = line;
        args[1] = NULL;
    }
    else
    {
        args[0] = strtok(line,&s);
        for (int j = 1; j<= number + 1 ;j++)
        {
            args[j] = strtok(NULL," \n");
        }
    }
    if(strcmp(line,"\n") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
