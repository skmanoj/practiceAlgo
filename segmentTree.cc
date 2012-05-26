#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;


template<class T>
class SegmentTree
{
     int *A,size;
     public:
     SegmentTree(int N)
     {
          int x = (int)(ceil(log2(N)))+1;
          size = 2*(int)pow(2,x);
          A = new int[size];
          memset(A,-1,sizeof(A));
     }
     void initialize(int node, int start,
                         int end, T *array)
     {

          if (start==end)
             A[node] = start;
          else
          {
              int mid = (start+end)/2;
              initialize(2*node,start,mid,array);
              initialize(2*node+1,mid+1,end,array);
              if (array[A[2*node]]<=
                     array[A[2*node+1]])
                 A[node] = A[2 * node];
              else
                  A[node] = A[2 * node + 1];
          }
     }
     int query(int node, int start,
                   int end, int i, int j, T *array)
     {
         int id1,id2;
         if (i>end || j<start)
            return -1;

         if (start>=i && end<=j)
            return A[node];

         int mid = (start+end)/2;
         id1 = query(2*node,start,mid,i,j,array);
         id2 = query(2*node+1,mid+1,end,i,j,array);

         if (id1==-1)
            return id2;
         if (id2==-1)
            return id1;

         if (array[id1]<=array[id2])
            return id1;
         else
             return id2;
     }
};

int main()
{
    int i,j,N;
    int A[1000];
    scanf("%d",&N);
    for (i=0;i<N;i++)
        scanf("%d",&A[i]);

    SegmentTree<int> s(N);
    s.initialize(1,0,N-1,A);
    while (scanf("%d%d",&i,&j)!=EOF)
      printf("%d\n",A[s.query(1,0,N-1,i-1,j-1,A)]);
}
