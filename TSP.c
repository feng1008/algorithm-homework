#include <stdio.h>
#define N 100

typedef struct node{
	int num,sum;
}node;

node s[N+10];
int m[N+10][N+10],used[N+10],a[N+10],ans[N+10],bound;

int firstans(int n){
    int i,j,sum=0,k,t;
    for(i=1;i<=n;++i){
        used[i]=0;
    }
    t=1;
    used[t]=1;
	ans[0]=t;
    for(i=1;i<n;++i){
        for(j=1;j<=n;++j){
            if(used[j]!=1){
                k=j;
                break;
            }
        }
        for(;j<=n;++j){
            if(used[j]!=1&&m[t][j]<m[t][k]){
                k=j;
            }
        }
        used[k]=1;
        sum+=m[t][k];
        t=k;
		ans[i]=t;
    }
    sum+=m[t][1];
    return sum;
}

void deepsearch(int first,int k,int now,int n){
    int i;
    if(k==n){
        if((now+m[first][s[1].num])<bound){
            bound=now+m[first][s[1].num];
			for(i=0;i<n;++i) ans[i]=a[i];
        }
		return;
    }
    for(i=1;i<=n;++i){
       if(used[i]==1) continue;
       else{
           if((now+m[first][i])<bound){
               used[i]=1;
			   a[k]=i;
               deepsearch(i,k+1,now+m[first][i],n);
               used[i]=0;   
           }
       }
    }
}

int main(){
	int i,j,n;
	node t;
	FILE *fr,*fw;
	fr=fopen("read.txt","r");
	fw=fopen("write.txt","w");
	if(fscanf(fr,"%d",&n)!=EOF){
		for(i=1;i<=n;++i){
			s[i].num=i;
			for(j=1;j<=n;++j){
				fscanf(fr,"%d",&m[i][j]);
				s[i].sum+=m[i][j];
			}
		}
		bound=firstans(n);
		for(i=2;i<=n;++i){
			for(j=i;j>1;--j){
				if(s[j].sum>s[j-1].sum){
					t.num=s[j].num;
					t.sum=s[j].sum;
					s[j].num=s[j-1].num;
					s[j].sum=s[j-1].sum;
					s[j-1].num=t.num;
					s[j-1].sum=t.sum;
				}
			}
		}
        for(i=1;i<=n;++i) used[i]=0;
		used[s[1].num]=1;
		a[0]=s[1].num;
		deepsearch(s[1].num,1,0,n);
		for(i=0;i<n;++i){
			if(ans[i]==1) break; 
		}
		for(j=1;j<=n;++j){
			fprintf(fw,"%d->",ans[i%n]);
			printf("%d->",ans[i%n]);
			++i;
		}
		printf("1\n");
		fprintf(fw,"1\n");
		fprintf(fw,"最短距离为：%d",bound);
		printf("最短距离为：%d",bound);
	}
	printf("\n");
	fclose(fr);
	fclose(fw);
	return 0;
}

