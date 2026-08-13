#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MOD 1000000007 // Common large prime modulus used in programming contests

// 1. GREATEST COMMON DIVISOR & LEAST COMMON MULTIPLE
long long getGCD(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long getLCM(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    // Divide first to prevent integer overflow before multiplying
    return (a / getGCD(a, b)) * b;
}

// 2. PRIME IDENTIFICATION (SIEVE OF ERATOSTHENES)
void runSieve(int limit) {
    printf("--- 2. PRIME/SIEVE (Primes up to %d) ---\n", limit);
    
    // Create a boolean array and initialize all entries as true
    bool isPrime[limit + 1];
    memset(isPrime, true, sizeof(isPrime));
    
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
    
    for (int p = 2; p * p <= limit; p++) {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p] == true) {
            // Update all multiples of p greater than or equal to its square
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    // Print all prime numbers found
    printf("Prime numbers: ");
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n\n");
}

// 3. MODULAR ARITHMETIC (Prevention of Integer Overflow)
void demonstrateModularArithmetic(long long a, long long b) {
    printf("--- 3. MODULAR ARITHMETIC (Modulus = %d) ---\n", MOD);
    
    // Property: (a + b) % MOD
    long long sumMod = (a % MOD + b % MOD) % MOD;
    
    // Property: (a * b) % MOD
    long long prodMod = ((a % MOD) * (b % MOD)) % MOD;
    
    printf("Inputs: a = %lld, b = %lld\n", a, b);
    printf("Modular Sum:  %lld\n", sumMod);
    printf("Modular Prod: %lld\n\n", prodMod);
}

// 4. EFFICIENT EXPONENTIATION (BINARY EXPONENTIATION)
// Computes (base^exp) % MOD in O(log exp) time complexity
long long powerMod(long long base, long long exp) {
    long long result = 1;
    base = base % MOD; // Handle if base >= MOD
    
    while (exp > 0) {
        // If exponent is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        // exp must be even now, divide it by 2 and square the base
        exp = exp >> 1; // Bitwise right shift is equivalent to exp / 2
        base = (base * base) % MOD;
    }
    return result;
}

// 5. COMBINATORICS (Permutations nPr & Combinations nCr)
// Uses dynamic programming table to handle factorials implicitly up to n=20 safely
long long getCombination(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; // Pascal's Identity: nCr = nC(n-r)
    
    long long res = 1;
    for (int i = 1; i <= r; i++) {
        res = res * (n - r + i) / i;
    }
    return res;
}

long long getPermutation(int n, int r) {
    if (r > n || r < 0) return 0;
    
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
    }
    return res;
}

// EXTRA 1: FAST PRIMALITY TEST (Trial division up to sqrt(n))
bool isPrimeTrialDivision(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check form 6k +/- 1 up to square root of n
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// EXTRA 2: FIBONACCI WITH LINEAR SPACE/TIME (Iterative DP Approach)
long long getFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    
    long long prev2 = 0, prev1 = 1, current = 0;
    for (int i = 2; i <= n; i++) {
        current = (prev1 + prev2) % MOD;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}


int main() {
    // 1. GCD / LCM Demo
    printf("--- 1. GCD & LCM ---\n");
    long long num1 = 36, num2 = 60;
    printf("Inputs: %lld and %lld\n", num1, num2);
    printf("Greatest Common Divisor (GCD): %lld\n", getGCD(num1, num2));
    printf("Least Common Multiple (LCM):   %lld\n\n", getLCM(num1, num2));

    // 2. Sieve of Eratosthenes Demo
    runSieve(50);

    // 3. Modular Arithmetic Demo
    demonstrateModularArithmetic(987654321987ULL, 123456789123ULL);

    // 4. Binary Exponentiation Demo
    printf("--- 4. BINARY EXPONENTIATION ---\n");
    long long base = 3, exp = 13;
    printf("Computing (%lld^%lld) %% %d...\n", base, exp, MOD);
    printf("Result: %lld\n\n", powerMod(base, exp));

    // 5. Combinatorics Demo
    printf("--- 5. COMBINATORICS ---\n");
    int n = 10, r = 3;
    printf("Pool Size (n) = %d, Selection Size (r) = %d\n", n, r);
    printf("Combinations (nCr - Order doesn't matter): %lld\n", getCombination(n, r));
    printf("Permutations (nPr - Order matters):       %lld\n\n", getPermutation(n, r));

    // Extra Mathematics Demo
    printf("--- BONUS: ADDED MATH CONCEPTS ---\n");
    long long largeNumber = 999999999989ULL; 
    printf("Primality check for %lld: %s\n", largeNumber, isPrimeTrialDivision(largeNumber) ? "PRIME" : "COMPOSITE");
    printf("50th Fibonacci number (scaled mod %d): %lld\n", MOD, getFibonacci(50));

    return 0;
}
