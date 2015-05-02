#include <stdio.h>
void initAscSort(int* a,int n)
{
	for(int i=1;i<n;i++)
	{
		int tmp = a[i],j;
		for(j=i-1;j>=0;j--)
		{
			if(tmp<a[j])
			{
				a[j+1] = a[j];
			}else
			{
				break;
			}
		}
		a[j+1] = tmp;
	}
}
void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void reverse(int* arr,int i,int j)
{
	while(i<j)
	{
		swap(arr+i,arr+j);
		i++;
		j--;
	}
}
void print(int* x,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d",x[i]);
	}
	printf("\n");
}
int fullSort(int* arr,int n)
{
	int i,j;
	if(n==1)
		return 1;
	
	while(1)
	{
		print(arr,n);
		for(i=n-2;i>=0;i--)
		{
			if(arr[i]<arr[i+1])
				break;
			if(i==0)
				return 1;
		}

		for(j=n-1;j>i;j--)
		{
			if(arr[j]>arr[i])
				break;
		}
		swap(arr+i,arr+j);
		reverse(arr,i+1,n-1);
	}
}
int main()
{
	int arr[4]={3,4,2,1};
	
	initAscSort(arr,4);
	fullSort(arr,4);
	
//	print(arr,4);
	return 0;
}