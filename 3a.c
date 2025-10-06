#include <stdio.h>
#define SIZE 5
int front=-1,rear=-1;
int q[SIZE];
void enqueue(int ele){
    if(rear==SIZE-1)
        printf("Queue Overflow\n");
    else{
        rear=rear+1;
        q[rear]=ele;
        printf("%d is inserted\n",ele);
        if(front==-1)
            front=front+1;       
    }
}
void dequeue(){
    int del;
    if(front==-1){
        printf("Queue underflow\n");
    }
    else{
        del=q[front];
        printf("%d is deleted\n",del);
        if(front==rear){
            front=-1;
            rear=-1;
        }else
            front+=1;
    }
}
void display(){
    if(front==-1)
        printf("Queue is empty\n");
    else{
        printf("The queue is: ");
        for (int i=front;i<=rear;i++){
            printf("%d ",q[i]);
        }printf("\n");
    }
}

int main() {
    int ele,choice;
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
    return 0;
}
