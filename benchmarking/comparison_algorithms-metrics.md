# Benchmarking comparison_algorithms.c

Script was compiled with this command:

```bash
gcc comparison_algorithms.c -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long -o comparison_algorithms
```

## Executions of comparison_algorithms

### First execution

> Naive algorithm result: 625025000
> Naive algorithm time: 0.604695 seconds
> Single-pass algorithm result: 25000
> Single-pass algorithm time: 0.000031 seconds

### Second execution

> Naive algorithm result: 625025000
> Naive algorithm time: 0.607844 seconds
> Single-pass algorithm result: 25000
> Single-pass algorithm time: 0.000090 seconds

### Third execution

> Naive algorithm result: 625025000
> Naive algorithm time: 0.598417 seconds
> Single-pass algorithm result: 25000
> Single-pass algorithm time: 0.000024 seconds

## Conclusion

Implementation A is ~12000 times slower than B
