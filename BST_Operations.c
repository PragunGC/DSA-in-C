#include<stdio.h>
#include<conio.h>
struct tree{
    int num;
    struct tree *left;
    struct tree *right;
}*btree=NULL;
struct tree *insert(struct tree *btree,int dig);
void display(struct tree *btree);
void search(struct tree*bt,int s);
struct tree* minimum(struct tree *root);
struct tree* del(struct tree *bt, int x);
int main(){
    int ch=1,n,i;
    int ele;
    printf("Enter number of elements for initial tree : ");
    scanf("%d",&n);
    printf("\nEnter %d elements : ",n);
    for(i=0;i<n;i++){
        scanf("%d",&ele);
        btree=insert(btree,ele);
    }
    while((ch>0) && (ch<5))
    {
        printf("\n1. Insert Element");
        printf("\n2. Search Element");
        printf("\n3. Delete Element");
        printf("\n4. Display Tree");
        printf("\nEnter your choice:  ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\n Enter element to be inserted : ");
            scanf("%d",&ele);
            btree=insert(btree,ele);
            break;
        case 2:
            printf("\n Enter element to be searched: ");
            scanf("%d",&ele);
            search(btree,ele);
            break;
        case 3:
            printf("\n Enter element to be deleted : ");
            scanf("%d",&ele);
            btree=del(btree,ele);
            break;
        case 4:
            display(btree);
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
void display(struct tree*btree)
{
    if(btree!=NULL)
    {
        display(btree->left);
        printf("%d \t",btree->num);
        display(btree->right);
    }
}
void search(struct tree *bt,int s){
    if(bt==NULL)
        printf("\n Number does not exist");
    else{
        if(s==bt->num)
            printf("The number %d is present in tree",s);
        else{
            if(s<bt->num)
                search(bt->left,s);
            else
                search(bt->right,s);

        }

    }
}
struct tree* minimum(struct tree *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left!= NULL)
        return minimum(root->left);
}


struct tree* del(struct tree *bt, int x)
{
    if(bt==NULL)
        return NULL;
    if (x>bt->num)
        bt->right=del(bt->right,x);
    else if(x<bt->num)
        bt->left=del(bt->left,x);
    else
    {

        if(bt->left==NULL && bt->right==NULL)
        {
            free(bt);
            printf("\n Element %d has been deleted.",x);
            return NULL;
        }

        else if(bt->left==NULL || bt->right==NULL)
        {
            struct tree *temp;
            if(bt->left==NULL)
                temp=bt->right;
            else
                temp=bt->left;
            free(bt);
            printf("\n Element %d has been deleted.",x);
            return temp;
        }

        else
        {
            struct tree *temp=minimum(bt->right);
            bt->num=temp->num;
            bt->right=del(bt->right,temp->num);
        }
    }
    return bt;
}



