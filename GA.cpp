#include<iostream>
#include<algorithm>
#define L 5
#define MATE ((L/2)+1)
#define LOW(xy) ((xy) & ((int)pow(2.0,MATE)-1))
#define HIGH(xy) ((xy) - LOW(xy))
#define POW (pow(2.0,L)-1.0)
using namespace std;

const int T=200;
const int SIZE=10000;

struct grp{
		double x;
		double y;
		
		double adj;
		double pr;
		double e;
		int count;
		double remain;
		double delta_e;
};
struct grp ga[SIZE] = {0};
static int orderDec[SIZE];


void init(){
	for(int i=0;i<SIZE;i++){
		ga[i].x=rand()%((int)POW);
		ga[i].y=rand()%((int)POW);
		//ga[i].x = 1.0 + ga[i].x/POW;
		//ga[i].y = 1.0 + ga[i].x/POW;
	}
}


double f(double x,double y){
	return x*sin(6*y)+y*cos(8*x);
}


void procal(){

	double total = 0, x, y, min = ga[0].adj;
	int i,j;
	int cal = 0;

	for(i=0; i<SIZE; i++)
	{
		x = 1.0 + ga[i].x/POW;
		y = 1.0 + ga[i].y/POW;
		ga[i].adj =f(x,y);
		if(min > ga[i].adj)
			min = ga[i].adj;
		total += ga[i].adj;
	}

	total += SIZE * fabs(min);
	
	for(j=0; j<SIZE; j++)
	{
		ga[j].e = ((ga[j].adj + fabs(min))/total) * SIZE;

		ga[j].count = ((int)(ga[j].e * 2)) / 2;

		ga[j].delta_e = (double)ga[j].count - ga[j].e;

		cal += ga[j].count;
		
	}

	if(cal < SIZE)
	{
		int c = SIZE - cal;

		int i;
		for(i=0 ; c; i++)
		{
			ga[orderDec[i]].count++;
			c--;
		}
		
	}
}


void getnextgeneration(){
	double tx[SIZE]={0.0},ty[SIZE]={0.0};
	int count=0;
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<ga[i].count;j++){
			tx[j]=ga[i].x;
			ty[j]=ga[i].y;
			count++;
		}	
	}

	for(int i=count;i<SIZE;i++){
		int j;
		for(j=SIZE-1;j>=0;j--){
			if(ga[j].remain<ga[j-1].remain){
				swap(ga[j],ga[j+1]);
			}
		}
		ga[SIZE-1-j].count++;
	}
}

void crossover(){
	for(int i=0;i<SIZE;i+=2){
		int lx,ly;
		lx = LOW((int)ga[i].x);
		ga[i].x = HIGH((int)ga[i].x) + LOW((int)ga[i+1].x);
		ga[i+1].x = HIGH((int)ga[i+1].x) + lx;
		
		ly = LOW((int)ga[i].y);
		ga[i].y = HIGH((int)ga[i].y) + LOW((int)ga[i+1].y);
		ga[i+1].y = HIGH((int)ga[i+1].y) + ly;
	}
}


void printmax(){
	double max=ga[0].adj;
	int index=0;
	for(int i=0;i<SIZE;i++){
		if(ga[i].adj>max){
			max=ga[i].adj;
			index=i;
		}
	}
	double x = 1.0 + ga[index].x/POW;
	double y = 1.0 + ga[index].y/POW;
//	max=max/POW;
//	max=f(x,y);
	cout<<"函数f(x,y)=xsin(6y)+ycos(8x)的极值为："<<max<<"坐标为x="<<x<<" y="<<y<<endl;
//	cout<<"函数f(x,y)=xsin(6y)+ycos(8x)的极值为："<<max<<"坐标为x="<<ga[index].x<<" y="<<ga[index].y<<endl;
}

int main(){
	init();
	for(int i=0;i<T;i++){
		procal();
		getnextgeneration();
		crossover();
	}
	printmax();

	system("pause");
	return 0;
}