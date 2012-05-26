#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct tree
{
  int data;
  struct tree *left;
  struct tree *rt;
}*head,*head1;

struct tree * append(struct tree *root, int x)
{
  struct tree *tmp;
  if(root==NULL)
  {
    tmp=malloc(sizeof(struct tree*));
    tmp->data=x;
    tmp->left=NULL;
    tmp->rt=NULL;
    return tmp;
  }
  else if(x<=(root->data))
    root->left=append(root->left,x);
  else if(x>(root->data))  
    root->rt=append(root->rt,x);
  return root;  
}

void inorder(struct tree *root)
{
  if(root==NULL) 
    return;
  inorder(root->left);
  printf("%d",root->data);
  inorder(root->rt);
}

int sub(struct tree *mainTree, struct tree *subTree)
{
   int lt,right;

   if(!mainTree && subTree)
     return 0;
   if(!subTree)
     return 1;
   lt=sub(mainTree->left,subTree->left);        
   right=sub(mainTree->rt,subTree->rt);
   if(!lt || !right)
     return 0;     
   if(mainTree->data == subTree->data)
     return 1;
   else
     return 0;  
}

mirror(struct tree *root)
{
  struct tree *ltSub,*rtSub,*tmp;
  if(root==NULL)
    return;
  mirror(root->left);
  mirror(root->rt);
  tmp=root->left;
  root->left=root->rt;
  root->rt=tmp;
}

int lca(struct tree *root,int val1,int val2)
{
  int lft,rgt;
  if(root==NULL)
    return 0;
  else if(root->data == val1 || root->data==val2)
    return root->data;  
  lft=lca(root->left,val1,val2);
  rgt=lca(root->rt,val1,val2);
  if(lft && rgt)
    return root->data;
  return lft?lft:rgt;  
      
}

int maxElement(struct tree *root)
{
  int left,right;
  if(root==NULL)
    return 0;
  left=maxElement(root->left);
  right=maxElement(root->rt);        
  if(left >= right)
  {
    if( root->data < left)
      return left;
    return root->data;
  }
  else
  {
     if(root->data< right)
       return right;
     return root->data;  
  }
      
}

int main()
{
  int n,n1;
  head=NULL;
  head1=NULL;
  printf("\nEnter no. of nodes in tree1:");
  while(1)
  {
    scanf("%d",&n);
    if(n==-1)
    break;
    head=append(head,n);
  }
  inorder(head);  
  printf("\nEnter no. of nodes in tree2:");
  while(1)
  {
    scanf("%d",&n);
    if(n==-1)
    break;
    head1=append(head1,n);
  }
  inorder(head1);
  printf("\nhead2 is subtree of head1:%d",sub(head,head1));
  printf("\nMirror tree:");
  mirror(head);
  inorder(head);
  printf("\nLCA enter 2 numbers:");
  scanf("%d",&n);
  scanf("%d",&n1);
  printf("\nLCA of given no's:%d",lca(head,n,n1));
  int max=INT_MIN;
  printf("\nFinding max element of tree:%d",maxElement(head));
  return 0;
}