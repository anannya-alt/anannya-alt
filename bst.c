#include <stdio.h>
#include <stdlib.h>
typedef struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
}bstnode;

bstnode* insert(bstnode* T,int x)
{
    bstnode* temp;
    if(T==NULL)
    {
        temp=(bstnode*)malloc(sizeof(bstnode));
        temp->data=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else if(x<T->data)
    {
        T->left=insert(T->left,x);
    }
    else if(x>T->data)
    {
        T->right=insert(T->right,x);
    }
    return T;
}
void inorder(bstnode* T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d",T->data);
        inorder(T->right);
    }
}

void postorder(bstnode* T)
{
    if(T!=NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d",T->data);
    }
}

void preorder(bstnode* T)
{
    if(T!=NULL)
    {
        printf("%d",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void display(bstnode* T)
{
    if(T!=NULL)
    {
        printf("%d",T->data);
        display(T->left);
        display(T->right);
    }
}

int main()
{
    int n,i,x,ch,sum,ans,cnt;
    bstnode* root=NULL, *root1=NULL;

    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("Enter the node:");
        scanf("%d",&x);
        root= insert(root,x);
    }
    do
    {
        printf("\n1.Inorder");
        printf("\n2.perorder");
        printf("\n3.postorder");
        printf("\n4.display");
        printf("\n5.exit");

        printf("\nEnter your shity choice bitch:");
        scanf("%d",&ch);

        switch(ch)
       {
        case 1: inorder(root);
                break;
        case 2: preorder(root);
                break;
        case 3: postorder(root);
                break;
        case 4: display(root);
                break;
      
        }
    }while(ch!=5);
 return 0;
}