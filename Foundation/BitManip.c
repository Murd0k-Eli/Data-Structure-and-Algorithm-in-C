#include <stdio.h>
#include <stdbool.h>

// Helper function to print structural binary view of a byte
void displayByte(unsigned char val) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
    }
    printf("\n");
}

int main() {
    // Inputs for standard logical bitwise operations
    unsigned char a = 12; // Binary: 00001100
    unsigned char b = 10; // Binary: 00001010

    // 1. AND / OR / XOR LOGICAL OPERATIONS
    printf("--- 1. AND / OR / XOR ---\n");
    printf("A:      "); displayByte(a);
    printf("B:      "); displayByte(b);
    
    printf("A & B (AND - Both 1s):   "); displayByte(a & b);
    printf("A | B (OR  - Any 1):    "); displayByte(a | b);
    printf("A ^ B (XOR - Mismatches):"); displayByte(a ^ b);
    printf("\n");

    // 2. SHIFTS (LEFT AND RIGHT)
    printf("--- 2. SHIFTS ---\n");
    unsigned char shiftNum = 5; // Binary: 00000101 (Decimal: 5)
    printf("Original:                 "); displayByte(shiftNum);
    
    // Left Shift multipling by 2^n
    unsigned char leftShifted = shiftNum << 2;
    printf("<< 2 (Left Shift/Mult):   "); displayByte(leftShifted);
    printf("New Decimal Value:        %d\n", leftShifted);

    // Right Shift dividing by 2^n
    unsigned char rightShifted = shiftNum >> 1;
    printf(">> 1 (Right Shift/Div):   "); displayByte(rightShifted);
    printf("New Decimal Value:        %d\n\n", rightShifted);

    // 3. MASKING (ISOLATING SPECIFIC DATA)
    printf("--- 3. MASKING ---\n");
    unsigned char statusRegister = 0b10110100; // Mock hardware register status
    unsigned char errorMask = 0b00010000;      // We only care about checking bit index 4
    
    printf("Register:                 "); displayByte(statusRegister);
    printf("Mask:                     "); displayByte(errorMask);
    
    unsigned char isErrorSet = statusRegister & errorMask;
    printf("Result of Mask Isolation: "); displayByte(isErrorSet);
    printf("Is Bit 4 Active?          %s\n\n", isErrorSet ? "YES" : "NO");

    // 4. COUNT SET BITS (Brian Kernighan’s Method)
    printf("--- 4. COUNT SET BITS ---\n");
    unsigned int setBitTarget = 45; // Binary: 00101101 (contains four 1s)
    int count = 0;
    unsigned int temp = setBitTarget;
    
    while (temp > 0) {
        temp &= (temp - 1); // This structural operation strips the lowest active bit instantly
        count++;
    }
    printf("Target decimal value:     %u\n", setBitTarget);
    printf("Number of active 1s found: %d\n\n", count);

    // 5. POWER OF 2 DETERMINATION
    printf("--- 5. POWER OF 2 CHECK ---\n");
    unsigned int x = 32;
    unsigned int y = 38;
    
    // If a number is a power of 2, it has exactly one '1' bit. x & (x - 1) removes it, yielding 0.
    bool checkX = (x > 0) && ((x & (x - 1)) == 0);
    bool checkY = (y > 0) && ((y & (y - 1)) == 0);
    
    printf("Is value %u a power of 2? %s\n", x, checkX ? "TRUE" : "FALSE");
    printf("Is value %u a power of 2? %s\n", y, checkY ? "TRUE" : "FALSE");

    return 0;
}
