#include<stdio.h>
#include<stdlib.h>
struct poly{
    int coeff;
    int pow;
    struct poly *next;
};
struct poly *p1=NULL,*p2=NULL,*psum=NULL;
void poly_enter(struct poly *node);
void poly_add(struct poly *poly1,struct poly *poly2,struct poly *polysum);
void display(struct poly *node);
int main(){
    p1=(struct poly *)malloc(sizeof(struct poly));
    p2=(struct poly *)malloc(sizeof(struct poly));
    psum=(struct poly *)malloc(sizeof(struct poly));
    printf("\nEnter 1ST Polynomial Expression : ");
    poly_enter(p1);
    printf("\nEnter 2ND Polynomial Expression :");
    poly_enter(p2);
    poly_add(p1,p2,psum);
    printf("\nAdded polynomial:");
    display(psum);
}
void poly_enter(struct poly *node)
{
 char ch;
 do
 {
  printf("\nEnter coefficient:");
  scanf("%d",&node->coeff);
  printf("\nEnter power:");
  scanf("%d",&node->pow);
  node->next=(struct poly*)malloc(sizeof(struct poly));
  node=node->next;
  node->next=NULL;
  printf("\nAdd another term? (y/n):");
  ch=getch();
 }
 while(ch=='y' || ch=='Y');
}
void poly_add(struct poly *poly1,struct poly *poly2,struct poly *polysum){

    while(poly1->next!=NULL &&  poly2->next!=NULL)
    {
        if(poly1->pow>poly2->pow)
        {
            polysum->pow=poly1->pow;
            polysum->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
            polysum->pow=poly2->pow;
            polysum->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        else
        {
            polysum->pow=poly1->pow;
            polysum->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        polysum->next=(struct poly *)malloc(sizeof(struct poly));
        polysum=polysum->next;
        polysum->next=NULL;
    }
    while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            polysum->pow=poly1->pow;
            polysum->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        if(poly2->next)
        {
            polysum->pow=poly2->pow;
            polysum->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        polysum->next=(struct poly*)malloc(sizeof(struct poly));
        polysum=polysum->next;
        polysum->next=NULL;
       }

}
void display(struct poly *node){
    while(node->next!=NULL)
    {
        printf("%dx^%d",node->coeff,node->pow);
        node=node->next;
        if(node->next!=NULL)
            printf(" +");
    }

}

