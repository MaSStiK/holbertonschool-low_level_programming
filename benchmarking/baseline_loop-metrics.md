# benchmarking

## Code
I am provided with: baseline_loop.c
```c
#include <stdio.h>
#include <time.h>

#define ITERATION_COUNT 100000000UL

int main(void)
{
    volatile unsigned long long result;
    clock_t start;
    clock_t end;
    double elapsed;
    unsigned long i;

    result = 0;

    start = clock();

    for (i = 0; i < ITERATION_COUNT; i++)
        result += (unsigned long long)(i % 3);

    end = clock();

    elapsed = (double)(end - start) / (double)CLOCKS_PER_SEC;

    printf("Iterations: %lu\n", (unsigned long)ITERATION_COUNT);
    printf("Execution time: %.6f seconds\n", elapsed);

    return 0;
}
```

## Executions
1. Execution time: 0.074874 seconds
2. Execution time: 0.078965 seconds
3. Execution time: 0.076969 seconds