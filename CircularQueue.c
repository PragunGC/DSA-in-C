#include<stdio.h>
#define MAX 5
int q[MAX];
int rear=-1,front=-1;
void enq(int item);
void deq();
void dispay();
int main(){
int ele,ch=1;
while(ch>0 && ch<4){
    printf("\n Enter 1 to enqueue element into circular queue.");
    printf("\n Enter 2 to dequeue an element from circular queue.");
    printf("\n Enter 3 to display elements of circular queue.\n");
    scanf("%d",&ch);
    switch(ch){
case 1:
    printf("Input the element to be enqueued : ");
    scanf("%d", &ele);
    enq(ele);
    break;
case 2:
    deq();
    break;
case 3:
    display();
    break;
default:
    printf("\n Thank You!");


    }
}
}
void enq(int item){
if((front == 0 && rear == MAX-1) || (front == rear+1))
{
    printf("Queue Overflow \n");
    return;
}
if(front == -1)
{
    front = 0;
    rear = 0;
}
else
{
    if(rear == MAX-1)
        rear = 0;
    else
        rear = rear+1;
}
q[rear] = item ;
}
void deq(){
if(front == -1)
{
    printf("Queue Underflow \n");
    return ;
}
printf("Element deleted from queue is : %d",q[front]);
if(front == rear)
{
    front = -1;
    rear=-1;
}
else
{
    if(front == MAX-1)
        front = 0;
    else
        front = front+1;
}
}
void display(){
int f=front,r=rear;
if(front == -1)
{
    printf("Queue Underflow \n");
    return;
}
printf("Queue elements :\n");
if(f<=r){
    while(f<=r)
    {
        printf("%d ",q[f]);
        f++;
    }
}
else
{
    while(f<= MAX-1)
    {
        printf("%d ",q[f]);
        f++;
    }
    f=0;
    while(f<=r)
    {
        printf("%d ",q[f]);
        f++;
    }
}
}

