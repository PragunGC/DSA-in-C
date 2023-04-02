#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node* next;
}*rear=0,*front=0;
void enq();
void deq();
void display();
int main(){
    int ch=1;
    while(ch>0 && ch<4){
        printf("\n*******Queue using LL*******");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        default:
            printf("\n Thank You");
        }
    }
}
void enq(){
    int item;
    struct node *ele;
    ele=(struct node*) malloc (sizeof(struct node));
    printf("\n Enter element to be enqueued : ");
    scanf("%d",&item);
    ele->data=item;
    ele->next=0;
    if(front==0)
        front=rear=ele;
    else{
        rear->next=ele;
        rear=ele;
    }

}
void deq(){
    if(front==0)
        printf("Queue Underflow");
    else{
        printf("\n Element dequeued is : %d",front->data);
        front=front->next;
    }

}
void display(){
    struct node *t;
    t=front;
    if(front==0)
        printf("Queue Underflow");
    else{
        printf("Printing Queue elements \n");
        while(t!=0)
        {
            printf("%d\t",t->data);
            t=t->next;
    }
}
}
