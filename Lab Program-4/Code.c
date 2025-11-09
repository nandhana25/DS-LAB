#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    while (num!=-1) {
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (start == NULL) {
            start = new_node;
        } else {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
        }
        printf("Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;
    if (ptr == NULL) {
        printf("Linked List is empty");
        return start;
    }
    printf("Linked List: ");
    while (ptr != NULL) {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
struct node *insert_beg(struct node *start) {
    struct node *new_node;
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start) {
    struct node *ptr, *new_node;
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (start == NULL) {
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
    return start;
}
struct node *insert_pos(struct node *start) {
    struct node *new_node, *ptr;
    int num, pos, i = 1;
    printf("Enter the data: ");
    scanf("%d", &num);
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    if (pos == 1) {
        new_node->next = start;
        start = new_node;
        return start;
    }
    ptr = start;
    while (i < pos - 1 && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL) {
        printf("Position out of range\n");
        free(new_node);
    } else {
        new_node->next = ptr->next;
        ptr->next = new_node;
        printf("Node inserted at position %d\n", pos);
    }
    return start;
}
int main() {
    struct node *start = NULL;
    int choice;
    do {
        printf("\n\n1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at Any Position\n");
        printf("5. Insert at End\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = create_ll(start);
                printf("\nLinked list created\n");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_pos(start);
                break;
            case 5:
                start = insert_end(start);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 6);
    return 0;
}