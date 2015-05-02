#include <stdio.h>
#include <stdlib.h>
#define N 6
#define M N+1

void MatrixChain(int* p,int n,int m[M][M],int s[M][M])
{
	for(int i=1;i<=n;i++) m[i][i] = 0;
	for(int r=2;r<=n;r++)
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
}

void Traceback(int i,int j,int s[M][M],int k[M][M])
{
	if(i==j) 
		return;

	Traceback(i,s[i][j],s,k);
	Traceback(s[i][j]+1,j,s,k);
	//�����ű�־��ӵ���¼����,1���������ţ�2����������
	k[i][s[i][j]] = 1;
	k[s[i][j]][i] = 2;
	k[s[i][j]+1][j] = 1;
	k[j][s[i][j]+1] = 2;

}

void printStr(int k[M][M])//��ӡ��д�뵽output.txt�ļ���
{
	FILE* fp_w;
	
	if((fp_w=fopen("output.txt","w")) == NULL )
	{
		printf("Open file failure!\n");
	}
	fprintf(fp_w,"�õ��������˵����ż�������ǣ�\n");
	
	printf("�õ��������˵����ż�������ǣ�");
	for(int i=1;i<M;i++)//����ɨ��k��
	{
		for(int j1=i+1;j1<=M;j1++)
		{
			if(k[i][j1]==1)
			{
				printf("(");
				fprintf(fp_w,"(");
			}
		}
		printf("A%d",i);
		fprintf(fp_w,"A%d",i);
		for(int j2=1;j2<i;j2++)
		{
			if(k[i][j2]==2)
			{
				printf(")");
				fprintf(fp_w,")");
			}
		}
	}
	fprintf(fp_w,"\n");
	printf("\n");
	fclose(fp_w);
}
void print(int k[M][M])
{
	for(int i1=1;i1<M;i1++)
		k[i1][i1] = 0;
	for(int i=1;i<M;i++)
	{
		for(int j=1;j<M;j++)
			printf("%-3d",k[i][j]);
		printf("\n");
	}
}

void readData(int* p)
{
	FILE* fp_r;
	if ((fp_r=fopen("input.txt","r"))==NULL)
    {
        printf("Open file failure!/n");
    }
	//���ļ��е���ֵ���뵽������
	for(int i=0;fscanf(fp_r,"%d",&p[i])!=-1;i++);
	//�ر��ļ���
	fclose(fp_r);
}
void main()
{
	int p[M]={0},s[M][M]={0},m[M][M]={0},k[M][M]={0};

	//���ļ��ж�������
	readData(p);
	
	MatrixChain(p,N,m,s);
	Traceback(1,N,s,k);
//	print(k);
	printStr(k);
}