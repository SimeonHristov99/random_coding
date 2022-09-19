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

