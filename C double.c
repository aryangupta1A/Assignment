#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double matrix_1[256][256];
double matrix_2[256][256];
double matrix_3[256][256];



int main()
{ 

for (int a=0;a<256;a++)
{
for (int b=0;b<256;b++)
{
matrix_1[a][b]= rand()*0.24;
}
}


for (int c=0;c<256;c++)
{
for (int d=0;d<256;d++)
{
matrix_2[c][d]= rand()*0.37;
}
}


clock_t t;

t = clock();

for (int i=0;i<256;i++)
{
for (int j=0;j<256;j++)
{
double answer=0.0;
for (int k=0;k<256;k++)
{
answer+= matrix_1[i][k]*matrix_2[k][j];
}
matrix_3[i][j]=answer;
}
}
 t = clock() - t;
    double time_taken1 = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken = %f seconds\n", time_taken1);
}



