# Benchmarking: Green Efficiency Analysis

In this document, I will analyze the performance of three C programs: baseline_loop, comparison_algorithms, and instrumentation_lab.

## Compilation and Running `baseline_loop`

### Compilation Command

```bash
gcc baseline_loop.c -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long -o baseline_loop
```

### Performance Summary

- Run 1: `Execution time: 0.080963 seconds`
- Run 2: `Execution time: 0.075908 seconds`
- Run 3: `Execution time: 0.081705 seconds`

## Compilation and Running `comparison_algorithms`

### Compilation Command

```bash
gcc comparison_algorithms.c -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long -o comparison_algorithms
```

### Run 1

> Naive algorithm result: 625025000  
> Naive algorithm time: 0.604695 seconds  
> Single-pass algorithm result: 25000  
> Single-pass algorithm time: 0.000031 seconds

### Run 2

> Naive algorithm result: 625025000  
> Naive algorithm time: 0.607844 seconds  
> Single-pass algorithm result: 25000  
> Single-pass algorithm time: 0.000090 seconds

### Run 3

> Naive algorithm result: 625025000  
> Naive algorithm time: 0.598417 seconds  
> Single-pass algorithm result: 25000  
> Single-pass algorithm time: 0.000024 seconds

## Compilation and Running `instrumentation_lab`

### Compilation Command

```bash
gcc instrumentation_lab.c -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long -o instrumentation_lab
```

### Run 1

> TOTAL seconds: 0.000353
> BUILD_DATA seconds: 0.000149
> PROCESS seconds: 0.000131
> REDUCE seconds: 0.000072

### Run 2

> TOTAL seconds: 0.000312
> BUILD_DATA seconds: 0.000126
> PROCESS seconds: 0.000127
> REDUCE seconds: 0.000058

### Run 3

> TOTAL seconds: 0.000377
> BUILD_DATA seconds: 0.000161
> PROCESS seconds: 0.000140
> REDUCE seconds: 0.000074

## Measurement Methodology

- All programs use the `clock()` function to measure time
- All programs were run three times
- **baseline_loop** performs 100 million iterations to measure execution time
- **comparison_algorithms** demonstrates the behavior of two different algorithms that count even numbers in the first 50,000
- **instrumentation_lab** displays the total program execution time, dataset creation time, data processing time, and checksum calculation time

## Observed Performance Differences

**baseline_loop**  
In three runs, the program's execution time varied, even though it performed the same task.

**comparison_algorithms**  
I found that the **Naive algorithm** runs in an average of `0.603652 seconds`, while the **Single-pass algorithm** runs in an average of `0.000048 seconds`.  
From this, we can see that the **Naive algorithm** is **12,500** times slower than the **Single-pass algorithm**.  
The significant difference in execution time stems from how the algorithms work: the **Naive algorithm** uses nested loops, while the **Single-pass algorithm** iterates through the array only once.  
There is also a difference in what the functions return. The **Naive algorithm** returns `result: 625025000`, while the **Single-pass algorithm** returns `result: 25000`.

**instrumentation_lab**  
The `BUILD_DATA` and `PROCESS` phases took the longest, while the `REDUCE` phase took the least time.  
I'd also like to note that in the first and third runs, the `BUILD_DATA` phase took longer than the `PROCESS` phase, but in the second run, `PROCESS` took longer.

## Relation Between Runtime and Energy Consumption

- Longer execution times can lead to higher energy consumption
- Inefficient algorithms cause the processor to perform more operations
- Optimizing algorithms can reduce energy consumption

> It is important to note that none of the three programs measure energy consumption directly, so it is not possible to determine their actual energy consumption based on the recorded execution times.

## Limitations of the Experiment

- Each program was measured only 3 times; to calculate accurate averages, many more measurements are needed
- Even with the same programs running, the computer’s load could change over time, which could have affected the calculation results
- In **comparison_algorithms** each algorithm returns a different `result`, so the comparison is not entirely accurate, since the **Naive algorithm** uses an incorrect approach to solving the problem and yields a `result` that is many times higher than expected, unlike the **Single-pass algorithm**, which worked exactly as intended

## Practical Engineering Takeaway

- Avoid unnecessary nested loops and recursion
- The choice of algorithm has a significant impact on performance and can affect energy consumption
- It is best to evaluate performance through repeated measurements
