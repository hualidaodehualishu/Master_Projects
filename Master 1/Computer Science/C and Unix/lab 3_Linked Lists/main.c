#include <stdio.h>
#include<stdlib.h>
#include<string.h>


struct element
{
    char data [20];
    struct element *next;
    int count;
};

struct element *link = NULL;
struct element* createList(FILE *fp)
{
    struct element *current = NULL;
    struct element *head = NULL;
    struct element *tail = NULL;
    current = (struct element*)malloc(sizeof(struct element));
    current ->next = NULL;
    while( fscanf(fp,"%s",current->data) != EOF)
    {
        if (head == NULL)
        {
            head = current;
            tail = current;
        }
        else
        {
            tail ->next = current;
            tail = current;
        }
        current = (struct element*)malloc(sizeof(struct element));
    }
    fclose(fp);
    return head;

}

void print_List(struct element *link)
{
    if (link == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        printf("list is : \n");
    }

    struct element *s1;
    struct element *s2;
    struct element *s3;
    s1 = link;
    s2 = link ->next;
    while(s1  != NULL)
    {
        s3 = s1;
        s2 = s3 ->next;
        s1 ->count = 1;
        while(s3->next!= NULL)
        {
            if(!strcmp(s1->data,s2->data))
            {
                s1->count ++;
                s3 ->next = s2 ->next; //delete1
                s2 = s2 ->next; //delete1
            }
            else
            {
                s3 = s3->next;
                s2 = s2->next;
                //s3 = s2;
            }
        }
        s1 = s1 ->next;

    }
    while(link != NULL)
    {
        printf("%s %d\n",link->data,link ->count);
        link = link ->next;
    }

}




int main()
{

    FILE *fp;
    fp = fopen("input_text.txt","rw");
    if (fp == NULL)
    {
        printf("fail to open file");
        exit(0);
    }
    else
    {
        link = createList(fp);
    }
    print_List(link);
    FILE *fq;
    fq = fopen("output_text.txt","w");
    if (fq == NULL)
    {
        printf("fail to open file");
        exit(0);
    }
    else
    {
        while(link!=NULL)
        {
            fprintf(fq,"%s %d\n",link ->data,link ->count);
            link = link->next;
        }
        fclose(fq);
    }

}