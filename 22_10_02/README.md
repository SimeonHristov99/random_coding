# Tasks

## Task 1

Mainak has an array of positive integers. He will do the following operation to this array exactly once:

```text
Pick a subsegment of this array and cyclically rotate it by any amount. 
```

Formally, he can do the following exactly once:

```text
Pick two integers l
```

and r, such that 1≤l≤r≤n, and any positive integer k
.
Repeat this k
times: set al=al+1,al+1=al+2,…,ar−1=ar,ar=al

```text
(all changes happen at the same time).
```

Mainak wants to maximize the value of (an−a1) after exactly one such operation. Determine the maximum value of (an−a1) that he can obtain.

