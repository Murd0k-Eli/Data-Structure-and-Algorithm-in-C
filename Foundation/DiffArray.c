#include <stdio.h>
#include <stdlib.h>

// Structure to represent the Difference Array
typedef struct {
    int *diff;
    int size;
} DifferenceArray;

/**
 * Initializes the difference array based on the original array.
 * Time Complexity: O(N)
 */
DifferenceArray* create_difference_array(int *original, int size) {
    DifferenceArray *da = (DifferenceArray*)malloc(sizeof(DifferenceArray));
    da->size = size;
    
    // Allocate size + 1 elements to safely handle the right + 1 boundary check
    da->diff = (int*)calloc(size + 1, sizeof(int));
    
    // Populate the initial difference array
    da->diff[0] = original[0];
    for (int i = 1; i < size; i++) {
        da->diff[i] = original[i] - original[i - 1];
    }
    
    return da;
}

/**
 * Efficiently adds 'val' to the range [left, right] (inclusive).
 * Time Complexity: O(1)
 */
void range_update(DifferenceArray *da, int left, int right, int val) {
    da->diff[left] += val;
    da->diff[right + 1] -= val;
}

/**
 * Converts the difference array back to a freshly allocated original array 
 * using Prefix Sum conversion.
 * Time Complexity: O(N)
 */
int* get_final_array(DifferenceArray *da) {
    int *final_array = (int*)malloc(da->size * sizeof(int));
    
    // The first element is identical
    final_array[0] = da->diff[0];
    
    // Compute prefix sum to restore elements
    for (int i = 1; i < da->size; i++) {
        final_array[i] = final_array[i - 1] + da->diff[i];
    }
    
    return final_array;
}

/**
 * Frees allocated memory to prevent memory leaks.
 */
void free_difference_array(DifferenceArray *da) {
    free(da->diff);
    free(da);
}

// Helper function to display arrays
void print_array(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    // 1. Initial Setup
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    print_array(arr, size);
    
    // 2. Initialize Difference Array
    DifferenceArray *da = create_difference_array(arr, size);
    
    // 3. Perform multiple O(1) range updates
    // Update 1: Add 10 to indices 1 to 3
    range_update(da, 1, 3, 10);
    
    // Update 2: Add 5 to indices 2 to 4
    range_update(da, 2, 4, 5);
    
    // Update 3: Subtract 2 from indices 0 to 2
    range_update(da, 0, 2, -2);
    
    // 4. Run Prefix Sum conversion to resolve modifications
    int *result = get_final_array(da);
    
    printf("Array After Updates: ");
    print_array(result, size);
    
    // 5. Clean up heap allocations
    free(result);
    free_difference_array(da);
    
    return 0;
}
