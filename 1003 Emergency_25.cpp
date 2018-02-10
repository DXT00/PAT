#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define inf 99999999
int N,M,C1,C2,x,y,le;
int team[502];
int len[502][502];
std::vector<int> v[502];
void Dijstra(int start,int endd){
	vector<bool> visited(N,false);
	vector<int> teams(N,0),num(N,0),dist(N,inf);
	int min=start;
	visited[min]=true;
	dist[min]=0;
	num[min]=1;
	teams[min]=team[min];
	while(true){
		for (int i = 0; i <v[min].size(); ++i){
			int j=v[min][i];
			if(visited[j]==false){
				if(dist[min]+len[min][j]<dist[j]){
					dist[j]=dist[min]+len[min][j];
					teams[j]=teams[min]+team[j];
					num[j]=num[min];
				}
				else if(dist[min]+len[min][j]==dist[j]){
					num[j]=num[j]+num[min];
					if(teams[min]+team[j]>teams[j]){
						teams[j]=teams[min]+team[j];		
					}
				}
			}
		}
		int MIN=inf,MIN_i;
		for (int i = 0; i <N; ++i){
			if(visited[i]==false&&dist[i]<MIN){
				MIN=dist[i];
				MIN_i=i;
			}
		}
		min=MIN_i;
		visited[min]=true;
		if(min==endd)break;
	}
	cout<<num[endd]<<" "<<teams[endd];
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	for (int i = 0; i <N; ++i)
		scanf("%d",&team[i]);
	for (int i = 0; i <M; ++i){
		scanf("%d%d%d",&x,&y,&le);
		v[x].push_back(y);
		v[y].push_back(x);
		len[x][y]=len[y][x]=le;
	}
	Dijstra(C1,C2);
	system("pause");
	return 0;
}
