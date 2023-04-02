#include <stdio.h>
void shell(int arr[], int num);
int Max(int arr[],int n);
void cs(int arr[],int n,int exp);
void radix(int arr[],int n);
void display(int arr[],int n);
int main()
{
    int arr[30];
    int ch=1,n;
    while((ch>0)&&(ch<3)){
        printf("Enter total no. of elements : ");
        scanf("%d", &n);
        printf("\nEnter %d numbers: ", n);
        for (int i=0 ;i<n;i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("\n1. Shell Sort");
        printf("\n2. Radix Sort");
        printf("\nEnter your choice:  ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            shell(arr,n);
            display(arr,n);
            break;
        case 2:
            radix(arr,n);
            display(arr,n);
            break;
        default:
            printf("\n Thank You!");
        }
    }

}
void shell(int arr[],int num)
{
    int i,j,k,tmp;
    for (i=num/2;i>0;i=i/2)
    {
        for (j=i;j<num;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if(arr[k+i]>=arr[k])
                    break;
                else
                {
                    tmp=arr[k];
                    arr[k]=arr[k+i];
                    arr[k+i]=tmp;
                }
            }
        }
    }
}
int Max(int arr[],int n) {
    int mx=arr[0];
    int i;
    for (i=1;i<n;i++)
        if (arr[i]>mx)
            mx=arr[i];
    return mx;
}
void cs(int arr[],int n,int exp) {
    int output[n];
    int i,count[10] = { 0 };

    for (i= 0;i<n;i++)
        count[(arr[i]/exp)%10]++;
    for (i=1;i<10;i++)
        count[i]+=count[i - 1];
    for (i=n-1;i>=0;i--) {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (i=0;i<n;i++)
        arr[i]=output[i];
}
void radix(int arr[],int n) {
    int m=Max(arr,n);
    int exp;
    for (exp =1;m/exp>0;exp*=10)
        cs(arr,n,exp);
}
void display(int arr[],int n) {
    for (int i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
