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

void sortList(){
    struct Node *i,*j;
    for(i=head;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

void display(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    
}
int main(){
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    createList(n);
    sortList();
    display();
    return 0;
}


