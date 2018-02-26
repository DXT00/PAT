#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#define inf 99999999

using namespace std;
int N,M,x,y,one,le,ti,S,D,Distance,Time;
std::vector<int> v[502];
int length[502][502];
int timee[502][502];
std::vector<int> res1,res2;
void Dijstra1(){//shortest

	std::vector<bool> visited(N,false);
	std::vector<int> dist(N,inf);
	std::vector<int> path(N,-1);
	std::vector<int> fast(N,inf);
	int min=S;
	visited[min]=true;
	dist[min]=0;
	fast[min]=0;
	while(true){

		for (int i = 0; i <v[min].size(); ++i)
		{
			int j=v[min][i];
			if(visited[j]==false){
				if(dist[min]+length[min][j]<dist[j]){
					dist[j]=dist[min]+length[min][j];
					fast[j]=fast[min]+timee[min][i];
					path[j]=min;
				}
				else if(dist[min]+length[min][j]==dist[j]){
					if(fast[min]+timee[min][j]<fast[j]){
						fast[j]=fast[min]+timee[min][i];
						path[j]=min;
					}
				}
			}
		}
		int MIN=inf,MIN_i;
		for (int i = 0; i <N; ++i){
			if(visited[i]==false){
				if(dist[i]<MIN){
					MIN=dist[i];
					MIN_i=i;
				}
			}
		}
		min=MIN_i;
		visited[min]=true;
		if(min==D)break;
	}
	int cur=D;
	while(cur!=-1){
		res1.push_back(cur);
		cur=path[cur];
	}
	Distance=dist[D];

}
void Dijstra2(){//shortest

	std::vector<bool> visited(N,false);
	std::vector<int> dist(N,inf);
	std::vector<int> path(N,-1);
	std::vector<int> cnt(N,inf);
	int min=S;
	visited[min]=true;
	dist[min]=0;
	cnt[min]=1;
	while(true){

		for (int i = 0; i <v[min].size(); ++i)
		{
			int j=v[min][i];
			if(visited[j]==false){
				if(dist[min]+timee[min][j]<dist[j]){
					dist[j]=dist[min]+timee[min][j];
					cnt[j]=1+cnt[min];
					path[j]=min;
				}
				else if(dist[min]+timee[min][j]==dist[j]){
					if(cnt[min]+1<cnt[j]){
						cnt[j]=1+cnt[min];
						path[j]=min;
					}
				}
			}
		}
		int MIN=inf,MIN_i;
		for (int i = 0; i <N; ++i){
			if(visited[i]==false){
				if(dist[i]<MIN){
					MIN=dist[i];
					MIN_i=i;
				}
			}
		}
		min=MIN_i;
		visited[min]=true;
		if(min==D)break;
	}
	int cur=D;
	while(cur!=-1){
		res2.push_back(cur);
		cur=path[cur];
	}
	Time=dist[D];
}
int main(int argc, char const *argv[])
{

	scanf("%d%d",&N,&M);
	for (int i = 0; i <M; ++i){
		scanf("%d%d%d%d%d",&x,&y,&one,&le,&ti);
		v[x].push_back(y);
		if(one==0){
			v[y].push_back(x);
		}
		length[x][y]=length[y][x]=le;
		timee[x][y]=timee[y][x]=ti;
	}
	scanf("%d%d",&S,&D);
	Dijstra1();
	Dijstra2();
	if(res1==res2){
		printf("Distance = %d; Time = %d: ",Distance,Time );
		for (int i = res1.size()-1; i>=0;i--){
			if(i!=res1.size()-1)printf(" -> ");
			printf("%d",res1[i]);
		}
	}
	else{
		printf("Distance = %d: ",Distance);
		for (int i = res1.size()-1; i>=0;i--){
			if(i!=res1.size()-1)printf(" -> ");
			printf("%d",res1[i]);
		}printf("\n");
		printf("Time = %d: ",Time);
		for (int i = res2.size()-1; i>=0;i--){
			if(i!=res2.size()-1)printf(" -> ");
			printf("%d",res2[i]);
		}//----------------->这里删了printf("\n")就没错了 = =！
	}

	system("pause");
	return 0;
}