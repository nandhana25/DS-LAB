#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int n) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top = top + 1;
        stack[top] = n;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from the stack\n", stack[top]);
        top = top - 1;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    printf("OPTIONS\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}