#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node* next;
}*list=0;
int ele;
void endins();
void bigins();
void posins();
void bigdel();
void enddel();
void posdel();
void search();
void display();
int main(){
    int ch=1;
    while(ch>0 && ch<9){
    printf("\n********Linked List Menu********\n");
    printf("\n 1. Beginning Insertion");
    printf("\n 2. End Insertion");
    printf("\n 3. Position Insertion");
    printf("\n 4. Beginning Deletion");
    printf("\n 5. End Deletion");
    printf("\n 6. Position Deletion");
    printf("\n 7. Search for element");
    printf("\n 8. Display linked list");
    printf("\n Enter your choice:\n");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        bigins();
        break;
    case 2:
        endins();
        break;
    case 3:
        posins();
        break;
    case 4:
        bigdel();
        break;
    case 5:
        enddel();
        break;
    case 6:
        posdel();
        break;
    case 7:
        search();
        break;
    case 8:
        display();
        break;
    default:
        printf("\nThank You!");
    }
    }


}
void bigins(){
    struct node *nnode;
    printf("\n Enter element to be inserted :  ");
    scanf ("%d", &ele);
    nnode = (struct node*) malloc (sizeof(struct node));
    nnode -> data = ele;
    nnode -> next = 0;
    if (list == 0)
        list = nnode;
    else
    {
        nnode -> next = list;
        list = nnode;
    }

}
void endins(){
    struct node *nnode, *t;
    printf("\n Enter element to be inserted :  ");
    scanf ("%d", &ele);
    nnode = (struct node*) malloc(sizeof(struct node));
    nnode -> data = ele;
    nnode -> next = 0;
    if (list == 0)
        list = nnode;
    else
    {
        t = list;
        while (t -> next != 0){
            t = t->next;
        }
        t -> next = nnode;
    }
}
void posins(){
    int pos,c;
    struct node *nnode,*t;
    printf ("\nEnter value and position to insert	:");
    scanf("%d%d",&ele,&pos);
    nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=ele;
    nnode->next=0;
    c=1;
    t=list;
    while((c<pos-1)&&(t->next!=0))
     {
        t=t->next;
        c++;
     }
     nnode->next=t->next;
     t->next = nnode;
}
void bigdel(){
    if(list==0)
        printf("\n Linked list empty.");
    else{
        if(list->next==0){
        printf("The only item is deleted:%d",list->data);
        list=0;
        }
        else{
        printf("the first item is deleted:%d",list->data);
        list=list->next;
        }
    }
}
void enddel(){
    struct node *t,*s;
    if(list==0)
        printf("\n Linked list empty.");
    else{
        if(list->next==0){
        printf("the only item is deleted:%d",list->data);
        list=0;
        }
        else{
        t = list;
        while (t -> next != 0){
            s=t;
            t = t->next;
        }
        printf("last item in list is deleted:%d",t->data);
        s->next=0;
        }

}
}
void posdel(){
    int c,pos;
    struct node *t,*s;
    c=1;
    t=list;
         while(t->next!=0)
         {
                    t=t->next;
                    c++;
         }
    if(list==0)
        printf("\n Linked list empty.");
    else{
        if(list->next==0){
        printf("the only item is deleted:%d",list->data);
        list=0;
        }
        else{
        printf ("\nEnter position to perform deletion	:");
        scanf("%d",&pos);
        if(pos==1){
            bigdel();
        }
        else{
            if(pos==c)
                enddel();
            else{
                c=1;
                t=list;
                while((c<pos)&&(t->next!=0)){
                    s=t;
                    t=t->next;
                    c++;
                }
                printf("the deleted item is:%d",t->data);
                s->next=t->next;
            }
        }

        }

}
}
void search(){
    if(list==0)
        printf("\n Linked list empty.");
    else{
        printf("\n Enter element to be searched  : ");
        scanf("%d",&ele);
        struct node *t;
        int c=1,f=0;
        t=list;
        while(t!=0){
            if(t->data==ele){
                printf("\n Element found at position %d",c);
                f=1;
                break;
                }
            else
                t=t->next;
                c++;

        }
        if(f==0)
            printf("\n Element not found");
    }
}
void display()
{
     struct node *t;
     if(list==0)
                printf("\nLinked list is empty.");
     else
     {
         t=list;
         while(t!=0)
         {
                    printf("%d\t",t->data);
                    t=t->next;
         }
     }
}
