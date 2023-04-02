#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node* next;
}*top=0;
void pop();
void push();
void peek();
void display();
int main(){
    int ch=1;
    while(ch>0 && ch<5){
        printf("\n*******Stack using LL*******");
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.PEEK");
        printf("\n 4.DISPLAY");
        printf("\n Enter your choice :  ");
        scanf("%d",&ch);
        switch(ch){
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
            printf("\n Thank You!");
        }
    }

}
void pop(){
    if(top==0)
        printf("\n Stack Empty.");
    else{
       printf("\n Element poped out is : %d",top->data);
       top=top->next;
    }

}
void push(){
    int item;
    struct node *ele;
    printf("\n Enter element to be pushed in :  ");
    scanf("%d",&item);
    ele=(struct node*) malloc (sizeof(struct node));
    ele->data=item;
    ele->next=top;
    top=ele;
}
void peek(){
    if(top==0)
        printf("\n Stack Empty.");
    else
        printf("\n Top element is : %d",top->data);

}
void display(){
    struct node *t;
    t=top;
    if(t==0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Printing Stack elements \n");
        while(t!=0)
        {
            printf("%d\n",t->data);
            t=t->next;
        }
    }
}

