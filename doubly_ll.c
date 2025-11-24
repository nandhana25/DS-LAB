#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev, *next;
};
struct Node* head = NULL;
struct Node* createNode(int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->prev = newnode->next = NULL;
    return newnode;
}
void createList(int n) {
    int val;
    struct Node *ptr = NULL, *newnode;
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &val);
        newnode = createNode(val);
        if (head == NULL) {
            head = ptr = newnode;
        } else {
            ptr->next = newnode;
            newnode->prev = ptr;
            ptr = newnode;
        }
    }
}
void insertLeft(int key, int val) {
    struct Node *ptr = head, *newnode;
    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;
    if (ptr == NULL) {
        printf("Key not found\n");
        return;
    }
    newnode = createNode(val);
    newnode->next = ptr;
    newnode->prev = ptr->prev;
    if (ptr->prev != NULL)
        ptr->prev->next = newnode;
    else
        head = newnode;
    ptr->prev = newnode;
    printf("Inserted %d to the left of %d\n", val, key);
}
void deleteByValue(int key) {
    struct Node *ptr = head;
    while (ptr != NULL && ptr->data != key)
        ptr = ptr->next;
    if (ptr == NULL) {
        printf("Value not found\n");
        return;
    }
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    else
        head = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    printf("Deleted %d\n", key);
    free(ptr);
}
void display() {
    struct Node* ptr = head;
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (ptr != NULL) {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }printf("NULL\n");
}
int main() {
    int choice, n, key, val;
    printf("\nMENU\n");
    printf("1. Create Doubly Linked List\n");
    printf("2. Insert left of a node\n");
    printf("3. Delete by value\n");
    printf("4. Display List\n");
    printf("5. Exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter the key value: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertLeft(key, val);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteByValue(key);
                break;
            case 4:
                display();
                break;
            case 5: exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}