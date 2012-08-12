#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct trie
{
   struct trie *arr[26];
   char *meaning;
   int flag;
}*head;

struct trie* init(struct trie *root)
{
   root=malloc(sizeof(struct trie *));
   root->flag=-1;
   int i=0;
   for(i=0;i<26;i++)
   	root->arr[i]=NULL;
   return root;	
}

void insert(struct trie *root,char *word,char * mean)
{
    int wordLen=strlen(word);
    int i;
    for(i=0;i<wordLen;i++)
    {
        int val=word[i]-'a';
        if(!(root->arr[val]))
        {
            struct trie *tmp;
            tmp=init(tmp);
            root->arr[val]=tmp;
            root=tmp;
            if(i==(wordLen-1))
            {
               root->flag=1;
			   root->meaning=malloc(sizeof(char)*strlen(mean));
               strcpy(root->meaning,mean);
			   break;
             }  
            continue;   
        }
        root=root->arr[val];
        if(i==(wordLen-1))
        {
           root->flag=1;
		   root->meaning=malloc(sizeof(char)*strlen(mean));		   
           strcpy(root->meaning,mean);
        }              
    } 
}

char* findMeaning(struct trie *root,char *word)
{
   int len=strlen(word);
   int i;
   for(i=0;i<len;i++)
   {
       int val=word[i]-'a';
		if(!(root->arr[val]))
			return NULL;
		root=root->arr[val];	
   }
   if(root->flag==1)
		return root->meaning;
	return NULL;	
}


int main()
{
   head=init(head);
   insert(head,"me","you");
   printf("%s",findMeaning(head,"me"));
   return 0;
}