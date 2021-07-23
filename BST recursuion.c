#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *addBST(struct node *root,int e);
struct node *getnode(int e);
void inorder(struct node *root);
int main()
{
    struct node *root=NULL;
    int ch,e,n;
    while(1)
    {
        printf("Enter the choice\n");
        scanf("%d",&ch);
        printf("1.Add BST\n");
        switch(ch)
        {
           case 1:printf("Enter  the element\n");
                  scanf("%d",&e);
                  root=addBST(root,e);
                  break;
            case 2:inorder(root);
                    getchar();
                   break;

            case 3:exit(0);
        }
    }
}
struct node *addBST(struct node *root,int e)
{
   if(root==NULL)
    return getnode(e);
   else
   {
       if(e<root->data)
        root->left=addBST(root->left,e);
       else
        root->right=addBST(root->right,e);

       return root;
   }
}
 struct node *getnode(int e)
 {
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=e;
    t->left=NULL;
    t->right=NULL;
    return t;
 }
 void inorder(struct node *root)
 {
     if(root == NULL)
        return;
        inorder(root->left);

         printf("%d\t",root->data);

         inorder(root->right);
 }



