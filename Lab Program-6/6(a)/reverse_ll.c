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
void createList(int n){
    int val;
    struct Node* temp;
    printf("Enter the elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d", &val);
        struct Node* newNode=createNode(val);
        if(head==NULL){
            head=temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
}
void reverseList(){
    struct Node *prev=NULL, *current=head, *nextNode=head;
    while (nextNode!=NULL){
        nextNode=nextNode->next;
        current->next=prev;
        prev=current;
        current=nextNode;
    }
    head=prev;
}
void display(){
    struct Node* temp=head;
    printf("Reversed Linked List: \n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    } 
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    createList(n);
    reverseList();
    display();
    return 0;
}
