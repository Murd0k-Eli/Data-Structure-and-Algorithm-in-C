#include <stdio.h>
#include <stdlib.h>

// Dimensions for the 2D matrix example
#define ROWS 3
#define COLS 4

// --- 1. 1D PREFIX SUM & RANGE SUM ---
void run1DPrefixSum() {
    printf("--- 1. 1D PREFIX SUM & RANGE SUM ---\n");
    
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Prefix sum array size is n + 1 to easily handle lower bound queries at index 0
    int pref[n + 1];
    pref[0] = 0;
    
    // Pre-calculate sums: O(N) time
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + arr[i];
    }
    
    // Display original array
    printf("Original Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nPrefix Sum Array: ");
    for (int i = 0; i <= n; i++) printf("%d ", pref[i]);
    printf("\n\n");
    
    // Answer Range Sum Queries in O(1) time
    // Query 1: Sum from index 2 to 5 (4 + 1 + 5 + 9)
    int L1 = 2, R1 = 5;
    int sum1 = pref[R1 + 1] - pref[L1];
    printf("Range Sum Query [%d, %d]: %d\n", L1, R1, sum1);
    
    // Query 2: Sum from index 0 to 3 (3 + 1 + 4 + 1)
    int L2 = 0, R2 = 3;
    int sum2 = pref[R2 + 1] - pref[L2];
    printf("Range Sum Query [%d, %d]: %d\n\n", L2, R2, sum2);
}

// --- 2. 2D PREFIX SUM ---
void run2DPrefixSum() {
    printf("--- 2. 2D PREFIX SUM ---\n");
    
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // 2D Prefix Sum table with an extra row and column of zeros to avoid boundaries
    int pref2D[ROWS + 1][COLS + 1] = {0};
    
    // Pre-calculate 2D prefix sums: O(Row * Col) time
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pref2D[i + 1][j + 1] = matrix[i][j] 
                                 + pref2D[i][j + 1] 
                                 + pref2D[i + 1][j] 
                                 - pref2D[i][j]; // Subtract intersection added twice
        }
    }
    
    // Range query on submatrix: Find sum from Top-Left (1,1) to Bottom-Right (2,2)
    // Elements covered: 6, 7, 10, 11 -> expected sum = 34
    int r1 = 1, c1 = 1;
    int r2 = 2, c2 = 2;
    
    // Formula for 2D range sum query: O(1) time
    int totalSum = pref2D[r2 + 1][c2 + 1] 
                 - pref2D[r1][c2 + 1] 
                 - pref2D[r2 + 1][c1] 
                 + pref2D[r1][c1]; // Add back overlapping region subtracted twice
                 
    printf("Submatrix Sum from (%d,%d) to (%d,%d): %d\n\n", r1, c1, r2, c2, totalSum);
}

// --- 3. SUBARRAY SUM EQUALS K ---
// Counts the number of contiguous subarrays that sum up to exactly K
void runSubarraySumEqualsK() {
    printf("--- 3. SUBARRAY SUM EQUALS K ---\n");
    
    int arr[] = {3, 4, 7, 2, -3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetK = 7;
    
    int currentSum = 0;
    int count = 0;
    
    // For a real-world edge case with large/negative numbers, you would use a Hash Map.
    // For demonstration, we simulate key tracking using a basic shift-offset table to handle negative indexes.
    int offset = 100; 
    int frequencyTable[200] = {0};
    frequencyTable[0 + offset] = 1; // Base case: an empty prefix sum of 0 occurs 1 time
    
    for (int i = 0; i < n; i++) {
        currentSum += arr[i];
        
        // If (currentSum - targetK) has been seen before as a prefix sum, 
        // the segment between that position and this one sums exactly to targetK.
        int complement = currentSum - targetK;
        if (complement + offset >= 0 && complement + offset < 200) {
            count += frequencyTable[complement + offset];
        }
        
        // Record the current prefix sum into our frequency array
        frequencyTable[currentSum + offset]++;
    }
    
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\nTarget Sum (K): %d\n", targetK);
    printf("Total continuous subarrays matching target: %d\n", count);
}

int main() {
    run1DPrefixSum();
    run2DPrefixSum();
    runSubarraySumEqualsK();
    return 0;
}
