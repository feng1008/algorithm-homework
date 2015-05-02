#include<iostream>
using namespace std;

int *a=new int[100];

void print(int m) 
{ 
	int i; 
	for(i=0;i<=m-1;i++) 
		cout<<a[i]<<" ";
	cout<<endl;
} 
void split(int n,int m) 
{ 
	int i; 
	if(n==0) print(m); 
	else{ 
		for(i=n;i>=1;i--) 
			if(m==0||i<=a[m-1]) 
			{
				a[m]=i;
				split(n-i,m+1);
			} 		
	}
} 
int main() 
{
	const int n=6;
	int m=0;
	split(n,m); 
	return 0;
}