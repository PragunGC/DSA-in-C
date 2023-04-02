#include<stdio.h>
#include<string.h>
#include<process.h>
#include<math.h>
char postfix[25];
char stack[20];
int top=-1;
int T=-1;
int prefix(char ch);
void push1(char c);
float pop1();
float exp_eval(char s_fix[], float data[]);
void topost(char in_fix[]);
void push(char s);
char pop();
int main()
{
int j=0;
char in_fix[25];
float number[20],res;
puts (" Enter an infix expressions: ");
gets(in_fix);
puts ("\n Postfix Expression: ");
topost(in_fix);
while(postfix[j]!='\0')
{
    if(isalpha(postfix[j]))
    {
        fflush(stdin);
        printf ("\n Enter number for %c: ",postfix[j]);
        scanf("%f",&number[j]);
    }
    j++;
}
res=exp_eval(postfix,number);
printf("The res of %s =%f", postfix,res);
getch();

}
void push (char s)
{
if (T>=19)
{
    puts ("Stack overflow ");
    exit(0);
}
else
{
    T=T+1;
    stack[T]=s;
}
}
char pop ()
{
    char num;
    if (T==-1)
    {
        puts (" Stack is Empty ");
        getch();
        return(0);
    }
    else
    {
        num=stack[T];
        T--;
    }
    return (num);
}
int prefix (char ch)
{
    if(ch=='/')
        return (5);
    else if (ch=='*')
        return (4);
    else if (ch=='+')
        return (3);
    else
        return (2);
}
void topost (char in_fix[])
{
int len;
static int index=0,pos=0;
char s,t;
len=strlen(in_fix);
push('#');
while(index<len)
{
    s=in_fix[index];
    switch(s)
    {
    case '(':
           push(s);
           break;
    case ')':
        t=pop();
        while (t!='(')
        {
            postfix[pos]=t;
            pos++;
            t=pop();
        }
        break;
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        while (prefix(stack[T])>prefix(s))
        {
            t=pop();
            postfix[pos]=t;
            pos++;
        }
        push(s);
        break;
    default:
        postfix[pos++]=s;
        break;
    }
index++;
}
while(T>0)
{
    t=pop();
    postfix[pos++]=t;
}
postfix[pos++]='\0';
puts(postfix);
return;
}
float exp_eval( char s_fix[], float data[])
{
int j=0;
float opA,opB,fs;
char ch;
while (s_fix[j]!='\0')
{
    ch=s_fix[j];
    if (isalpha(s_fix[j]))
    {
        push(data[j]);
    }
    else
    {
        opB=pop();
        opA=pop();
        switch(ch)
        {
            case '+':
                push(opA+opB);
                break;
            case '-':
                push(opA-opB);
                break;
            case'*':
                push(opA*opB);
                break;
            case '/':
                push(opA/opB);
                break;
            case '^':
                push(pow(opA,opB));
                break;
        }
        }
    j++;
    }
    fs=pop();
    return(fs);
}

void push1(char c)
{
    top=++top;
    stack[top]=c;
}
float pop1()
{
    float n;
    n=stack[top];
    top=--top;
    return(n);
}



