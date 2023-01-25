#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int number_input(void);
void rand_fill(int *array, unsigned int length);
void bubble_sort(int *array, int length);
void insertion_sort(int *array, int length);
void selection_sort( int *array,int length);
void descend_order_fill(int *array, int length);
void time_for_random(int *array, int length);
void time_for_descend(int *space, int length);


int main()
{
    int input_length = number_input();
    int *a = malloc(sizeof(int)*input_length); // allocate random memory
    int *b = malloc(sizeof(int)*input_length); // allocate descend memory
    rand_fill(a, input_length);
    descend_order_fill(b, input_length);
    time_for_random(a,input_length);
    time_for_descend(b,input_length);
    free(a);
    free(b);
    return 0;
}

int number_input(void)
{
    int number;
    printf("please input a number: ");
    scanf("%d",&number);
    return number;

}

void rand_fill(int *array,unsigned int length) //random number function
 {
    time_t time_seed;
    srand ((unsigned) time(&time_seed));

    for (int j = 0; j < length ; j++)
    {
        array[j] = rand() % 100;
    }
}
void bubble_sort(int *array, int length)
{
   int *b = malloc(sizeof(int)*length);
   for(int i = 0; i < length; i++)
   {
       b[i] = array[i];
   }

    for(int i = 0; i < length-1; i++ )
    {
        for(int j = 0;j < length-1; j++)
        {
            if (b[j] > b[j + 1])
            {
                int t = b[j];
                b[j] = b[j + 1];
                b[j + 1] = t;
            }
        }
    }
    free(b);
}

void insertion_sort(int *array, int length)
{
    int *c = malloc(sizeof(int)*length);
    for (int i = 0; i < length; i++)
    {
        c[i] = array[i];
    }

    for(int i = 0 ; i < length; i++)
    {
       if (c[i] < c[i - 1])
       {
           int j = i - 1;
           while (j >= 0 && c[j] > c[j + 1])
           {
               int temp = c[j];
               c[j] = c[j + 1];
               c[j + 1] = temp;
               j--;
           }
       }

    }
    free(c);
}

void selection_sort( int *array,int length)
{
    int *d = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        d[i] = array[i];
    }
    for(int i = 0; i < length - 1; i++)
    {
        for(int j =i + 1; j < length; j++)
        {
            if(d[i] > d[j])
            {
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    free(d);
}

void descend_order_fill(int *array, int length)
{
    int count = length;
    for(int i = 0; i < count  ; i++)
    {
       array[i] = count - i - 1 ;
    }
}

void time_for_random(int *array,int length)
{
    long double m;
    int n = length / 10 *2;
    long double elapsed_time;
    clock_t start, end;
    start = clock();
    bubble_sort(array,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("bubble_sort for random-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("bubble_sort for random-fill average time is %LFms\n",m);
    printf("\n");

    start = clock();
    insertion_sort(array,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("insertion_sort for random-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("insertion_sort for random-fill average time is %LFms\n",m);
    printf("\n");

    start = clock();
    selection_sort(array,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("selection_sort for random-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("selection_sort for random-fill average time is %LFms\n",m);
    printf("\n");

}

void time_for_descend(int *space,int length)
{
    long double m;
    int n = length / 10 *2;
    long double elapsed_time;
    clock_t start, end;
    start = clock();
    bubble_sort(space,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("bubble_sort for descend-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("bubble_sort for descend-fill average time is %LFms\n",m);
    printf("\n");

    start = clock();
    insertion_sort(space,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("insertion_sort for descend-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("insertion_sort for descend-fill average time is %LFms\n",m);
    printf("\n");

    start = clock();
    selection_sort(space,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("selection_sort for descend-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("selection_sort for descend-fill average time is %LFms\n",m);
    printf("\n");
}




