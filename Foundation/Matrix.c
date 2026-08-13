#include <stdio.h>

#define ROWS 4
#define COLS 4

// 1. Row-Wise and Column-Wise Traversal
void print_row_column_wise(int matrix[ROWS][COLS]) {
    printf("--- Row-Wise Traversal ---\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Column-Wise Traversal ---\n");
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 2. Spiral Order Traversal (Clockwise)
void print_spiral(int matrix[ROWS][COLS]) {
    printf("--- Spiral Order Traversal ---\n");
    int top = 0, bottom = ROWS - 1;
    int left = 0, right = COLS - 1;

    while (top <= bottom && left <= right) {
        // Move left to right across top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Move top to bottom down right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Move right to left across bottom row (if rows remain)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Move bottom to top up left column (if columns remain)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    printf("\n\n");
}

// 3. Diagonal Traversal (Grouping by anti-diagonals where i + j = k)
void print_diagonals(int matrix[ROWS][COLS]) {
    printf("--- Diagonal Traversal (Top-Right to Bottom-Left) ---\n");
    
    // Total number of diagonals in an MxN matrix is (M + N - 1)
    int total_diagonals = ROWS + COLS - 1;

    for (int k = 0; k < total_diagonals; k++) {
        printf("Diagonal %d: ", k);
        
        // Find boundaries for row 'i' based on diagonal index 'k'
        for (int i = 0; i < ROWS; i++) {
            int j = k - i; // Since i + j = k, j is always k - i
            
            // Check if column index 'j' falls within valid matrix bounds
            if (j >= 0 && j < COLS) {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Initialize a sample 4x4 matrix
    int matrix[ROWS][COLS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Input Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Execute traversals
    print_row_column_wise(matrix);
    print_spiral(matrix);
    print_diagonals(matrix);

    return 0;
}
