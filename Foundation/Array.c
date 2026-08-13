#include <stdio.h>
//Function to print the contents of an array
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);             
    }
        printf("\n");
}

int main() {
// Initialize an array with a capacity of 100 and 5 elements
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;
    int target, pos, i, j, temp;
    // 1. Traversal
    printf("Traversal: ");
    display(arr, size);
    // 2. Insertion (Insert 25 at index 2)
    pos = 2;
    int value = 25;
    for (i = size; i > pos; i--) {
        arr[i] = arr[i - 1]; // Shift elements to the right
    }
    arr[pos] = value; // Place the new value
    size++; // Increase array size tracking
    printf("After Insertion: ");
    display(arr, size);
    // 3. Deletion (Remove element at index 3)
    pos = 3;
    for (i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    size--; // Decrease array size tracking
    printf("After Deletion: ");
    display(arr, size);
    // 4. Searching (Linear Search for 40)
    target = 40;
    int found = -1;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            found = i;
            break; // Stop loop once found
        }
    }
    printf("Search %d: Found at index %d\n", target, found);
}