
 
#include<stdio.h>  
int fact(int n)  
{ 
 if (n==0)  
 { 
  return 1;  
 } 
 else 
 { 
  return n*fact(n -1); 
 } 
} 
 
int main()  
{ 
 int n,f;  
 printf("Enter a number to find factorial : ");  
 scanf("%d",&n);  
 f=fact(n);  
 printf("Factorial = %d \n",f); 
 return 0;  
}