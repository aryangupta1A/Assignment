#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrix_1[128][128];
int matrix_2[128][128];
int matrix_3[128][128];



int main()
{ 

for (int a=0;a<128;a++)
{
for (int b=0;b<128;b++)
{
matrix_1[a][b]= rand();
}
}


for (int c=0;c<128;c++)
{
for (int d=0;d<128;d++)
{
matrix_2[c][d]= rand();
}
}

clock_t t;

t = clock();
for (int i=0;i<128;i++)
{
for (int j=0;j<128;j++)
{
int answer=0;
for (int k=0;k<128;k++)
{
matrix_3[i][j]+= matrix_1[i][k]*matrix_2[k][j];
}
}
}
 
    t = clock() - t;
    double time_taken1 = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken = %f seconds\n", time_taken1);
}

