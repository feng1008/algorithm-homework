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
	cout<<"����ݹ����N�������ֻ�0�˳���";
	while(cin>>N && !(isalnum(N)||N==0)){
		backtrace(0,a);
		cout<<"����N��ֵ�������ֻ�0�˳���";
	}

	system("pause");
	return 0;
}