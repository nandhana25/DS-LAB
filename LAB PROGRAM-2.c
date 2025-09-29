#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100

char stack[SIZE];
int top= -1;

void push(char c){
    if(top==SIZE-1){
        printf("Stack Overflow");
        exit(1);
    }
    stack[++top]=c;
}
char pop(){
    if(top==-1){
        return -1;
    }
    return stack[top--];
}
char peek(){
    if(top==-1) return -1;
    return stack[top];
}
int prec(char c){
    if(c=='^') return 3;
    else if(c=='/'||c=='*') return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}
void postfix(char s[]){
    char ans[SIZE];
    int k=0;

    for(int i=0; i<strlen(s);i++){
        char c =s[i];

        if(isalnum(c)){
            ans[k++]=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(top!=-1 && peek()!='('){
                ans[k++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && prec(c)<=prec(peek())){
                ans[k++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1){
        ans[k++]=pop();
    }
    ans[k]='\0';
    printf("The postfix expression is: %s \n",ans);
}
int main(){
    char exp[SIZE];
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    postfix(exp);
    return 0;
}
