#include <stdio.h>
#include<conio.h>
void quicksort(int l[], int low, int high);
int main()
{
    int a[50];
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements to be sorted:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("After applying quick sort\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

    return 0;
}
void quicksort(int l[], int low, int high)
{
    int pivot,i,j,temp;
    if (low<high)
    {
        pivot=low;
        i=low;
        j=high;
        while(i<j)
        {
            while((l<=l[pivot])&&(i<=high))
            {
                i++;
            }
            while((l[j]>l[pivot])&&(j>=low))
            {
                j--;
            }
            if (i<j)
            {
                temp=l[i];
                l[i]=l[j];
                l[j]=temp;
            }
        }
        temp=l[j];
        l[j]=l[pivot];
        l[pivot]=temp;
        quicksort(l,low,j-1);
        quicksort(l,j+1,high);
    }
}
