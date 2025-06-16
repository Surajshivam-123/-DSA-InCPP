#include<stdio.h>
#include<string.h>
int top=-1;
void push(int stack[],int key){
    top++;
    stack[top]=key;
}
int pop(int stack[]){
    return stack[top--];
}
int eval_postfix(char s[]){
    int n=strlen(s);
    int stack[n];
    for(int i=0;i<n;i++){
        if(s[i]>=48 && s[i]<=57){
            push(stack,s[i]-48);
        }
        else{
            int value1=pop(stack);
            int  value2=pop(stack);
            if(s[i]=='*')push(stack,value1*value2);
            else if(s[i]=='/')push(stack,value1/value2);
            else if(s[i]=='-')push(stack,value1-value2);
            else if(s[i]=='+')push(stack,value1+value2);
        }
    }
    return pop(stack);
}
int main(){
    char postfix[100]="34+5*";
    int ans=eval_postfix(postfix);
    printf("%d \n",ans);
}