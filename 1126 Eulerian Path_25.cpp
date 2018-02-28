#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N,M,x,y,odd=0,even=0;
bool flag;
int v[502][502];
int degree[502];
int visited[502];
void dfs(int x){
	for (int i = 1; i <=N; ++i)
	{
		if(v[x][i]==1&&visited[i]==0){
			visited[i]=1;
			dfs(i);
		}

	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for (int i = 0; i <M; ++i){
		scanf("%d%d",&x,&y);
		degree[x]++;
		degree[y]++;
		v[x][y]=v[y][x]=1;
	}
	int cnt=0;
	for (int i = 1; i <=N; ++i)
	{
		if(visited[i]==0){
			visited[i]=1;
			dfs(i);
			cnt++;
		}
		
	}
	if(cnt==1)flag=true;
	else
		flag=false;
	for (int i = 1; i <=N; ++i)
	{
		if(i!=1)printf(" ");
		printf("%d",degree[i]);
		if(degree[i]%2==0)even++;
		else
			odd++;
	}
	printf("\n");
	if(flag&&odd==0&&even==N)
		printf("Eulerian\n");
	else if(flag&&odd==2&&even==N-2)
		printf("Semi-Eulerian\n");
	else
		printf("Non-Eulerian\n");
	system("pause");
	return 0;
}