#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int v[10][10]; 
int max (int a,int b) 
{ 
 return (a>b) ? a:b; 
} 
void knapsack (int values[],int weights[],int n,int capacity) 
{ 
 int i,j; 
 for(i=0;i<=n;i++) 
 { 
 for(j=0;j<=capacity;j++) 
 { 
 if(i==0 || j==0) 
 v[i][j]=0; 
 
 else if((j-weights[i])<0) 
 v[i][j]=v[i-1][j]; 
 
 else
 v[i][j]=max(v[i-1][j],values[i]+v[i-1][j-weights[i]]); 
 } 
 } 
 
} 
void main() 
{ 
 int i,j,capacity,n,weights[10],values[10]; 
 clock_t start,end; 
 double clk; 
 
 printf("ENTER NO OF ITEMS\n"); 
 scanf("%d",&n); 
 
 printf("ENTER VALUES OF THESE ITEMS\n"); 
 for(i=1;i<=n;i++) 
 scanf("%d",&values[i]); 
 
 printf("ENTER WEIGHT OF THESE ITEMS\n"); 
 for(i=1;i<=n;i++) 
 scanf("%d",&weights[i]); 
 
 printf("ENTER CAPACITY OF BAG\n"); 
 scanf("%d",&capacity); 
 
 for(i=0;i<=n;i++) 
 { 
 for(j=0;j<=capacity;j++) 
 { 
 v[i][j]=0; 
 } 
 } 
 
 
 start=clock(); 
 knapsack(values,weights,n,capacity); 
 end=clock(); 
 
 for(i=0;i<=n;i++) 
 { 
 for(j=0;j<=capacity;j++) 
 { 
 printf("%d ",v[i][j]); 
 } 
 printf("\n"); 
 } 
 
 printf("OPTIMAL SOLUTION OF THE PROBLEM IS %d\n",v[n][capacity]); 
 
 clk=(double)(end-start)/CLOCKS_PER_SEC; 
 
 printf("TIME REQUIRED IS %f",clk); 
}
