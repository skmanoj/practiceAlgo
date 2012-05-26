/*You should use it when you do not know what data type the memory
>> contains. The advantage is that once u know the data type, u may
>> typecast the void ptr into the appropriate data type.[/color]
>
> A good example is the "malloc" function. It returns a void* and you can
> typecast it to whatever type you need.
>
> Prototype : void *malloc(size_t size);
> Usage : int *n = (int *) malloc(sizeof(int));[/color]*/
#include<stdio.h>
int fun (int a,int b)
{
   printf("\n in fun");
   return 1;
}

void fun1(int(* fun_to_be_called)(int,int))
{
   printf("\nin fun1");
   printf("%d",(* fun_to_be_called)(5,6));
}
int main()
{
  void *p;//declaration of void pointer
  int a=3;
  double b=5.2;
  p=&a;
  printf("%d",*(int *)p);
  p=&b;
  printf("%f",*(double *)p);
  int(*q)(int,int);  //declaration of function pointer
  q=fun;
  printf("\nfun:%d",(*q)(3,4));
  fun1(fun);//sending function as argument
  return 0;
}