# Tasks

## Monday

Given the triangle of consecutive odd numbers:

                   1
               3     5
           7     9    11
       13    15    17    19
    21    23    25    27    29
    ...

Calculate the sum of the numbers in the `n`th row of this triangle (starting at index 1) e.g.: (Input --> Output)

    1 -->  1
    2 --> 3 + 5 = 8

## Tuesday

Implement Length() to count the number of nodes in a linked list.

    Length(null) => 0
    Length(1 -> 2 -> 3 -> null) => 3

Implement Count() to count the occurrences of an integer in a linked list.

    Count(null, 1) => 0
    Count(1 -> 2 -> 3 -> nullptr, 1) => 1
    Count(1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 2 -> 3 -> 3 -> nullptr, 2) => 4

The `push()/Push()` and `buildOneTwoThree()/BuildOneTwoThree()` functions do not need to be redefined.

## Wednesday

You will have a list of rationals in the form

    lst = [ [numer_1, denom_1] , ... , [numer_n, denom_n] ]

where all numbers are positive integers. You have to produce their sum N / D in an irreducible form: this means that N and D have only 1 as a common divisor.

Example:

    [ [1, 2], [1, 3], [1, 4] ]  -->  [13, 12]
    1/2  +  1/3  +  1/4     =      13/12

