#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// 1. TRAVERSAL
void traverseString(const char *str) {
    printf("--- 1. TRAVERSAL ---\n");
    int index = 0;
    while (str[index] != '\0') {
        printf("Index %d: '%c'\n", index, str[index]);
        index++;
    }
    printf("\n");
}

// 2. PATTERN MATCH
void patternMatch(const char *text, const char *pattern) {
    printf("--- 2. PATTERN MATCH ---\n");
    // strstr returns a pointer to the first occurrence
    char *result = strstr(text, pattern);
    if (result != NULL) {
        // Calculate index by subtracting pointers
        long position = result - text;
        printf("Found '%s' at character index %ld.\n", pattern, position);
    } else {
        printf("'%s' not found.\n", pattern);
    }
    printf("\n");
}

// Helper sorting function for anagram check (Bubble Sort)
void sortString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (tolower(str[i]) > tolower(str[j])) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// 3. ANAGRAM
void checkAnagram(const char *str1, const char *str2) {
    printf("--- 3. ANAGRAM CHECK ---\n");
    
    // Anagrams must be the same length
    if (strlen(str1) != strlen(str2)) {
        printf("Are '%s' and '%s' anagrams? false\n\n", str1, str2);
        return;
    }

    char temp1[100], temp2[100];
    strcpy(temp1, str1);
    strcpy(temp2, str2);

    sortString(temp1);
    sortString(temp2);

    bool isAnagram = (strcmp(temp1, temp2) == 0);
    printf("Are '%s' and '%s' anagrams? %s\n\n", str1, str2, isAnagram ? "true" : "false");
}

// 4. PALINDROME
void checkPalindrome(const char *str) {
    printf("--- 4. PALINDROME CHECK ---\n");
    int left = 0;
    int right = strlen(str) - 1;
    bool isPalindrome = true;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }
    printf("Is '%s' a palindrome? %s\n\n", str, isPalindrome ? "true" : "false");
}

// 5. HASHING (djb2 Algorithm)
unsigned long hashDJB2(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

// 6. SUBSTRINGS
void extractSubstring(const char *str, int start, int length) {
    printf("--- 6. SUBSTRINGS ---\n");
    char sub[100];
    
    // Safely copy a slice of the string
    strncpy(sub, str + start, length);
    sub[length] = '\0'; // Manually terminate the new string
    
    printf("Full string: '%s'\n", str);
    printf("Extracted substring [%d to %d]: '%s'\n", start, start + length, sub);
}

int main() {
    // 1. Traversal Demo
    traverseString("Django");

    // 2. Pattern Match Demo
    patternMatch("Building web applications with Python", "Python");

    // 3. Anagram Demo
    checkAnagram("listen", "silent");

    // 4. Palindrome Demo
    checkPalindrome("radar");

    // 5. Hashing Demo
    printf("--- 5. HASHING ---\n");
    const char *secure_string = "SecretPassword123";
    printf("String: '%s'\n", secure_string);
    printf("DJB2 Hash value: %lu\n\n", hashDJB2(secure_string));

    // 6. Substring Demo (Extract "View" starting from index 5, length 4)
    extractSubstring("ModelViewController", 5, 4);

    return 0;
}
