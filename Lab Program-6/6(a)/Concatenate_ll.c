#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* head2 = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createList(struct Node** head, int n) {
    int val;
    struct Node* temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (*head == NULL) {
            *head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

void concatenate() {
    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("Concatenated list: \n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n1, n2;
    printf("Enter number of nodes in linked list 1: ");
    scanf("%d", &n1);
    printf("Enter the elements: ");
    createList(&head1, n1);
    printf("Enter number of nodes in linked list 2: ");
    scanf("%d", &n2);
    printf("Enter the elements: ");
    createList(&head2, n2);
    concatenate();
    display(head1);
    return 0;
}
