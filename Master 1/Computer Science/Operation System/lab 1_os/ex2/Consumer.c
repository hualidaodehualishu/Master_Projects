#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <time.h>

struct Change{
    int flag; //0 is A first to read then to write, 1 is B first to read and then to write.
    char content[2048];
};

int main() {
    const int SIZE = 4096;
    const char *name = "OS";
    int shm_fd;
    char *ptr = NULL;
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SIZE);
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    struct Change *share = NULL;
    share = (struct Change*)ptr;
    int run = 1;
    while(run)
    {
        if(share->flag==0) {
            while (share->flag == 1) {
                sleep(1);
            }
            printf("read from producer: %s", share->content);
            for(int i =0; i <strlen(share->content); i++)
            {
                share->content[i]='\0';
            }
            printf("Please write messages to consumer and input '0' to fini:");
            int x = 1;
            while(x!=0)
            {
                fgets(share->content+strlen(share->content),SIZE, stdin);
                scanf("%d",&x);

            }
            share->flag = 1;
            if (strncmp(share->content, "end", 3) == 0) {
                run = 0;
            }
        }
        else
        {
            sleep(1);
        }
    }
    return 0;
}
