/*
 * MergeSort.c
 *
 *  Created on: 22.06.2014
 *      Author: idalexi
 */

#include <stdio.h>
int* mergeSort(int* array, const int length)
{
	if (length<=1)
		return array;
	if (length == 2)
	{
		if (array[0]>array[1])
		{
			int t = array[0];
			array[0]=array[1];
			array[1]=t;
			return array;
		}
	}
	//length >= 3
	const int Nleft = length/2;
	const int Nright = length-Nleft;
	int left[Nleft];
	int right[Nright];
	int i;
	for(i=0;i<Nleft;i++)
	{
		left[i]=array[i];
	}
	int j;
	for(j=0;j<Nright;j++,i++)
	{
		right[j]=array[i];
	}
	mergeSort (&left[0], Nleft);
	mergeSort (&right[0],Nright);
	if (left[Nleft-1]<=right[0])
	{
		for(i=0;i<Nleft;i++)
		{
			array[i]=left[i];
		}
		for(j=0;j<Nright;j++,i++)
		{
			array[i]=right[j];
		}
	}
	else
	{
		i=0;
		j=0;
		int k;
		for(k=0;k<length;k++)
		{
			if ((i<Nleft)&&(j<Nright))
			{
				if (left[i]<right[j])
				{
					array[k]=left[i];
					i++;
				}
				else
				{
					array[k]=right[j];
					j++;
				}
			}
			else
			{
				if (i==Nleft)
				{
					array[k]=right[j];
					j++;
				}
				else
				{
					array[k]=left[i];
					i++;
				}
			}
		}
	}
	return array;
}
#define LENGTH 100
int main(void)
{
	int a[LENGTH]={2,-2,5};//,3,7,1,9,6,8,0};
	int i;
	mergeSort(&a[0],LENGTH);
	for (i=0;i<LENGTH;i++)
		printf("a[%d]=%d\n",i+1,a[i]);
	return 0;
}
