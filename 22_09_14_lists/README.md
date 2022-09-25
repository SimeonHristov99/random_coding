# Tasks

## Task 1

Write a `SortedIntersect()` function which creates and returns a list representing the intersection of two lists that are sorted in increasing order. Ideally, each list should only be traversed once. The resulting list should not contain duplicates.

```js
var first = 1 -> 2 -> 2 -> 3 -> 3 -> 6 -> null
var second = 1 -> 3 -> 4 -> 5 -> -> 6 -> null
sortedIntersect(first, second) === 1 -> 3 -> 6 -> null
```

## Task 2

Write a function that takes a string of parentheses, and determines if the order of the parentheses is valid. The function should return `True` if the string is valid, and `False` if it's invalid.

Examples:

```text
"()"              =>  True
")(()))"          =>  False
"("               =>  False
"(())((()())())"  =>  True
```

Along with opening (`()` and closing `()`) parenthesis, input may contain any valid `ASCII` characters. Furthermore, the input string may be empty and/or not contain any parentheses at all. Do not treat other forms of brackets as parentheses (e.g. `[]`, `{}`, `<>`).

## Task 3

A Narcissistic Number is a positive number which is the sum of its own digits, each raised to the power of the number of digits in a given base.

For example, take 153 (3 digits), which is narcissistic:

```text
1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
```

and 1652 (4 digits), which isn't:

```text
1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938
```

The Challenge:

Your code must return true or false (not 'true' and 'false') depending upon whether the given number is a Narcissistic number in base 10.

## Task 4

You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers from 1 to 5 from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move, you are allowed to apply one of the two following transformations to the matrix:

```text
Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5). 
```

You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.

## Task 5

Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Examples

```text
Input
aaaa
aaaA
Output
0
```

```text
Input
abs
Abz
Output
-1
```

```text
Input
abcdefg
AbCdEfF
Output
1
```

## Task 6

A pangram is a sentence that contains every single letter of the alphabet at least once. For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because it uses the letters A-Z at least once (case is irrelevant). Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.

Example

```text
Input
The quick brown fox jumps over the lazy dog
Output
True
```

## Task 7

Xenia the beginner mathematician is a third year student at elementary school. She is now learning the addition operation. The teacher has written down the sum of multiple numbers. Pupils should calculate the sum. To make the calculation easier, the sum only contains numbers 1, 2 and 3. Still, that isn't enough for Xenia. She is only beginning to count, so she can calculate a sum only if the digits follow in non-decreasing order. For example, she can't calculate sum 1+3+2+1 but she can calculate sums 1+1+2 and 3+3. You've got the sum that was written on the board. Rearrange the digits and print the sum in such a way that Xenia can calculate the sum.

Examples

```text
Input
3+2+1
Output
1+2+3

Input
1+1+3+1+3
Output
1+1+1+3+3

Input
2
Output
2
```
