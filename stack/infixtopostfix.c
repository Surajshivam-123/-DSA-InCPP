#include<stdio.h>
#include<string.h>
#include<ctype.h>
int prec(char c){
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='-' || c=='+')return 1;
    else return -1;
}
char stack[100];
int top=-1;
void push(char key){
    stack[++top]=key;
}
char pop(){
    return stack[top--];
}
int isempty(){
    return top==-1;
}
char *convert_Infix_Postfix(char s[]){
    int n=strlen(s);
    //char *ans=(char *)malloc(100*sizeof(char));
    static char ans[100];
    int in=0;
    for(int i=0;i<n;i++){
        if(isalnum(s[i])){
            ans[in++]=s[i];
        }
        else{
            if(s[i]=='(')push(s[i]);
            else if(s[i]==')'){
                while(stack[top]!='('){
                    ans[in++]=pop();
                }
                pop();
            }
            else{
                while(prec(s[i])<=prec(stack[top])){
                    if(prec(s[i])=='^' && prec(stack[top]=='^'))break;//Right associativity of ^
                    ans[in++]=pop();
                }
                push(s[i]);
            }
        }
    }
    while(!isempty()){
        ans[in++]=pop();
    }
    ans[in]='\0';
    return ans;
}
int main(){
    char infix[100]="K+L-M*N+(O^P)*W/U/V*T+Q";
    char *postfix;
    postfix=convert_Infix_Postfix(infix);
    puts(postfix);
}