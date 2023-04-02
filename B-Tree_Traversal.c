#include<stdio.h>
#include<conio.h>
struct tree{
    int num;
    struct tree *left;
    struct tree *right;
}*btree=NULL;
struct tree *insert(struct tree *btree,int dig);
void inor(struct tree *btree);
void preor(struct tree *btree);
void postor(struct tree *btree);
int main(){
    int ch=1,n,i;
    int ele;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("\nEnter %d elements : ",n);
    for(i=0;i<n;i++){
        scanf("%d",&ele);
        btree=insert(btree,ele);
    }
    while((ch>0) && (ch<4))
    {

        printf("\n1. Preorder Traversal");
        printf("\n2. Postorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\nEnter your choice:  ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            preor(btree);
            break;
        case 2:
            postor(btree);
            break;
        case 3:
            inor(btree);
            break;
        default:
            printf("\n Thank You!");
        }
    }
}
struct tree *insert(struct tree *btree,int dig){
    if(btree==NULL){
        btree=(struct tree*)malloc(sizeof(struct tree));
        btree->left=NULL;
        btree->right=NULL;
        btree->num=dig;
    }
    else{
        if(dig<btree->num)
            btree->left=insert(btree->left,dig);
        else{
            if(dig>btree->num)
                btree->right=insert(btree->right,dig);
            else{
                if(dig==btree->num){
                    printf("\nValue repeated");
                    exit(0);
                }
            }
        }

    }
    return(btree);
};
void inor(struct tree*btree)
{
    if(btree!=NULL)
    {
        inor(btree->left);
        printf("%d \t",btree->num);
        inor(btree->right);
    }
}
void preor(struct tree*btree)
{
    if(btree!=NULL)
    {
        printf("%d \t",btree->num);
        preor(btree->left);
        preor(btree->right);
    }
}
void postor(struct tree*btree)
{
    if(btree!=NULL)
    {
        postor(btree->left);
        postor(btree->right);
        printf("%d \t",btree->num);
    }
}
