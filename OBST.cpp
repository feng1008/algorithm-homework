#include<iostream>
using namespace std;

void Optimal_BST(double *p,double *q,int length,double (*e)[20],int (*root)[20])
{
	int i,j,k,r;
	double t;
	double w[20][20]={0};
	for(i=1;i<=length+1;i++)
	{
		e[i][i-1]=q[i-1];
		w[i][i-1]=q[i-1];
	}
	//i为关键字之间的长度
	for(i=1;i<=length;i++)
	{
		//从下标为j开始的关键字到下标为k的关键字
		for(j=1;j<=length-i+1;j++)
		{
			k=i+j-1;
			e[j][k]=0x7fffffff;
			w[j][k]=w[j][k-1]+p[k]+q[k];
			//选取j到k之间的某个下标的关键字作为从j到k的根，如果组成的树的期望值当前最小，则r为从j
			//到k的根节点
			for(r=j;r<=k;r++)
			{
				t=e[j][r-1]+e[r+1][k]+w[j][k];
				if(e[j][k]>t)
				{
					e[j][k]=t;
					//r即为从下标j到k的根节点
					root[j][k]=r;
				}
			}
		}
	}
}
void Construct_Optimal_BST(int (*root)[20],int i,int j,bool flag)
{
	
	if(flag==0)
	{
		cout<<"k"<<root[i][j]<<"(";
		flag=1;
	}
	int r=root[i][j];

	//如果左子树是叶子
	if(r-1<i)
	{
		cout<<"d"<<r-1;
	}

	//如果左子树不是叶子
	else
	{
		cout<<"k"<<root[i][r-1]<<"(";
		Construct_Optimal_BST(root,i,r-1,1);
	}

	//如果右子树是叶子
	if(r>=j)
	{
		cout<<","<<"d"<<j<<")";
	}

	//如果右子树不是叶子
	else
	{
		cout<<","<<"k"<<root[r+1][j]<<"(";
		Construct_Optimal_BST(root,r+1,j,1);
		cout<<")";
	}
}
int main()
{
	const int N=8;
	double p[N]={0.00,0.04,0.06,0.08,0.02,0.10,0.12,0.14};
	double q[N]={0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05};
	double e[20][20]={0};
	int root[20][20]={0};
	Optimal_BST(p,q,N,e,root);
	cout<<"The shortest path length is "<<e[1][N-1]<<endl;
	cout<<"The tree is :";
	Construct_Optimal_BST(root,1,N-1,0);
	cout<<endl;
	system("pause");
	return 0;
}
