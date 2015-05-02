#include<iostream>
#include<cctype>
using namespace std;

int N;
void output(int *x){
	for(int i=0;i<N;i++){
		cout<<x[i];
	}
	cout<<endl;
}

void backtrace(int m,int *x){
	if(m<N){
		x[m]=0;
		backtrace(m+1,x);
		x[m]=1;
		backtrace(m+1,x);
	}
	else{
		output(x);
	}
}

int main(){
	
	
	int a[20]={0};
	cout<<"输入递归深度N，非数字或0退出：";
	while(cin>>N && !(isalnum(N)||N==0)){
		backtrace(0,a);
		cout<<"输入N的值，非数字或0退出：";
	}

	system("pause");
	return 0;
}