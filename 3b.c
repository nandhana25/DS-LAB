#include <stdio.h>
#define SIZE 5
int front = -1, rear = -1;
int q[SIZE];
void enqueue(int ele) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        q[rear] = ele;
        printf("%d inserted\n", ele);
    }
}
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted\n", q[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        int i;
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", q[i]);
        }
        printf("%d\n", q[i]); 
    }
}

int main() {
    int choice, ele;
    printf("Queue Operations\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Display\n");
    printf("4.Exit\n");

    while(1){  
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the element to be inserted: ");
            scanf("%d",&ele);
            enqueue(ele);
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4:printf("Exiting..\n");
            return 0;
            break;
            default:printf("Invalid choice\n");
        }
    }
}

