#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // For bool type

// Define a structure for a dynamic array
typedef struct {
    int* data;        // Pointer to the actual array in memory
    int size;         // Current number of elements in the array
    int capacity;     // Current capacity of the array
} DynamicArray;

// Function to create a new dynamic array
DynamicArray* create_array(int cap) {
    if (cap <= 0) {
        printf("Error: Capacity must be positive\n");
        return NULL;
    }
    
    DynamicArray* a = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (a == NULL) {
        printf("Error: Memory allocation failed for DynamicArray\n");
        return NULL;
    }
    
    a->data = (int*)malloc(cap * sizeof(int));
    if (a->data == NULL) {
        printf("Error: Memory allocation failed for array data\n");
        free(a);
        return NULL;
    }
    
    a->size = 0;
    a->capacity = cap;
    return a;
}

// Function to double the capacity of the array when full
bool resize(DynamicArray* a) {
    if (a == NULL) return false;
    
    int new_capacity = a->capacity * 2;
    if (new_capacity <= a->capacity) {
        printf("Error: Capacity overflow\n");
        return false;
    }
    
    int* new_data = (int*)realloc(a->data, new_capacity * sizeof(int));
    if (new_data == NULL) {
        printf("Error: Memory reallocation failed\n");
        return false;
    }
    
    a->data = new_data;
    a->capacity = new_capacity;
    printf("Array resized to capacity %d\n", new_capacity);
    return true;
}

// Function to add an element at the end of the array
bool append(DynamicArray* a, int v) {
    if (a == NULL) return false;
    
    if (a->size == a->capacity) {
        if (!resize(a)) {
            return false;
        }
    }
    a->data[a->size++] = v;
    return true;
}

// Function to insert at a specific position
bool insert_at(DynamicArray* a, int pos, int value) {
    if (a == NULL) return false;
    if (pos < 0 || pos > a->size) {
        printf("Error: Position %d out of bounds (size: %d)\n", pos, a->size);
        return false;
    }
    
    if (a->size == a->capacity) {
        if (!resize(a)) {
            return false;
        }
    }

    // Shift elements to the right
    for (int i = a->size; i > pos; i--) {
        a->data[i] = a->data[i - 1];
    }

    a->data[pos] = value;
    a->size++;
    return true;
}

// Function to delete at a specific position
bool delete_at(DynamicArray* a, int pos) {
    if (a == NULL) return false;
    if (pos < 0 || pos >= a->size) {
        printf("Error: Position %d out of bounds (size: %d)\n", pos, a->size);
        return false;
    }

    // Shift elements to the left
    for (int i = pos; i < a->size - 1; i++) {
        a->data[i] = a->data[i + 1];
    }

    a->size--;
    return true;
}

// Function to get the value of an element at a specific index
int get_at(DynamicArray* a, int pos, bool* success) {
    if (a == NULL || pos < 0 || pos >= a->size) {
        if (success) *success = false;
        return 0;  // Return default value
    }
    
    if (success) *success = true;
    return a->data[pos];
}

// Function to update a value of an element at a specific position
bool update_at(DynamicArray* a, int pos, int value) {
    if (a == NULL || pos < 0 || pos >= a->size) {
        printf("Error: Position %d out of bounds (size: %d)\n", pos, a->size);
        return false;
    }
    
    a->data[pos] = value;
    return true;
}

// Function to print all the elements of the array
void print_array(DynamicArray* a) {
    if (a == NULL) {
        printf("Array is NULL\n");
        return;
    }
    
    printf("Array [size=%d, capacity=%d]: ", a->size, a->capacity);
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->data[i]);
    }
    printf("\n");
}

// Function to free the memory allocated for the array
void free_array(DynamicArray* a) {
    if (a != NULL) {
        if (a->data != NULL) {
            free(a->data);
        }
        free(a);
        printf("Array memory freed\n");
    }
}

// Main function to demonstrate the dynamic array
int main() {
    printf("=== Dynamic Array Implementation in C ===\n\n");
    
    // Create array
    DynamicArray* arr = create_array(2);
    if (arr == NULL) {
        printf("Failed to create array. Exiting...\n");
        return 1;
    }
    
    // Append elements
    printf("Appending elements:\n");
    append(arr, 10);
    append(arr, 20);
    append(arr, 30);  // This should trigger resize
    print_array(arr);
    
    // Insert element
    printf("\nInserting 99 at position 1:\n");
    insert_at(arr, 1, 99);
    print_array(arr);
    
    // Get element
    printf("\nGetting element at position 2:\n");
    bool success;
    int value = get_at(arr, 2, &success);
    if (success) {
        printf("Element at index 2: %d\n", value);
    } else {
        printf("Failed to get element\n");
    }
    
    // Update element
    printf("\nUpdating element at position 1 to 55:\n");
    update_at(arr, 1, 55);
    print_array(arr);
    
    // Delete element
    printf("\nDeleting element at position 0:\n");
    delete_at(arr, 0);
    print_array(arr);
    
    // Try invalid operations
    printf("\nTesting error handling:\n");
    printf("Trying to get at invalid index 10: ");
    value = get_at(arr, 10, &success);
    if (!success) printf("Failed as expected\n");
    
    printf("Trying to update at invalid index 10: ");
    if (!update_at(arr, 10, 100)) printf("Failed as expected\n");
    
    printf("Trying to delete at invalid index 10: ");
    if (!delete_at(arr, 10)) printf("Failed as expected\n");
    
    // Free memory
    printf("\n");
    free_array(arr);
    
    return 0;
}