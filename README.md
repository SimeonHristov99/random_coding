# CodeEveryDay

Daily coding practice. Goal is to upload a solution to a coding problem every day in at least two programming languages.

## Task 1

Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.

Ex: Given the following strings...

    "level", return true
    "algorithm", return false
    "A man, a plan, a canal: Panama.", return true

## Task 2

Implement a function named generateRange(min, max, step), which takes three arguments and generates a range of integers from min to max, with the step. The first integer is the minimum value, the second is the maximum of the range and the third is the step. (min < max)

    generate_range(2, 10, 2) # should return list of [2,4,6,8,10]
    generate_range(1, 10, 3) # should return list of [1,4,7,10]
    generate_range(2, 10, 2) # should return array of [2, 4, 6, 8, 10]
    generate_range(1, 10, 3) # should return array of [1, 4, 7, 10]

## Task 3

Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will return to its original position. The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.

Ex: Given the following strings...

    "LR", return true
    "URURD", return false
    "RUULLDRD", return true

## Task 4

Write a program that will calculate the number of trailing zeros in a factorial of a given number.

Examples

    zeros(6) = 1
        6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

    zeros(12) = 2
        12! = 479001600 --> 2 trailing zeros

You are not meant to calculate the factorial. The number of trailing zeros in *n!* is the number of factors of 5 in *{1,2,....n}*, which is:

![Alt text](./assets/task4_0.png?raw=true "formula")

As an example here's what it'll look like for 127:

![Alt text](./assets/task4_1.png?raw=true "formula")

## Task 5

Create NxN multiplication table, of size provided in parameter.

For example, when given size is 3:

    1 2 3
    2 4 6
    3 6 9

for given example, the return value should be: [[1,2,3],[2,4,6],[3,6,9]]

## Task 6

You get an array of arrays.
If you sort the arrays by their length, you will see, that their length-values are consecutive.
But one array is missing!

Write a method, that returns the length of the missing array.

Example:

    [[1, 2], [4, 5, 1, 1], [1], [5, 6, 7, 8, 9]] --> 3

If the array of arrays is null/nil or empty or an array in the array is null or empty, the method should return 0. There will always be a missing element and its length will be always between the given arrays.
