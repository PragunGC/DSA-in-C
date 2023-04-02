#include<stdio.h>

void push();
void pop();
void display();
void peek();
int stack[10],ch=1,n,top,x,i;
int main()
{

    top = -1;
    printf("\n Enter the size of STACK : ");
    scanf("%d",&n);
    printf("\nSTACK IMPLEMENTATION USING ARRAYS\n");
    while(ch>0 && ch<5){
        printf("\n1.PUSH Element\n2.POP Element\n3.PEEK top \n4.DISPLAY\n");
        printf("\nEnter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf ("\n Thank You!\n");
        }
    }




 return 0;
}

void push()
{
 if(top >= n - 1)
 {
 printf("\nSTACK OVERFLOW\n");

 }
 else
 {
 printf("Enter a value to be pushed : ");
 scanf("%d",&x);
 top++;
 stack[top] = x;
 }
 }

void pop()
{
 if(top <= -1)
 {
 printf("\nSTACK UNDERFLOW\n");
 }
 else
 {
 printf("\nThe popped element is %d",stack[top]);
 top--;
 }
 }
 void peek(){
 if(top<=-1){
    printf("\n STACK UNDERFLOW\n");
 }
 else{
    printf("\n %d",stack[top]);
 }
 }

void display()
{
 if(top >= 0)
 {
    printf("\nELEMENTS IN THE STACK\n\n");
    for(i = top ; i >= 0 ; i--)
        printf("%d\n",stack[i]);
 }
else
 {
    printf("\nEMPTY STACK\n");
 }
 }
