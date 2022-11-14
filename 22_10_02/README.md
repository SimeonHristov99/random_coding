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

## Task 2

You are given a positive integer x. Find any such 2 positive integers a and b such that GCD(a,b)+LCM(a,b)=x.

It's guaranteed that the solution always exists. If there are several such pairs (a,b), you can output any of them.

