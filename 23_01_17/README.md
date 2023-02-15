# Tasks

## Task 1

There is a bus moving in the city which takes and drops some people at each bus stop.

You are provided with a list (or array) of integer pairs. Elements of each pair represent the number of people that get on the bus (the first item) and the number of people that get off the bus (the second item) at a bus stop.

Your task is to return the number of people who are still on the bus after the last bus stop (after the last array). Even though it is the last bus stop, the bus might not be empty and some people might still be inside the bus, they are probably sleeping there :D

Take a look on the test cases.

Please keep in mind that the test cases ensure that the number of people in the bus is always >= 0. So the returned integer can't be negative.

The second value in the first pair in the array is 0, since the bus is empty in the first bus stop.

# Task 2

Write a function to return `True` when its argument is a list that has the same nesting structures and same corresponding length of nested arrays as the first list.

# Task 3

We shall encode an integer in the following way:

Given positive integer n > 1. We convert it to an array as follows:

    First, create an array of all n's prime factors sorted ascending
    Then, for every element: if it is equal to 2, return an empty array. Otherwise replace the number with an array with its index in the prime numbers sequence, and then convert this number.

For example, lets convert number 46 to array. Firstly, convert it to array of its prime factors:

[2, 23]

Number 23 is 9th prime, so replace 2 with empty array and 23 with [9]. Array now becomes:

[[], [9]]

Prime factors of 9 are 3 and 3, so:

[[], [3, 3]]

Do the same for both 3:

[[], [[2], [2]]]

And finally:

[[], [[[]], [[]]]]

Now, to encode it, we simply replace each open bracket with 1 and each closing bracket with 0, then remove all ending zeros and drop one 1 from the end. This is our binary number. Using the above example:

[ ] [ [ [ ] ] [ [ ] ] ]

| | | | | | | | | | | |
| | | | | | | | | | | |
V V V V V V V V V V V V

1 0 1 1 1 0 0 1 1 0 0 0

Now simply drop the last three zeros and the last 1. The number becomes 10111001 which is 185 in decimal. That is the expected output. Notice that in array to binary conversion brackets of the main array are not included.

Your task is to write a pair of functions, encode and decode. encode should encode a number according the above procedure, and decode will return the original number given an encoded number.

# Task 4

Who remembers back to their time in the schoolyard, when girls would take a flower and tear its petals, saying each of the following phrases each time a petal was torn:

    "I love you"
    "a little"
    "a lot"
    "passionately"
    "madly"
    "not at all"

If there are more than 6 petals, you start over with "I love you" for 7 petals, "a little" for 8 petals and so on.

When the last petal was torn there were cries of excitement, dreams, surging thoughts and emotions.

Your goal is to determine which phrase the girls would say at the last petal for a flower of a given number of petals. The number of petals is always greater than 0.
