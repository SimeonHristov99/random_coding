# CodeEveryDay

## Quick Start

Substitute i with a number.

For C++:

```console
$ cd taski
/taski$ g++ taski.cpp -o taski && ./taski && rm taski
```

For Python:

```console
$ cd taski
/taski$ python3 taski
```

## Task 1

Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.

Ex: Given the following strings...

```text
"level", return true
"algorithm", return false
"A man, a plan, a canal: Panama.", return true
```

## Task 2

Implement a function named generateRange(min, max, step), which takes three arguments and generates a range of integers from min to max, with the step. The first integer is the minimum value, the second is the maximum of the range and the third is the step. (min < max)

```python
generate_range(2, 10, 2) # should return list of [2,4,6,8,10]
generate_range(1, 10, 3) # should return list of [1,4,7,10]
generate_range(2, 10, 2) # should return array of [2, 4, 6, 8, 10]
generate_range(1, 10, 3) # should return array of [1, 4, 7, 10]
```

## Task 3

Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will return to its original position. The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.

Ex: Given the following strings...

```text
"LR", return true
"URURD", return false
"RUULLDRD", return true
```

## Task 4

Write a program that will calculate the number of trailing zeros in a factorial of a given number.

Examples:

```python
zeros(6) = 1  # 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2  # 12! = 479001600 --> 2 trailing zeros
```

You are not meant to calculate the factorial. The number of trailing zeros in *n!* is the number of factors of 5 in *{1,2,....n}*, which is:

![Alt text](./assets/task4_0.png?raw=true "formula")

As an example here's what it'll look like for 127:

![Alt text](./assets/task4_1.png?raw=true "formula")

## Task 5

Create NxN multiplication table, of size provided in parameter.

For example, when given size is 3:

```console
1 2 3
2 4 6
3 6 9
```

for given example, the return value should be: [[1,2,3],[2,4,6],[3,6,9]]

## Task 6

You get an array of arrays.
If you sort the arrays by their length, you will see, that their length-values are consecutive.
But one array is missing!

Write a method, that returns the length of the missing array.

Example:

```python
[[1, 2], [4, 5, 1, 1], [1], [5, 6, 7, 8, 9]] --> 3
```

If the array of arrays is null/nil or empty or an array in the array is null or empty, the method should return 0. There will always be a missing element and its length will be always between the given arrays.

## Task 7

ROT13 is a simple letter substitution cipher that replaces a letter with the letter 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. If there are numbers or special characters included in the string, they should be returned as they are. Only letters from the latin/english alphabet should be shifted (like in the original Rot13 "implementation").

## Task 8

Once upon a time, on a way through the old wild mountainous west,…

… a man was given directions to go from one point to another. The directions were "NORTH", "SOUTH", "WEST", "EAST". Clearly "NORTH" and "SOUTH" are opposite, "WEST" and "EAST" too.

Going to one direction and coming back the opposite direction right away is a needless effort. Since this is the wild west, with dreadfull weather and not much water, it's important to save yourself some energy, otherwise you might die of thirst!
How I crossed a mountainous desert the smart way.

The directions given to the man are, for example, the following (depending on the language):

```python
[ "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" ]
```

Going "NORTH" and immediately "SOUTH" is not reasonable, better stay to the same place! So the task is to give to the man a simplified version of the plan. A better plan in this case is simply:

```python
[ "WEST" ]
```

Other examples:

In `["NORTH", "SOUTH", "EAST", "WEST"]`, the direction `"NORTH" + "SOUTH"` is going north and coming back right away. The path becomes `["EAST", "WEST"]`, now `"EAST"` and `"WEST"` annihilate each other, therefore, the final result is `[]`.

In `["NORTH", "EAST", "WEST", "SOUTH", "WEST", "WEST"]`, `"NORTH"` and `"SOUTH"` are not directly opposite but they become directly opposite after the reduction of `"EAST"` and `"WEST"` so the whole path is reducible to `["WEST", "WEST"]`.

Write a function which will take an array of strings and returns an array of strings with the needless directions removed.

> **Note**: Not all paths can be made simpler. The path ["NORTH", "WEST", "SOUTH", "EAST"] is not reducible. "NORTH" and "WEST", "WEST" and "SOUTH", "SOUTH" and "EAST" are not directly opposite of each other and can't become such. Hence the result path is itself : ["NORTH", "WEST", "SOUTH", "EAST"].

## Task 9

Inspired from real-world Brainf**k, we want to create an interpreter of that language which will support the following instructions:

```text
> => increment the data pointer (to point to the next cell to the right).
< => decrement the data pointer (to point to the next cell to the left).
+ => increment (increase by one, truncate overflow: 255 + 1 = 0) the byte at the data pointer.
- => decrement (decrease by one, treat as unsigned byte: 0 - 1 = 255 ) the byte at the data pointer.
. => output the byte at the data pointer.
, => accept one byte of input, storing its value in the byte at the data pointer.
[ => if the byte at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
] => if the byte at the data pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.
```

The function will take in input...

```text
the program code, a string with the sequence of machine instructions,
the program input, a string, eventually empty, that will be interpreted as an array of bytes using each character's ASCII code and will be consumed by the , instruction
```

... and will return ...

```text
the output of the interpreted code (always as a string), produced by the . instruction.
```

## Task 10

Create a RomanNumerals class that can convert a roman numeral to and from an integer value. It should follow the API demonstrated in the examples below. Multiple roman numeral values will be tested for each helper method.

Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.

Examples:

```C++
RomanNumerals.toRoman(1000); // should return 'M'
RomanNumerals.fromRoman('M'); // should return 1000
```

Help

| Symbol         | Value     |
|--------------|-----------|
| I | 1 |
| IV | 4 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

## Task 11

Write a function which formats a duration, given as a number of seconds, in a human-friendly way.

The function must accept a non-negative integer. If it is zero, it just returns "now". Otherwise, the duration is expressed as a combination of years, days, hours, minutes and seconds.

It is much easier to understand with an example:

```c++
format_duration(62)    // returns "1 minute and 2 seconds"
format_duration(3662)  // returns "1 hour, 1 minute and 2 seconds"
```

## Task 12

Given the string representations of two integers, return the string representation of the sum of those integers.

For example:

```c++
sum_strings("1", "2") // => "3"
sum_strings("111111111111111111111111111111", "111111111111111111111111111111") // => "222222222222222222222222222222"
```

A string representation of an integer will contain no characters besides the ten numerals "0" to "9".

## Task 13

The action of a Caesar cipher is to replace each plaintext letter (plaintext letters are from 'a' to 'z' or from 'A' to 'Z') with a different one a fixed number of places up or down the alphabet.

This program performs a variation of the Caesar shift. The shift increases by 1 for each character (on each iteration).

If the shift is initially 1, the first character of the message to be encoded will be shifted by 1, the second character will be shifted by 2, etc...

The function `movingShift` first codes the entire string and then returns an array of strings containing the coded string in 5 parts (five parts because, to avoid more risks, the coded message will be given to five runners, one piece for each runner).

Parameters of `movingShift`:

```text
param s    : a string to be coded
param shift: an integer giving the initial shift
```

If possible the message will be equally divided by message length between the five runners. If this is not possible, parts 1 to 5 will have subsequently non-increasing lengths, such that parts 1 to 4 are at least as long as when evenly divided, but at most 1 longer. If the last part is the empty string this empty string must be shown in the resulting array.

For example, if the coded message has a length of 17 the five parts will have lengths of 4, 4, 4, 4, 1. The parts 1, 2, 3, 4 are evenly split and the last part of length 1 is shorter. If the length is 16 the parts will be of lengths 4, 4, 4, 4, 0. Parts 1, 2, 3, 4 are evenly split and the fifth runner will stay at home since his part is the empty string. If the length is 11, equal parts would be of length 2.2, hence parts will be of lengths 3, 3, 3, 2, 0.

You will also implement a `demovingShift` function with two parameters:

```text
an array of strings: s (possibly resulting from "movingShift", with 5 strings)
param shift        : an integer giving the initial shift
```

Example:

```text
u = "I should have known that you would have a perfect answer for me!!!"
```

movingShift(u, 1) returns :

```text
v = ["J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"]
```

and demovingShift(v, 1) returns u.

## Task 14

Given a string, return whether or not it uses capitalization correctly. A string correctly uses capitalization if all letters are capitalized, no letters are capitalized, or only the first letter is capitalized.

Ex: Given the following strings...

```text
"USA", return true
"Calvin", return true
"compUter", return false
"coding", return true
```

## Task 15

Given an `n x n` array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

Examples:

```python
array = [[1,2,3],
         [4,5,6],
         [7,8,9]]

snail(array) # => [1,2,3,6,9,8,7,4,5]

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]

snail(array) # => [1,2,3,4,5,6,7,8,9]
```

This image will illustrate things more clearly:

![Alt text](./assets/task15.png?raw=true "snail_sort")

## Task 16

Create all permutations of an input string and remove duplicates, if present. This means, you have to shuffle all letters from the input in all possible orders.

Examples:

```c++
permutations("a");    // => vector<string> {"a"}
permutations("ab");   // => vector<string> {"ab", "ba"}
permutations("aabb"); // => vector<string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"}
```

The order of the permutations doesn't matter.

The permutation tree might be helpful:

![Alt text](./assets/task16.png?raw=true "snail_sort")

## Task 17

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

## Task 18

Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

## Task 19

Write a program that finds the summation of every number from 1 to num. The number will always be a positive integer greater than 0.

Implementation detail:

```text
Do not use a loop.
```

For example:

```text
summation(2) -> 3
1 + 2

summation(8) -> 36
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8
```

## Task 20

Нека е дадена следната дефиниция на израз:
израз = неотрицателно цяло число | f(израз) | g(израз) | m(израз,израз), където:
f(x) = (x * x) mod 100, където mod 100 връща остатъка при деление на 100
g(x) = (x mod 5) ! , т.е. факториелът на остатъка на деленето на х на 5
m(x,y) = min(x,y)
Например, f(m(25, g(14))) е валиден израз от горния тип и се оценява до 76, защото:
f(m(25,g(14))) =
f( min( 25, (14 mod 5)!) =
f (min (25, 24)) =
(24 * 24) mod 100 = 76
Даден е текстови файл с последователен достъп, в който са записани на отделен ред
цяло положително число N и след него пак на отделни редове N на брой изрази от
горния вид. Съдържанието на един примерен файл би бил:
3
f(15)
m(f(15),24)
f(m(25, g(14)))
Да се напише програма, която прочита информацията от един такъв файл и извежда
на стандартния изход на отделен ред всеки израз от файла и съответната му крайна
оценка (без междинни стъпки).
