#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *left_child;
    struct node *right_child;
}Node, *pNode;

pNode InitBiTree(int *c,int x,int length);
void CreatBiTree(pNode *p,int length);
int preorder(pNode tree);
int high(pNode tree);
int balance(pNode tree);
int tree_len(int *c, FILE *fp);
int array_tree(char *c,int *c1, FILE *fp);
void print_out(FILE *fp,int balance,int height,int number);
void print_for_special(char *f_name);



int main()
{
    FILE *fp;
    fp = fopen("input_tree.txt","rw");
    if (fp == NULL)
    {
        printf("fail to open file");
        exit(0);
    }
    char *a_in = malloc(sizeof(char)*10);
    int *b_in = malloc(sizeof(int)*20);
    int length = tree_len(b_in,fp);
    b_in [0] = 1;
    fclose(fp);
    fp = fopen("input_tree.txt","rw");
    if (fp == NULL)
    {
        printf("fail to open file");
        exit(0);
    }
    int number =array_tree(a_in,b_in,fp);
    if(number == 0 || number == 1 ) //empty tree or one node tree
    {
        print_for_special("tree_properties.txt");
        exit(0);
    }
    //printf("%d ",number);
    pNode root;
    root = InitBiTree(b_in,0,length);
    //CreatBiTree(p,length);
    int count =preorder(root);
    int t_height = high(root);
    int b_balance = balance(root);
    FILE *fp1;
    fp1 = fopen("tree_properties.txt","w");
    if (fp1 == NULL)
    {
        printf("fail to open file");
        exit(0);
    }
    print_out(fp1,b_balance,t_height,count);
}

pNode InitBiTree(int *c,int x,int length)
{
    if(c[x] == 0 || x>=length)
    {
        return NULL;
    }
    else
    {
        pNode p = (pNode)malloc(sizeof(Node));
        p->data = c[x];
        p->left_child = NULL;
        p->right_child = NULL;
        p->left_child = InitBiTree(c,x*2+1,length);
        p->right_child = InitBiTree(c,x*2+2,length);
        return p;
    }
}
void CreatBiTree(pNode *p, int length)
{
    int i,j;
    for( i = 1; i < length; i++)
    {
        for(j = 0; j < length; j++)
        {
            if(p[j]->left_child == NULL)
            {
                p[j]->left_child = p[i];
                break;
            }
            if(p[j]->right_child == NULL)
            {
                p[j]->right_child = p[i];
                break;
            }
        }
    }
}
int preorder(pNode tree)
{
    int count =0;
    if (tree != NULL) {
        ++count;
        count += preorder(tree->left_child);
        count += preorder(tree->right_child);
    }
    return count;
}
int high(pNode tree)
{
    if(tree == NULL)
    {
        return 0;
    }
        int l_h1 = high(tree->left_child);
        int r_h2 = high(tree->right_child);
        return l_h1 > r_h2 ? l_h1 +1 : r_h2 +1 ;
}

int balance(pNode tree)
{
    if(tree ==NULL)
    {
        return 1;
    }
    int left_child = high(tree->left_child);
    int right_child = high(tree->right_child);
    int ret = left_child - right_child;
    if(ret > 1 || ret < -1)
    {
        return 0;
    }
    else
    {
        return balance(tree->left_child) && balance(tree->right_child);
    }
}

int tree_len(int *c, FILE *fp)
{
    int length = 0;
    char p[1];
    char *c_in = malloc(sizeof(char)*10);
    while(fgets(c_in,10,fp) != NULL)
    {
        length = atoi(&c_in[4]);
    }
    for(int o = 0;o <= length; o++)
    {
        c[o] = 0;
    }
    return length;
}

int array_tree(char *c,int *c1, FILE *fp)
{
    int location;
    while(fgets(c,10,fp) != NULL)
    {
        int value = atoi(&c[4]);
        location = atoi(&c[4])-1 ;
        if(c[4] != '\0')
        {
            c1[location] =value;
        }
    }
    int count = 1 ;
    for(int j = 0; j < location;j++)
    {
        if(c1[j]!=0)
        {
            count++;
        }
    }
    return count;
}

void print_out(FILE *fp1,int balance,int height,int number)
{
    if(pow(2,height)-1 == number)
    {
        fprintf(fp1,"Is the tree complete? Yes\n");
    }
    else
    {
        fprintf(fp1,"Is the tree complete? No\n");
    }
    fprintf(fp1,"What’s the height of the tree? %d\n",height-1);
    if(balance == 1)
    {
        fprintf(fp1,"Is it balanced? Yes\n");
    }
    else
    {
        fprintf(fp1,"Is it balanced? No\n");
    }
    fclose(fp1);
}

void print_for_special(char *f_name)
{
    FILE *fp;
    fp = fopen(f_name,"w");
    fprintf(fp,"Is the tree complete? Yes\n");
    fprintf(fp,"What’s the height of the tree? %d\n",0);
    fprintf(fp,"Is it balanced? Yes\n");
    fclose(fp);
}