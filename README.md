# CodeEveryDay
Daily coding practice. Goal is to upload a solution to a coding problem every day in at least two programming languages.

# Task 1
Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.

Ex: Given the following strings...

    "level", return true
    "algorithm", return false
    "A man, a plan, a canal: Panama.", return true

# Task 2
Implement a function named generateRange(min, max, step), which takes three arguments and generates a range of integers from min to max, with the step. The first integer is the minimum value, the second is the maximum of the range and the third is the step. (min < max)

    generate_range(2, 10, 2) # should return list of [2,4,6,8,10]
    generate_range(1, 10, 3) # should return list of [1,4,7,10]
    generate_range(2, 10, 2) # should return array of [2, 4, 6, 8, 10]
    generate_range(1, 10, 3) # should return array of [1, 4, 7, 10]

# Task 3
Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will return to its original position. The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.

Ex: Given the following strings...

    "LR", return true
    "URURD", return false
    "RUULLDRD", return true
