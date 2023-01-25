#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int number_input(void);
void rand_fill(int *array, unsigned int length);
void quick_sort(int *array, int left , int right);
void binary_sort(int *array,int left,int right,int k);
void swap_1(int a[], int m, int n);
int digit(int a, int k);
void swap_2(int *array, int length);
void Max_heap(int *array, int i,int n);
void BuildHeap(int *array,int size);
void HeapSort(int *array, int size);
void bubble_sort(int *array, int length);
void insertion_sort(int *array, int length);
void selection_sort( int *array,int length);
void descend_order_fill(int *array, int length);
void time_for_random(int *array, int length);
void time_for_descend(int *space, int length);
void time_for_quick_random(int *array, int length);
void time_for_quick_descend(int *space, int length);



int main()
{
    int input_length = number_input();
    int *a = malloc(sizeof(int)*input_length); // allocate random memory
    int *b = malloc(sizeof(int)*input_length); // allocate descend memory
    rand_fill(a, input_length);
    descend_order_fill(b, input_length);
    //time_for_random(a,input_length);
    //time_for_descend(b,input_length);
    time_for_quick_random(a,input_length);
    time_for_quick_descend(b,input_length);
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

void quick_sort(int *array, int left , int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        int  m= array[left];
        while(i < j)
        {
            while(i < j && array[j] >= m)
            {
                j--;
            }
            if (i < j)
            {
                array[i++] = array[j];
            }
            while(i < j && array[i] < m)
            {
                i++;
            }
            if(i < j)
            {
                array[j--] = array[i];
            }
        }
        array[i] = m;
        quick_sort(array,left,i-1);
        quick_sort(array,i+1,right);
    }
}

void binary_sort(int *array,int left,int right,int k)
{
    int i = left;
    int j = right;
    if (left < right && k >= 0 )
    {
        while (i < j) {
            while (digit(array[i], k) == 0 && (i < right)) {
                i = i + 1;
            }
            while (digit(array[j], k) == 1 && (j > left)) {
                j = j - 1;
            }
            if (i < j) {
                swap_1(array, i, j);
            }
        }

        binary_sort(array, left, j , k - 1);
        binary_sort(array, i, right, k - 1);
    }
}

int digit(int a, int k)
{
    if((1<<k) & a)
    {
        return 1 ;
    }
    else
    {
        return 0;
    }
}

void swap_1(int a[],int m,int n)
{
    int temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}

void Max_heap(int *array, int i,int n)
{
    int parent = i;
    int child = 2*i+1;
    while(child<n){
        if(child+1<n &&array[child]<array[child+1]){
            child++;
        }
        if(array[parent]<array[child]){
            swap_1(array,parent,child);
            parent=child;
        }
        child=child*2+1;
    }
}

void BuildHeap(int *array,int size){
    for(int i =size/2-1;i>=0;i--){
        Max_heap(array,i,size);
    }
}

void HeapSort(int *array, int size){
    BuildHeap(array,size);
    for(int i = size-1;i>0;i--){
        swap_1(array,0,i);
        Max_heap(array,0,i);
    }
}

void swap_2(int *array, int input_length)
{
    int temp;
    temp = array[0];
    array[0] = array[input_length-1];
    array[input_length-1] = temp;
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
    for(int i = 0; i < count; i++)
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

void time_for_quick_random(int *array, int length)
{
    long double m;
    int n = length / 10 *2;
    long double elapsed_time;
    clock_t start, end;
    int *a = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        a[i] = array[i];
    }
    int left = 0;
    int right = length - 1;
    start = clock();
    quick_sort(a,left,right) ;
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("quick_sort for random-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("quick_sort for random-fill average time is %LFms\n",m);
    printf("\n");

    int *b = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        b[i] = array[i];
    }


    start = clock();
    binary_sort(b, left, right, 6);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("binary_sort for random-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("binary_sort for random-fill average time is %LFms\n",m);
    printf("\n");

    int *c = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        c[i] = array[i];
    }
    start = clock();
    HeapSort(c,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("heap_sort for random-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("heap_sort for random-fill average time is %LFms\n",m);
    printf("\n");
}

void time_for_quick_descend(int *space, int length)
{
    long double m;
    int n = length / 10 *2;
    long double elapsed_time;
    int *a = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        a[i] = space[i];
    }
    printf("\n");
    clock_t start, end;
    start = clock();
    int left = 0;
    int right = length - 1;
    quick_sort(a,left,right) ;
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("quick_sort for descend-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("quick_sort for descend-fill average time is %LFms\n",m);
    printf("\n");


    int *b = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        b[i] = space[i];
    }
    start = clock();
    binary_sort(b, left, right, 6);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("binary_sort for descend-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("binary_sort for descend-fill average time is %LFms\n",m);
    printf("\n");


    int *c = malloc(sizeof(int)*length);
    for(int i = 0; i < length; i++)
    {
        c[i] = space[i];
    }
    start = clock();
    HeapSort(c,length);
    end = clock();
    elapsed_time = (long double)(end - start) / CLOCKS_PER_SEC;
    elapsed_time *= 10e3;
    printf("heap_sort for descend-fill total time is %LFms\n",elapsed_time);
    m= elapsed_time / n;
    printf("heap_sort for descend-fill average time is %LFms\n",m);
    printf("\n");

}



