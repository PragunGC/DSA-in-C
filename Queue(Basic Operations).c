#include<stdio.h>
#define MAX 10
void enq (int a);
void deq ();
void display ();
int q[MAX], item, ch=1, ele, rear, front;
int main()
{
rear = 0;
front = 0;
while(ch>0 && ch<4)
{

    printf("\n*****Queue operations*****");
    printf("\n1.ENQUEUE element");
    printf("\n2.DEQUEUE");
    printf("\n3.DISPLAY");
    printf("\n\nEnter choice : ");
    scanf("%d",&ch);
    switch(ch){
case 1:
    printf("\nEnter Element to be Enqueued");
    scanf("%d",&ele);
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
return 0;
}
void enq (int a)
{
    if (rear == MAX)
        printf("Overflow");
    else
    {
        rear = rear + 1;
        q[rear] = a;
        if (front == 0)
            front = 1;
}
}

void deq()
{
    if (front == 0)
        printf("Underflow");
    else
    {
        item = q[front];
        q[front] = 0;
        if (front == rear)
            front = rear = 0;
        else
            front = front + 1;
        printf("\n Deleted item is %d", item);
}
}

void display()
{
    int i;
    if (front == 0)
        printf("Queue is empty");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t",q[i]);
}
}
