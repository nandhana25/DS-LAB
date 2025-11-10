#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void createList(){
    int data;
    printf("Enter the elements to enterin the list(-1 to stop): ");
    while(1){
        scanf("%d",&data);
        if(data==-1) break;
        struct Node* newNode= createNode(data);
        if(head==NULL){
            head=newNode;
        }else{
            struct Node* temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newNode;
        }
    }
    printf("Linked List created\n");
}

void deleteBeginning() {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head=head->next;
    printf("Deleted node from beginning\n");
    free(temp);
}

void deleteEnd() {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp=head;
    struct Node* prev=NULL;
    if (head->next==NULL) {
        printf("Deleted node from end\n", head->data);
        free(head);
        head=NULL;
        return;
    }
    while (temp->next!=NULL) {
        prev=temp;
        temp=temp->next;
    }
    printf("Deleted node with value from end\n", temp->data);
    prev->next=NULL;
    free(temp);
}

void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        printf("Deleted node with value %d\n", value);
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value not found in list\n", value);
        return;
    }
    prev->next = temp->next;
    printf("Deleted node with value %d\n", value);
    free(temp);
}
    
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
    printf("%d -> ", temp->data);
    temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Create Linked List\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete by Value\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            createList();
            break;
            case 2:
            deleteBeginning();
            break;
            case 3:
            deleteEnd();
            break;
            case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;
            case 5:
            display();
            break;
            case 6:
            exit(0);
            default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
