const int INF=0x7fffffff/100;

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[1001][1001]={0};
int d[1001]={0},N,M,X;
int dd[1001]={0};
bool f[1001];

void Dijstra()
{
	for(int i=1; i<=N; i++)
		d[i]=INF;
	d[X]=0;
	memset(f,0,sizeof f);
	for(int i=1; i<=N; i++){
		int min=INF,u=0;
		for(int j=1; j<=N; j++)
			if(d[j]<min&&!f[j]){
				min=d[j];
					u=j;
			}
		f[u]=true;
		for(int j=1; j<=N; j++){
			if(d[u]+map[u][j]<d[j])
			d[j]=d[u]+map[u][j];
		}
	}
}

void Inverse()
{
	int temp;

	for(int i=1; i<=N; i++){
		for(int j=1; j<i; j++){
			temp = map[i][j];
			map[i][j]=map[j][i];
			map[j][i]=temp;
		}
	}
}

int main()
{

	cin>>N>>M>>X;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
		    map[i][j]=INF;
	for(int i=1,s,t,value; i<=M; i++){
		  cin>>s>>t>>value;
		  map[s][t]=value;
	}
	Dijstra();
	for(int i=1; i<=N; i++)
		dd[i]=d[i];
	Inverse();
	Dijstra();
	int max=0;
	for(int i=1; i<=N; i++)
		if(d[i]+dd[i]>max)
			max=d[i]+dd[i];
	cout<<max<<endl;

	return 0;
}
