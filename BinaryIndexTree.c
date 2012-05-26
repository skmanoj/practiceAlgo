#include<stdio.h>
#define MAX 10

int T[MAX+1]; //Define a space for BIT

//function to update
void update(int idx, int val)
{
 while(idx<=MAX)
 {
  T[idx]+=val;
  idx+=(idx&-idx);
 }
}



//function to query
int query(int idx)
{
 int sum=0;
 while(idx>0)
 {
  sum+=T[idx];
  idx-=(idx&-idx);
 }
 return sum;
}

int readSingle(int idx){
int sum = T[idx]; // sum will be decreased
if (idx > 0){ // special case
	int z = idx - (idx & -idx); // make z first
	idx--; // idx is no important any more, so instead y, you can use idx
	while (idx != z){ // at some iteration idx (y) will become z
		sum -= T[idx]; 
// substruct T frequency which is between y and "the same path"
		idx -= (idx & -idx);
	}
}
return sum;
}

int main()
{
  int i;
  for(i=0;i<11;i++) //initializing the array to 0
    T[i]=0;
  update(4,3);
  for(i=1;i<11;i++)     //printing out array
    printf("%d ",T[i]);
  printf("\n");  
  update(6,3);     //updating bucket 6 to value 3
    update(10,3);  //updating bucket 10 to value 3
      update(9,3);  //updating bucket 9 to value 3
        update(8,3);  //updating bucket 8 to value 3
  for(i=1;i<11;i++)
    printf("%d ",T[i]);  //printing out T values i.e according to binary indexed trees
  printf("\n");  
  for(i=1;i<11;i++)
    printf("%d ",query(i));  //if we want initial buckets to have values a[1]=1, a[2]=3,a[3]=3... than query(3)=a[1]+a[2]+a[3]
  printf("\n");  
  
  for(i=1;i<11;i++)
    printf("%d ",readSingle(i)); //this gives original values put in buckets
  printf("\n");  
    
  return 0;
}
