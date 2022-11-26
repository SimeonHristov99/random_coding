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

## Task 3

Little Susie listens to fairy tales before bed every day. Today's fairy tale was about wood cutters and the little girl immediately started imagining the choppers cutting wood. She imagined the situation that is described below.

There are n trees located along the road at points with coordinates x1, x2, ..., xn. Each tree has its height hi. Woodcutters can cut down a tree and fell it to the left or to the right. After that it occupies one of the segments [xi - hi, xi] or [xi;xi + hi]. The tree that is not cut down occupies a single point with coordinate xi. Woodcutters can fell a tree if the segment to be occupied by the fallen tree doesn't contain any occupied point. The woodcutters want to process as many trees as possible, so Susie wonders, what is the maximum number of trees to fell. 

## Task 4

Usually when you buy something, you're asked whether your credit card number, phone number or answer to your most secret question is still correct. However, since someone could look over your shoulder, you don't want that shown on your screen. Instead, we mask it.

Your task is to write a function *maskify*, which changes all but the last four characters into '#'.
Examples

"4556364607935616" --> "############5616"
     "64607935616" -->      "#######5616"
               "1" -->                "1"
                "" -->                 ""

// "What was the name of your first pet?"

"Skippy" --> "##ippy"

"Nananananananananananananananana Batman!"
-->
"####################################man!"

## Task 5


## Task 6


## Task 7

