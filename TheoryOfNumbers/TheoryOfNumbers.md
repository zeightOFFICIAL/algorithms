# Borwein's PI
Borwein's algorithm is a spigot algorithm for computing the digits of pi. It was discovered by brothers Jonathan and Peter Borwein in 1984. The algorithm generates pi digit by digit, starting from the leftmost digit and working its way to the right.

The algorithm is based on the observation that pi can be expressed as an infinite sum of rational numbers. The algorithm uses this fact to generate the digits of pi one at a time.

To generate the next digit of pi, the algorithm starts with a guess for the digit, and then verifies the guess by computing the sum of an infinite series. The series is truncated after a certain number of terms, and the resulting sum is compared to the guessed digit. If the sum is greater than or equal to the guessed digit, then the guess is correct, and the algorithm moves on to the next digit. If the sum is less than the guessed digit, then the guess is too high, and the algorithm tries a lower guess.

The algorithm uses a spigot-like approach to compute the series, which allows it to generate the digits of pi one at a time without having to compute all the preceding digits. The algorithm has a linear time complexity, which means that it is very efficient and can compute the digits of pi quickly.

# Chudnovsky's PI
Chudnovsky's algorithm is a fast method for computing the digits of π.

The algorithm is an iterative method that involves calculating the terms of the series in the denominator of the formula until a desired number of digits of π are obtained. The algorithm is particularly efficient because it converges rapidly, with each iteration doubling the number of correct digits.

The algorithm also includes a number of optimization techniques, including the use of multi-precision arithmetic, the fast computation of factorials, and the efficient calculation of powers of -262537412640768000. These optimizations make the algorithm particularly efficient, and it has been used to compute billions of digits of π.

Chudnovsky's algorithm is one of the fastest known methods for computing π, and it is used extensively in modern high-precision calculations of π.

# Gauss-Legendre's PI
Gauss-Legendre's algorithm is a numerical method for approximating the value of pi. It was developed by Carl Friedrich Gauss and later refined by Adrien-Marie Legendre.

The algorithm works by iteratively improving the estimate of pi using a series of arithmetic and geometric operations. At each iteration, the algorithm calculates the arithmetic mean and geometric mean of two values, which are then used to update the estimates of pi.

The Gauss-Legendre algorithm is known for its rapid convergence and high accuracy, and has been used to calculate pi to over 10 billion decimal places. However, it requires significant computational resources and is not typically used in practical applications.

# Eratosthenes' Sieve
Eratosthenes' Sieve is a simple and efficient algorithm for finding all prime numbers up to a given limit. The algorithm works by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the multiples of 2. The algorithm terminates when the square of the next prime exceeds the limit.

ratosthenes' Sieve is an efficient algorithm for finding all prime numbers up to a given limit because it has a time complexity of O(n log log n).

# Sundaram's Sieve
Sundaram's Sieve is another algorithm for finding all prime numbers up to a given limit. It was developed by Indian mathematician S.P. Sundaram in 1934. The algorithm is named after its inventor and is also known as the Sundaram sieve.

Compared to other sieve algorithms like the Sieve of Eratosthenes, Sundaram's Sieve is less efficient in terms of time complexity. However, it has the advantage of requiring less space and memory, making it a useful algorithm for smaller limits.

The basic idea behind Sundaram's Sieve is to generate all numbers up to the limit, and then remove all the numbers of the form i+j+2ij where i, j are natural numbers less than or equal to the limit. The remaining numbers are all prime.

While Sundaram's Sieve is conceptually simple, it requires some additional steps to handle edge cases and ensure correct output. Additionally, the algorithm can become quite slow for larger limits, making it less practical for real-world applications.

In general, algorithms for finding prime numbers become increasingly difficult and complex as the limit increases. This is due to the nature of prime numbers, which become more and more sparse as the numbers get larger. As a result, more complex algorithms are required to efficiently generate and test prime numbers for larger limits.

# Euclidean's GCD
Euclidean's algorithm is a well-known algorithm for finding the greatest common divisor (GCD) of two integers. It is based on the observation that the GCD of two numbers is the same as the GCD of one of the numbers and the remainder when the other number is divided by it. The algorithm starts by dividing the larger number by the smaller number and taking the remainder. If the remainder is zero, the smaller number is the GCD. Otherwise, the algorithm is recursively called with the smaller number and the remainder until the remainder is zero, at which point the GCD is the smaller number. The algorithm is relatively simple to implement and has a time complexity of O(log n), where n is the size of the input.

# Stein's GCD
Stein's algorithm, also known as binary GCD algorithm, is an efficient method to compute the greatest common divisor (GCD) of two integers. It is a variant of Euclid's algorithm, and it is based on the observation that if both a and b are even, then gcd(a,b) = 2*gcd(a/2,b/2), and if only one of them is even, then gcd(a,b) = gcd(a/2,b) or gcd(a,b/2), depending on which one is even.

The algorithm uses only integer arithmetic operations such as division, multiplication, and bit shifting, which makes it faster than Euclid's algorithm in practice. It also avoids the division by a non-zero number, which can be expensive in some hardware architectures.

The time complexity of Stein's algorithm is O(log min(a,b)), which is the same as Euclid's algorithm, but it has a smaller constant factor due to its use of bit shifting and other integer operations. It is especially useful for large integers, where the cost of division can be significant.