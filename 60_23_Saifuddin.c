/*Merge Sort*/

/*
Name = Saifuddin Syed
Roll No = 60
pid = 23
SE-IT
2023-24
*/

#include<stdio.h>
# include <stdlib.h>
void partition(int *,int,int);

void main(){

  int n,temp,i,j,a[20];
  printf("Enter total numbers of elements: ");
  scanf("%d",&n);

  printf("Enter %d elements: ",n);
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);

  partition(a,0,n-1);

  printf("\n After sorting: ");
  for(i=0;i<n;i++)
      printf(" %d",a[i]);
}

void partition(int *a,int low,int high)
{
    int mid=0;

    if(low<high)   
    {
      mid=(low+high)/2;
      partition(a,low,mid);
      partition(a,mid+1,high);
      mergesort(a,low,mid,high);
    }
}

 mergesort(int *a,int low,int mid,int high)
{
 int i,m,k,l,temp[20];
 l=low;
 i=low;         
 m=mid+1;

 while(l<=mid && m<=high)     
   {                                               
    if(a[l]<=a[m])                        
	  {                                            
	      temp[i]=a[l];                     
		  l++;i++;
     }
    else
     {
		temp[i]=a[m];
		m++;i++;
     }
  } 


 if(l>mid)     
   {
     for(k=m;k<=high;k++)  
       {
	 temp[i]=a[k];
	 i++;
       }
   }
 else
   {
    for(k=l;k<=mid;k++)
     {
      temp[i]=a[k];
      i++;
     }
   }


   for(k=low;k<=high;k++)
  {
    a[k]=temp[k];
  }
 }