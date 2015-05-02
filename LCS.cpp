#include<iostream>
#include<fstream>
using namespace std;
const int N=20;
char s[N]={'\0'};
void LCSLength(int m,int n,char* x,char* y,int c[N][N],int b[N][N])
{
	int i,j;
	for(i=1;i<=m;i++)
		c[i][0] = 0;
	for(i=1;i<=n;i++)
		c[0][i] = 0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j-1];
				b[i][j] = 3;
			}
		}

}
void LCS(int i,int j,char* x,int b[N][N],int &len)
{
	
	if(i==0 || j==0) return;
	if(b[i][j]==1)
	{
		char ch=x[i-1];
//		cout<<x[i-1];
		s[len++]=x[i-1];
		LCS(i-1,j-1,x,b,len);
	}else if(b[i][j]==2){
		LCS(i-1,j,x,b,len);
	}
	else if(b[i][j]=3){
		LCS(i,j-1,x,b,len);
	}
	
}

void read(char* x,char* y,int* pm,int* pn)
{

    ifstream in("input.txt");

    if (!in)
    {
        cerr<<"error:can not open file:input.txt"<<endl;
		return ;
    }
	cout<<"字符串x为：";
	for(int m=0;(x[m]=in.get())!=-1&&x[m]!='\n';m++)
	{
		if(x[m]==' ')
		{
			m--;
			continue;
		}
		(*pm)++;
		cout<<x[m];
	}
	cout<<endl;
	cout<<"字符串y为：";
	for(int n=0;(y[n]=in.get())!=-1&&y[n]!='\n';n++)
	{
		if(y[n]==' ')
		{
			n--;
			continue;
		}
		(*pn)++;
		cout<<y[n];
	}
    in.close();
    in.clear();
}
void writeData(char s[])
{
	int i=0,len=0;
	while(s[i++]!='\0'){
		len++;
	}
	ofstream outfile;
	outfile.open("output.txt");
	if(!outfile){
		cerr<<"error:can not open file:"<<outfile<<endl;
		return ;
	}
	outfile<<"最长公共子串为：";
	for(i=len-1;i>=0;i--){
		outfile.put(s[i]);
		cout<<s[i];
	}
	outfile.close();
}
int main(){	
	char x[20],y[20];
	
	
	int b[N][N]={0},c[N][N]={0};
	int m=0,n=0,len=0;
	read(x,y,&m,&n);
	cout<<endl;
	LCSLength(m,n,x,y,b,c);
	cout<<"最长公共子串为：";
	LCS(m,n,x,c,len);
	writeData(s);
	cout<<endl;
	system("pause");
	return 0;
}