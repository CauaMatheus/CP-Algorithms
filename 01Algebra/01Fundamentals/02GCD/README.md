# [Click here to go to the original page](https://cp-algorithms.com/algebra/euclid-algorithm.html)

# Self explanation
Basically, in university, we learned a new way to calculate the GCD of two numbers.
This new way, does not need a list of primes or a list of divisors, it just needs the two numbers.

The algorithm is based on the fact that the GCD of two numbers is the same as the GCD of the remainder of the division of the two numbers and the smallest number.

So gcd(10, 15) can be solved by:
```
10 = 15 * 0 + 10
15 = 10 * 1 + 5
10 = 5 * 2 + 0

Here when we get 0 as remainder, we know that the GCD is the smallest number, so 5 is the GCD of 10 and 15.
```

So you can recursively apply this algorithm until you get 0 as remainder.  

$$\gcd(a, b) = \begin{cases}a,&\text{if }b = 0 \\ \gcd(b, a \bmod b),&\text{otherwise.}\end{cases}$$

Below you can see the implementation of the algorithms.

# Algorithms
## [Recursive GCD](/01Algebra/01Fundamentals/02GCD/algorithms/recursive.cpp)
A recursive implementation of gcd.

## [Iterative GCD](/01Algebra/01Fundamentals/02GCD/algorithms/iterative.cpp)
An iterative implementation of gcd.

## [GCD by C++ STL](https://en.cppreference.com/w/cpp/numeric/gcd)
GCD is already implemented in C++17 STL.

# Problems
## [Sum of gcd of Tuples (Easy)](https://vjudge.net/problem/AtCoder-abc162_c) | [(Click here tho see the solution  ✅)](/01Algebra/01Fundamentals/02GCD/problems/01SumOfGcdOfTuplesEasy.cpp)
Given an integer $K$, find the sum of $\gcd(a, b, c)$ for all $1 \leq a, b, c \leq K$.
