#include<stdio.h>
#include<malloc.h>
struct tree
{
  int data;
  struct tree *left;
  struct tree *rt;
}*head,*head1;

int *d,a,*store,*lev;
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
  else if(x<(root->data))
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

int ancestor(struct tree *root,int n)
{
   if(root==NULL)
     return 0;
   else if(root->data==n)
     return 1;
   if(ancestor(root->left,n) || ancestor(root->rt,n))
   {
     printf("%d ",root->data);
     return 1;
   }    
}

int levelVal(struct tree *root,int n,int level)
{
  int left,right;
  if(root==NULL)
    return 0;
  else if(root->data==n)
    return level;  
  left=levelVal(root->left,n,level+1);  
  right=levelVal(root->rt,n,level+1);
  if(left)
    return left;
  else if(right)
    return right;  
}

void levelNode(struct tree *root,int level,int presentLevel)
{
  if(root==NULL)
    return;
  else if(presentLevel==level)
  {
    printf("%d ",root->data);    
    return;
  }
  levelNode(root->left,level,presentLevel+1);  
  levelNode(root->rt,level,presentLevel+1);  
}

//tree paths printing
void print(int nod[],int n)
{
  int i=0;
  printf("\n");
  for(i=0;i<n;i++)
  printf("%d ",nod[i]);
  printf("\n");
}

void treePaths(struct tree *root,int nod[],int level)
{
  if(root==NULL)
   return;	
  nod[level]=root->data;
  if(!(root->left) && !(root->rt))
  {
    print(nod,level+1);
    return;
  }   
  else
  { 
   treePaths(root->left,nod,level+1);
   treePaths(root->rt,nod,level+1);  
  }      
}
/*
//for max suym path

void storeMaxPath(int nod[],int level)
{
   lev=&a;
   *lev=level;
   int i=0;
   store=malloc(sizeof(level * sizeof(int)));
   for(i=0;i<level;i++)
   {
     store[i]=nod[i];
   }
}

void printMax()
{
  int i=0,sum=0;
  printf("\n");
  for(i=0;i<(*lev);i++)
  {
    printf("%d ",store[i]);
    sum=sum+store[i];
  }
  printf("\nMax sum:%d",sum);
  return;  
}
void MaxPath(int nod[],int level,int sum)
{
  int i=0;
  if((*d) < sum)
  {
    *d=sum;
    storeMaxPath(nod,level);
  }
  return;
}

void maxTreePath(struct tree *root,int nod[],int level,int sum)
{
  if(root==NULL)
    return;
  nod[level]=root->data;
  sum=sum+root->data;
  if(!(root->left) && !(root->rt))
  {
     MaxPath(nod,level+1,sum);
     return;
  }  
  else
  {
  maxTreePath(root->left,nod,level+1,sum);
  maxTreePath(root->rt,nod,level+1,sum);
  }
}

void maxSumPath(struct tree *head)
{
  int nod[100];
  a=0;
  d=&a;
  maxTreePath(head,nod,0,0);  
  printMax();
  return;
}
*/
void doubleTree(struct tree *root)
{
  struct tree *tmp;
  if(root==NULL)
   return;
  doubleTree(root->left);
  doubleTree(root->rt);
  tmp=malloc(sizeof(struct tree *));
  tmp->data=root->data;
  tmp->left=root->left;
  root->left=tmp;
}

int main()
{
  int i=0,j,sum=0,n,level=1,nod[100];
  d=&a;
  head=NULL;
  head1=NULL;
  printf("\nEnter no. of nodes in tree1:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&j);
    head=append(head,j);
  }
  inorder(head);
  printf("\nEnter a node to find its ancestors:");
  scanf("%d",&n);
  printf("\nAncestors of %d is:%d",n,ancestor(head,n));
  printf("\nEnter a node to find out its level:");
  scanf("%d",&n);
  printf("\nlevel of %d is:%d",n,levelVal(head,n,level));
  printf("\nEnter level to print all nodes at that level:");
  scanf("%d",&n);
  printf("\nNodes are:");
  levelNode(head,n,1);
  printf("\nTree Paths:");
  treePaths(head,nod,0);//print all tree paths
 // maxSumPath(head);
 doubleTree(head);
   inorder(head);
  return 0;
}