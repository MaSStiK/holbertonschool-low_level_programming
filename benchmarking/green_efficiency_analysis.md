# Benchmarking: Green Efficiency Analysis

In this document, I will compare the performance of two functions written in C: the Naive Algorithm and the Single-Pass Algorithm.

The `comparison_algorithms.c` file was compiled using the following command:

```bash
gcc comparison_algorithms.c -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long -o comparison_algorithms
```

## Running `comparison_algorithms`

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

## Measurement Methodology

- Both algorithms processed an array of 50000 elements
- Time was measured using the `clock()` function
- Each algorithm was run 3 times
- Calculation of the average execution time of the algorithm

## Observed Performance Differences

I found that the Naive algorithm runs in an average of `0.603652 seconds`, while the Single-pass algorithm runs in an average of `0.000048 seconds`.  
From this, we can see that the Naive algorithm is 12,500 times slower than the Single-pass algorithm.  
The significant difference in execution time stems from how the algorithms work: the Naive algorithm uses nested loops, while the Single-pass algorithm iterates through the array only once.  
There is also a difference in what the functions return. The Naive algorithm returns `result = 625025000`, while the Single-pass algorithm returns `result = 25000`.

## Relation Between Runtime and Energy Consumption

- Longer execution times can lead to higher energy consumption
- Inefficient algorithms cause the processor to perform more operations
- Optimizing algorithms can reduce energy consumption

> It is important to note that the script does not measure energy consumption, so it is not possible to say exactly how many times less energy the single-pass algorithm uses compared to the naive algorithm.

## Limitations of the Experiment

- Each algorithm was measured only 3 times; to calculate accurate averages, many more measurements are needed.
- Even with the same programs running, the computer’s load could change over time, which could have affected the calculation results.
- Each algorithm returns a different `result`, so the comparison is not entirely accurate, since the Naive algorithm uses an incorrect approach to solving the problem and yields a `result` that is many times higher than expected, unlike the Single-pass algorithm, which worked exactly as intended.

## Practical Engineering Takeaway

- Avoid unnecessary nested loops and recursion
- The choice of algorithm has a significant impact on performance and can affect energy consumption
- It is best to evaluate performance through repeated measurements
