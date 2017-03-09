//
//  main.c
//  merge sort
//
//  Created by 楊博名 on 2016/12/27.
//  Copyright © 2016年 楊博名. All rights reserved.
//

#include<stdio.h>

void mergeSort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

int totalNumber=0;

int main(void)
{
    int a[30],n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    totalNumber =n;
    printf("Enter array elements:");
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    mergeSort(a,0,n-1);
    
    printf("\nSorted array is : ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    
    return 0;
}

void mergeSort(int a[],int i,int j)
{
    int mid,count;
    
    if(i<j)
    {
        mid=(i+j)/2;
        
        mergeSort(a,i,mid);        //left recursion
        mergeSort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
        
        for (count=0; count<totalNumber; count++) {
            printf("%d, ",a[count]);
        }
        printf("\n");
        
    }
}

void merge(int a[],int i1,int j1,int i2,int j2)//left:i1~j1, right:i2~j2
{
    int temp[50];    //array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;
    
    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
    
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
    
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++){
        a[i]=temp[j];
        //printf("%d, ", temp[j]);
    }
    printf("\n");

}
