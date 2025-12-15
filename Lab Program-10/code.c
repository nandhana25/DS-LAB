#include <stdio.h>
#define MAX 50
int hashTable[MAX];
int m;

void init() {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % m;

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        printf("Collision occurred for key %d at index %d\n", key, index);
        int i = (index + 1) % m;
        while (i != index) {
            if (hashTable[i] == -1) {
                hashTable[i] = key;
                return;
            }
            i = (i + 1) % m;
        }
        printf("Hash table is full\n");
    }
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == -1)
            printf("HT[%d] : empty\n", i);
        else
            printf("HT[%d] : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;
    printf("Enter number of employee records: ");
    scanf("%d", &n);
    printf("Enter hash table size(m): ");
    scanf("%d", &m);
    init();
    printf("Enter %d employee keys(4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
