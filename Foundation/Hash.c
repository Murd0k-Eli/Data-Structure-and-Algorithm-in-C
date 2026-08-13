#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for the linked list (Chaining)
typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

// Hash Map structure
typedef struct {
    Node* buckets[TABLE_SIZE];
} HashMap;

// Hash function: DJB2 algorithm
unsigned int hash(const char* key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}

// Create a new node
Node* create_node(const char* key, int value) {
    Node* new_node = malloc(sizeof(Node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Insert or Update a key-value pair
void insert(HashMap* map, const char* key, int value) {
    unsigned int index = hash(key);
    Node* head = map->buckets[index];
    
    // Check if key already exists, update if found
    while (head != NULL) {
        if (strcmp(head->key, key) == 0) {
            head->value = value;
            return;
        }
        head = head->next;
    }
    
    // Key not found, insert at the front of the bucket (Chaining)
    Node* new_node = create_node(key, value);
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;
}

// Search for a value by key (-1 means not found)
int search(HashMap* map, const char* key) {
    unsigned int index = hash(key);
    Node* head = map->buckets[index];
    
    while (head != NULL) {
        if (strcmp(head->key, key) == 0) {
            return head->value;
        }
        head = head->next;
    }
    return -1; 
}

// Free allocated memory
void free_map(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* head = map->buckets[i];
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            free(temp->key);
            free(temp);
        }
    }
}

int main() {
    // Initialize the hash map to NULL pointers
    HashMap map = { {NULL} };

    // Insert data
    insert(&map, "apple", 5);
    insert(&map, "banana", 12);
    insert(&map, "orange", 9);
    
    // Update data
    insert(&map, "apple", 8); 

    // Search and Print
    printf("apple: %d\n", search(&map, "apple"));
    printf("banana: %d\n", search(&map, "banana"));
    printf("grape: %d\n", search(&map, "grape")); // Does not exist

    // Clean up memory
    free_map(&map);
    return 0;
}
