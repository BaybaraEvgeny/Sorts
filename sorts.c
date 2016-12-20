#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorts.h"

int comparator (char *x, char *y){ 
 int i = 0;
 while((x[i]!= '\0')&&(y[i]!= '\0')){
  if (x[i] > y[i]){
   return 1;
  }
  if (x[i] < y[i]){
   return 0;
  }
  i++;
 }
 if (x[i] == '\0'){
  return 0;
 }
 if (y[i] == '\0'){
  return 1;
 }
 }


void bubblesort(char **str, int size){ 
 int x = 0,y = 0;
 for (x = 0; x < size-1; x++){
  for (y = 0; y < size-1; y++){
   if (comparator(str[y], str[y+1]) > 0){
    char *strN = str[y];
    str[y] = str[y+1];
    str[y+1] = strN;
   }
  }
 }
}

void insertion(char **str, int size){ 
 int x = 0,y = 0;
 for(x = 1; x < size; x++){
  for(y = x; y > 0 && comparator(str[y-1], str[y]) > 0; y--){
   char *strN = str[y];
   str[y] = str[y-1];
   str[y-1] = strN;
  }
 }
}

void quicksort(char **str, int size){ 
 char *elem;
 elem = str[size / 2];
 int x = 0, y = size;
 while(x <= y) {
  while(comparator(elem, str[x]))
   x++;
  while(comparator(str[y], elem))
   y--;
  if (x <= y) {
   char *strN = str[x];
   str[x] = str[y];
   str[y] = strN;
   x++;
   y--;
  }
 }
 if (y > 0)
  quicksort(str, y);
 if (size > x)
  quicksort(str + x, size - x);
}

void mergesort(char **str, int n, int m){
 if (n < m){
  int q = (m+n)/2;
  mergesort(str, n, q);
  mergesort(str, q+1, m); 
  merge(str, n, q, m);
 }
}

void merge(char **str, int n, int q, int m){
 int i, j, k;
 int n1 = q-n+1;
 int n2 = m-q;

 char *Left[n1], *Right[n2]; 
 for (i = 0; i < n1; i++){
  Left[i] = str[n+i];
 }
 for (j = 0; j < n2; j++){
  Right[j] = str[q+1+j];
 }

 i = 0; 
 j = 0;
 k = n;
 while (i < n1 && j < n2){
  if (comparator(Left[i], Right[j]) <= 0){
   str[k] = Left[i];
   i++;
  }
  else{
   str[k] = Right[j];
   j++;
  }
  k++;
 }

 while (i < n1){
  str[k] = Left[i];
  i++;
  k++;
 }


 while (j < n2){
  str[k] = Right[j];
  j++;
  k++;
 }
}
