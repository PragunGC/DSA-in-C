#include<stdio.h>
#include<conio.h>
int n,i,ele[25],temp,j;
void selsort(int a[]);
void inssort(int a[]);
void bubsort(int a[]);
void display(int a[]);
int main(){
    int ch=1;
    while((ch>0) && (ch<4)){
        printf("Enter number of elements : ");
        scanf("%d",&n);
        printf("\nEnter %d elements : ",n);
        for(i=0;i<n;i++){
            scanf("%d",&ele[i]);
        }
        printf("\n1. Selection Sort");
        printf("\n2. Insertion Sort");
        printf("\n3. Bubble Sort");
        printf("\nEnter your choice:  ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            selsort(ele);
            break;
        case 2:
            inssort(ele);
            break;
        case 3:
            bubsort(ele);
            break;
        default:
            printf("\n Thank You!");
        }
    }
}
void selsort(int a[]){
    int min;
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[min]>a[j])
                min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("\n Elements after selection sort are :");
    display(a);
}
void inssort(int a[]){
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while((j>=0) && (a[j]>temp)){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    printf("\n Elements after insertion sort are :");
    display(a);
}
void bubsort(int a[]){
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\n Elements after bubble sort are :");
    display(a);
}
void display(int a[]){
    for(i=0;i<n;i++){
        printf("\t %d",a[i]);
        printf("\n");
    }
}
