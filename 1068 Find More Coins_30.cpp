

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
/*

//dfs超时了==！！
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
std::vector<int>res;
int N, M;
std::vector<int> v;

bool cmp(vector<int>a,vector<int>b){
	return a<b;
}
bool flag=false;
void dfs(int x,int sum,vector<int>path){
	if(sum>M)return;
	if(sum==M){
		res=path;
		flag=true;
		return;
	}
	for (int i = x+1; i <N; ++i)
	{
		path.push_back(v[i]);
		dfs(i,sum+v[i],path);
		if(flag)return;
		path.pop_back();
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	v.assign(N,0);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());

	vector<int>path;
	for (int i = 0; i <v.size(); ++i)
	{
		if(v[i]>M)break;
		path.push_back(v[i]);
		dfs(i,v[i],path);
		if(flag)break;
		path.pop_back();
	}
	if(res.size()==0){
		printf("No Solution\n");
	}
	else{
		for (int i = 0; i <res.size(); ++i)
		{
			if(i!=0)printf(" ");
			printf("%d",res[i]);
		}
	}
	

	getchar();
	system("pause");
	return 0;
}

*/
int N,M;
void find(std::vector<int> &v){
	std::vector<int> dp(M+1,0);
	std::vector<bool> cur(M+1,false);
	std::vector<vector<bool> > path(N,cur);
	std::vector<int> res;
	for (int i = 0; i < N; ++i)
	{
		for (int j = M; j>=v[i]&&j>=1;j--)
		{
			if(dp[j]<=dp[j-v[i]]+v[i]){
				dp[j]=dp[j-v[i]]+v[i];
				path[i][j]=true;
			}
		}
	}
	if(dp[M]!=M){
		cout<<"No Solution"<<endl;
	}
	else{
	
		int endd=M;
		int beginn=N-1;
		while(endd>0){
			if(path[beginn][endd]==true){
				res.push_back(v[beginn]);
				endd=endd-v[beginn];
			}
			beginn--;
		}
	}
	for (int i = 0; i <res.size(); ++i)
	{
		if(i!=res.size()-1)
			printf("%d ",res[i]);
		else
			printf("%d\n",res[i]);
	}
		
}
bool cmp(int a,int b){
	return a>b;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	std::vector<int> v(N);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d",&v[i]);
	}
	sort(v.begin(), v.end(),cmp);
	find(v);
	getchar();
	system("pause");
	return 0;
}
