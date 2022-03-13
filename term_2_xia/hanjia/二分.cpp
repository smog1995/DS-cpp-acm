#include <stdio.h>
#include <stdlib.h>
Position BinarySearch( List L, ElementType X )
{
	int high=L->Last,low=1;
	int mid=(high+low)/2;
	while(low<=high)
	{
		if(L->Data[mid]>X) high=mid-1;
		else if(L->Data[mid]<X)low=mid+1;
		else return mid;
		mid=low+(high-low)/2;
	}
	return NotFound;
}

 Position BinarySearch( List L, ElementType X )
 {
     int left = 1;
     int right = L->Last;
     int mid = (left + right) / 2;
     while (left <= right)
     {
         if (X > L->Data[mid])
         {
             left = mid + 1;
             mid = (left + right) / 2;
         }
         else if (X < L->Data[mid])
         {
             right = mid - 1;
             mid = (left + right) / 2;
         }
         else
             return mid;
     }
 
     return NotFound;
 
 }
