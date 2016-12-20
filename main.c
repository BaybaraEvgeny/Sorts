#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "sorts.h"


void main(int argc, char **argv){

 FILE *file; 
 if ((file = fopen(argv[2],"r")) == NULL){
  printf("Couldn't open the file.\n");
  exit(1);
 }

 int size = atoi(argv[1]);
 char ch = 0;
 int sum = 0;  
 while(ch!=EOF){ 
  ch = fgetc(file);
  if(ch == '\n'){ 
  sum++;
  } 
 }
 
 if (size > sum){
  size = sum;
 }

 rewind(file);

 int *len = malloc(sizeof(int)*(size));
 
 int i = 0, k = 0,f = 0; 	
 while(f!=size){ 
  ch = fgetc(file);	
  k++;
  if (ch == '\n' || ch == '\0'){
   len[i] = k;
   k = 0;
   i++;
   f++;
  }	
 }
 

 char **str = malloc(sizeof(char*)*(size));

 rewind(file);

 int p = 0;
 while(p < size){ 
  int t = 0;
  str[p] = malloc(sizeof(char)*(len[p]));
  for(t = 0; t < len[p]-1; t++){
   str[p][t] = fgetc(file);
  }
  ch = fgetc(file);
  str[p][t] = '\0';
  p++;
 }

 fclose(file);

printf("\nChoose the type of sort:\n1) bubble sort\n2) insertion sort\n3) quick sort\n4) merge sort\n"); 

 int t = 0,w = 0;
 while(!w){ 
  scanf("%d",&t);
  switch(t){
   case 1:
   bubblesort(str,size);
   w = 1;
   break;
      
   case 2:
   insertion(str,size);
   w = 1;
   break;

   case 3: 
   quicksort(str,size-1); 
   w = 1;    
   break;
  
   case 4:
   mergesort(str,0,size-1);
   w = 1;
   break;

   default:
   printf("Wrong action\n");
   break;
  }
 }
 
 printf("Sorted massive:\n"); 
 for (i = 0; i < size; i++){
  printf("%s\n", str[i]);
 }

 for (i = 0; i < size; i++)
  free(str[i]);

 free(len);
 free(str);
}


