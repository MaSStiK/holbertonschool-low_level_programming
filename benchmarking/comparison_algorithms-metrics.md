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

The Naive algorithm average time is 0.603652.
The Single-pass algorithm average time is 0.000048.
The Naive algorithm is ~12500 times slower than the Single-pass algorithm.
