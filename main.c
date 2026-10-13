#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char postfix[100];
char stack[100];
int j=0;
int top=-1;
int precedence(char ch);
void push(char c);
char pop();
int main()
{
        char str[50];//infix
        printf("enter the infix\n");
        fgets(str,50,stdin);//scaning input
        for(int i=0;str[i]!='\0';i++)
        {
                if((str[i]>=65)&&(str[i]<=90))//alphabet checking
                {
                        postfix[j]=str[i];
                        j++;
                }
                else if(str[i]=='['||str[i]=='{'||str[i]=='(')
                {
                        push(str[i]);
                }
                else if(str[i]==']')
                {
                        while(stack[top]!='[')
                         {
                              postfix[j]=pop();
                                j++;
                         }
                        pop();
                }
                else if(str[i]=='}')
                {
                        while(stack[top]!='{')
                         {
                              postfix[j]=pop();
                                j++;
                         }
                        pop();
                }
                else if(str[i]==')')
                {
                        while(stack[top]!='(')
                         {
                              postfix[j]=pop();
                                j++;
                         }
                        pop();
                }
                else if(str[i]=='*'||str[i]=='/'||str[i]=='+'||str[i]=='-'||str[i]=='^')
                {
                         while(precedence(stack[top])>=precedence(str[i]))
                         {
                                postfix[j]=pop();
                                j++;
                         }
                         push(str[i]);
                }

        }
        while(stack[top]!='\0')
        {
                postfix[j]=pop();
                j++;
        }
        puts(postfix);
}
void push(char c)

{
        top++;
        stack[top]=c;
}
char pop()
{
        char temp;
        temp=stack[top];
        top--;
        return temp;
}