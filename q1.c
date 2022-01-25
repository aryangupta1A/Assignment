#include <stdio.h>
#include <time.h>
long long int array_recur[100];
long long int array_recur_memo[100];
long long int array_loop[100];
long long int array_loop_memo[100];

//recursive function
long long int fib (long long int n)
{
if (n==0)
return 0;
if (n==1)
return 1;
return fib(n-1)+fib(n-2);
}
//store value in array
void recursion()
{
for (int i=0; i<100; i++)
array_recur[i] = fib(i);
}
//recursive and memiozation
long long int fib_memo(long long int n)
{
if (n==0)
return 0;
if (n==1)
return 1;
if (array_recur_memo[n] != -1)
return array_recur_memo[n];
else
{
array_recur_memo[n]=fib(n-1)+fib(n-2);
return array_recur_memo[n];
}
}
//store value in array
void recursion_memo()
{
for (int i=0; i<100; i++)
array_recur_memo[i]= fib_memo(i);
}

// loop
void loop_memo()
{
long long int answer;
long long int a=0;
long long int b=1;
long long int c;
for (int i=0;i<100;i++)
{
if (i=0)
answer=a;
if (i=1)
answer=b;
else
c=a+b;
a=b;
b=c;
answer=c;
array_loop_memo[i]= answer;
}
}

// loop  
void loop()
{
long long int answer;
long long int a=0;
long long int b=1;
long long int c;
for (int i=0;i<100;i++)
{
for (int j=0;j<i+1;j++)
{
if (j=0)
answer=a;
if (j=1)
answer=b;
else
c=a+b;
a=b;
b=c;
answer=c;
}
array_loop[i]=answer;
}
}



int main()
{
    clock_t t;

    // Initialize to -1
    for (int i = 0; i <100; i++)
    {
        array_recur[i] = -1;
        array_loop[i] = -1;
        array_recur_memo[i] = -1;
        array_loop_memo[i] = -1;
    }

    t = clock();
    recursion();
    t = clock() - t;
    double time_taken1 = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken by Recursion = %f seconds\n", time_taken1);

    t = clock();
    loop();
    t = clock() - t;
    double time_taken2 = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken by Loop = %f seconds\n", time_taken2);

    t = clock();
    recursion_memo();
    t = clock() - t;
    double time_taken3 = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken by Recursion and Memoization = %f seconds\n", time_taken3);

    t = clock();
    loop_memo();
    t = clock() - t;
    double time_taken4 = ((double)t) / CLOCKS_PER_SEC;
    printf("Time taken by Loop and Memoization = %f seconds\n", time_taken4);

    printf("Speedup of program using Recursion = %f\n", (time_taken1 / time_taken1));
    printf("Speedup of program using Loop = %f\n", (time_taken1 / time_taken2));
    printf("Speedup of program using Recursion and Memoization = %f\n", (time_taken1 / time_taken3));
    printf("Speedup of program using Loop and Memoization = %f\n", (time_taken1 / time_taken4));
    return 0;
}


