#include<stdio.h>
#include<string.h>
#include<malloc.h>

int * failure(char p[],int n)
{
  int *f=malloc(sizeof(int)*n);
  f[0]=0;
  int i=1,j=0;
  while(i<n)
  {
    if(p[i]==p[j])
    {
      f[i]=j+1;
      ++i;
      ++j;       
    }
    else
    {
      if(j==0)
      {
        f[i]=0;
        ++i;
      }
      else
       j=f[j-1];
    }
  }
  return f;
}

int kmp(char s[],char p[],int n,int m)
{
  int i=0,j=0;
  int *f=failure(p,m);
  int k=0;

  while(i<n)
  {
    if(s[i]==p[j])
    {
       if(j==m-1)
         return 1;
       i++;
       j++;  
    }
    else
    {
       if(j==0)
         i++;
       else
         j=f[j-1];  
    }
  }
  return 0;
}

int main()
{
  char s[11];
  char p[6];
  int i=0;
  while(i<24)
  {
  scanf("%s %s",s,p);
  printf("%d",kmp(s,p,strlen(s),strlen(p)));
  i++;
  }
  return 0;
}