# [Click here to go to the original page](https://cp-algorithms.com/algebra/binary-exp.html)

# Self explanation
First of all, we need to understand the `naive` solution. That is the easiest way to solve the problem.  
If you want to exponentiate a number `x` to the power of `y`, you can just multiply `x` by itself `y` times.
```cpp
long long pow(long long x, long long y) {
  long long acc = 1;
  while(y--) {
    acc *= x;
  }
  return acc;
}
```
This solution is `O(y)`, which is not good enough for large values of `y`.  

Ok,well... But how can we improve this solution?  
We can use the fact that $x^ y = (x^ 2)^ \dfrac{y}{2}$ for recursively calculate the result. So, if we have $2^8$, we can calculate like this $(2^ 2)^ 4$
If we think $2^2 = w$, so $2^8 = w^4$ that is the same as $(w^2)^2$, so we can calculate $2^8$ in 3 steps instead of 8 doing $(((2^2)^2)^2)$.

We just have to think a little bit more, because if `y` is odd, it will have a remainder of 1 when divided by 2, so we have to multiply the result by the actual `x` again.

For example: $2^7$, using the same logic will be $(2^2)^3$ that is not the correct result, so we have to first multiply by the actual `x` value, so we have $2 * (2^2)^3$.


The important thing, is that binary exponentiation works with any problem that can be solve by applying a function `f(x)` successively. And it's possible to know `h` that is `h(x) = f(f(x))` having the same property.  
Example $a^8$ can be calculated by the function `f(x) = x*a` called 8 times like this
$f(f(f(f(f(f(f(f(1))))))))$, but we know that $f(f(x)) = h(x)$ and $h(h(x)) = k(x)$ and with that we can divide the problem in sub-problems to solve in log(n).  
<a href="#12---la---3722-jewel-eating-monsters--click-here-tho-see-the-solution--">
  Problem 12 use this idea to solve
</a>

Below you can see the implementation of the algorithms.

# Algorithms
## [Recursive Binary Exponentiation](/01Algebra/01-BinaryExponentiation/algos/recursive.cpp)
A recursive implementation of binary exponentiation.

## [Iterative Binary Exponentiation](/01Algebra/01-BinaryExponentiation/algos/iterative.cpp)
An iterative implementation of binary exponentiation.

## [Modular Binary Exponentiation](/01Algebra/01-BinaryExponentiation/algos/modular.cpp)
An implementation of binary exponentiation with modular arithmetic.

# Problems
## [01 - UVa 1230 - MODEX](https://vjudge.net/problem/UVA-1230) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/01Modex.cpp)
Answer `c` queries of given three integers `x`, `y`, and `n`, compute `x^y mod n`.  

## [02 - UVa 374 - Big Mod](https://vjudge.net/problem/UVA-374) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/02BigMod.cpp)
Answer unknown number of queries until EOF of given three integers `B`, `P`, and `M`, compute `B^P mod M`.  

## [03 - UVa 11029 - Leading and Trailing](https://vjudge.net/problem/UVA-11029) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/03LeadingAndTrailing.cpp)
Answer `t` queries of given two integers `n` and `k`, compute the first 3 digits and the last 3 digits of `n^k`. **HUGE NUMBERS LIKE 2147483647^10000000**  

## [04 - Codeforces 630I - Parking Lot](https://vjudge.net/problem/CodeForces-630I)
TODO

## [05 - Leetcode - Count good numbers](https://leetcode.com/problems/count-good-numbers/) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/05CountGoodNumbers.cpp)
Good numbers is numbers that in even positions have the digits (0, 2, 4, 6 or 8) and in odd positions has (2, 3, 5 or 7).
Given an integer `n`, return the number of good numbers of length `n`. Since the answer may be very large, return it modulo `10^9 + 7`.  

## [06 - CodeChef - Chef and Riffles](https://vjudge.net/problem/CodeChef-RIFFLES) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/06ChefAndRiffles.cpp)
Asnwer `t` queries of given an initial array `f` that is an iota from 1 to `n`, apply `k` times the permutations `g` = (f(1), f(3), f(5), ... , f(n-1), f(2), f(4), f(6), ... , f(n))  

## [07 - Codeforces - Decoding Genome](https://vjudge.net/problem/CodeForces-222E)
TODO

## [08 - Codeforces - Neural Network Country](https://vjudge.net/problem/CodeForces-852B)
TODO

## [09 - Codeforces - Magic Gems](https://vjudge.net/problem/CodeForces-1117D)
TODO

## [10 - SPOJ - The last digit](https://vjudge.net/problem/SPOJ-LASTDIG) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/10TheLastDigit.cpp)
Answer `t` queries of given two integers `a` and `b`, compute the last digit of `a^b`.  

## [11 - SPOJ - Magic of the locker](https://vjudge.net/problem/SPOJ-LOCKER) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/11MagicOfTheLocker.cpp)
Answer `t` queries of given a integer `k`, find the largest product of a combination of integers having sum equal to k.

## [12 - LA - 3722 Jewel-eating Monsters](https://vjudge.net/problem/UVALive-3722) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/12JewelEatingMonsters.cpp)
### !!! Usage of Matrix Exponentiation !!!

Answer unknown queries of the problem:  
Someone has `x` coins, and every night toss a coin, so now he has `x-1` coins.
But in the morning he will have `alpha*(x-1)` coins.  
After `n` nights, he will leave the cave and buy the maximum quantity of
diamonds that cost `c` each.  
How much coins he will have at the end?  

## [13 - SPOJ - Just add it](https://vjudge.net/problem/SPOJ-ZSUM) | [(Click here tho see the solution  ✅)](/01Algebra/01-BinaryExponentiation/problems/13JustAddIt.cpp)
Answer unknown queries of given `n` and `k`, what is the result of
$(Z_n + Z_{n-1} - 2*Z_{n-2})\%10000007$, where:
$$Z_n = S_n + P_n$$
$$S_n = 1^k + 2^k + 3^k + ... + n^k$$
$$P_n = 1^1 + 2^2 + 3^3 + ... + n^n$$

## [14 - Codeforces - Stairs and Lines](https://vjudge.net/problem/CodeForces-498E)
TODO