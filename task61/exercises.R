# Task 1: Convert a string to a number.
s_to_i <- function(x) {
  # Var 1
  # result <- as.integer(x)
  
  # Var 2
  result <- as.numeric(x)
  
  return (result)
}
s_to_i("123")

# Task 2: Return the opposite of a number.
opposite <- function(number) {
  return (-number)
}
opposite(s_to_i("123"))

# Task 3: Your task is to make two
# functions ( max and min, or maximum and minimum, etc.,
# depending on the language ) that
# receive a list of integers as input, and
# return the largest and lowest number in that list, respectively.
minimum <- function(vec) {
  min(vec)
}
maximum <- function(vec) {
  max(vec)
}
minimum(c(-52, 56, 30, 29, -54, 0, -110))
maximum(c(-52, 56, 30, 29, -54, 0, -110))

# Task 4: Write a function which converts the input string to uppercase.
makeUpperCase <- function(s) {
  toupper(s)
}
makeUpperCase("hello")

# Task 5: Write a function to convert a name (two words with one
# space in between them) into initials. The output should be two capital letters
# with a dot separating them.
abbrev_name <- function(name) {
  splits <- unlist(strsplit(name, ' '))
  firstname_letter1 <- toupper(substr(splits[1], 1, 1))
  lastname_letter1 <- toupper(substr(splits[2], 1, 1))
  paste(firstname_letter1, lastname_letter1, sep = ".")
}
abbrev_name("Sam Harris")
abbrev_name("Patrick Feenan")
abbrev_name("Evan cole")

# Task 6: Implement a function which convert the given boolean value
# into its string representation.
boolean_to_string <- as.character
boolean_to_string(TRUE)

# Task 7: The solution would work like the following:
# get_even_numbers(c(2,4,5,6)) => c(2,4,6)
get_even_numbers <- function(vec) {
  vec[vec %% 2 == 0]
}
get_even_numbers(c(2, 4, 5, 6))

# Task 8: Your goal is to implement a difference function, which
# subtracts one list from another and returns the result. It should remove
# all values from list a, which are present in list b keeping
# their order.
array_diff = function(a, b) {
  # one-linear:
  a[!(a %in% b)]
  
  # result <- vector()
  # for (x in a) {
  #   if(!(x %in% b)){
  #     result <- append(result, x)
  #   }
  # }
  # return(as.numeric(result))
}
array_diff(c(1, 2), 1) # 2
array_diff(c(1, 2, 2), 1) # c(2, 2)
array_diff(c(1, 2, 2), 2) # 1
array_diff(c(1, 2, 2), numeric()) # c(1, 2, 2)
array_diff(numeric(), c(1, 2)) # numeric()
array_diff(c(1, 2, 3), c(1, 2)) # 3

# Task 9: You are provided with consecutive elements of an Arithmetic
# Progression. There is however one hitch: exactly one term from the original
# series is missing from the set of numbers which have been given to you.
# The rest of the given series is the same as the original AP.
# Find the missing term.
find_missing <- function(sequence) {
  len_seq <- length(sequence)
  (sequence[1] + sequence[len_seq]) * (len_seq + 1) / 2 - sum(sequence)
}
find_missing(c(1, 3, 5, 9, 11)) == 7
find_missing(c(1, 3, 4, 5, 6, 7, 8, 9)) == 2

# Task 10: Define a function that calculates the factorial of a number.
fact_rec <- function(x) {
  if (x < 0) {
    stop("x was negative")
  }
  if (x == 0) {
    return(1)
  }
  return(x * fact_rec(x - 1))
}
# fact_rec(-5)
fact_rec(5)

fact_iter <- function(x) {
  helper <- function(x, result) {
    if (x == 0) {
      return(result)
    }
    return(helper(x - 1, result * x))
  }
  if (x < 0) {
    stop("x was negative")
  }
  return(helper(x, 1))
}
fact_iter(5)

# Task 11: Given an integer n, return a string array answer (1-indexed) where:
# answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
# answer[i] == "Fizz" if i is divisible by 3.
# answer[i] == "Buzz" if i is divisible by 5.
# answer[i] == i (as a string) if none of the above conditions are true.
fizz_buzz <- function(n) {
  result <- vector()
  
  for (i in 1:n) {
    if (i %% 3 == 0 && i %% 5 == 0) {
      result <- append(result, "FizzBuzz")
    }
    else if (i %% 3 == 0) {
      result <- append(result, "Fizz")
    }
    else if (i %% 5 == 0) {
      result <- append(result, "Buzz")
    }
    else {
      result <- append(result, as.character(i))
    }
  }
  
  return(result)
}
fizz_buzz(3)
fizz_buzz(5)
fizz_buzz(15)

# Task 12: Count the number of divisors of a positive integer n.
divisors <- function(n) {
  length(Filter(function(x){n %% x == 0}, 1:n))
}
divisors(30)

# Task 13: Given a positive number n > 1 find the prime
# factor decomposition of n. The result
# will be a string with the following form : "(p1**n1)(p2**n2)...(pk**nk)"
# with the p(i) in increasing order and n(i) empty if n(i) is 1.
primeFactors <- function(n) {
  d <- 2
  cnt <- 0
  result <- ""
  while(n > 1) {
    if(n %% d == 0) {
      n <- n %/% d
      cnt <- cnt + 1
    }
    else {
      if(cnt == 1) {
        result <- paste0(result, "(", d, ")")
      }
      else if (cnt > 1) {
        result <- paste0(result, "(", d, "**", cnt, ")")
      }
      cnt <- 0
      d <- d + 1
    }
  }
  result <- paste0(result, "(", d, ")")
  return(result)
}
primeFactors(86240)
primeFactors(7919)

