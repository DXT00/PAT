

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
/*

//dfs超时了==！！
int N, M;
bool dfs(vector<int> &v, int i, vector<int> &s, int &sum){
	bool flag = false;
	sum += v[i];
	s.push_back(v[i]);
	if (sum>M)return false;
	else if (sum == M)return true;

	for (int j = i + 1; j <N; ++j)
	{
		flag = dfs(v, j, s, sum);
		if (flag)break;
		sum -= v[j];
		s.pop_back();
		if(flag==false&&sum+v[j]>M)break;
	}
	return flag;
}
void find(vector<int> &v){
	vector<int> s;
	bool flag = false;
	int sum = 0;
	for (int i = 0; i<N; i++){
		if(v[i]>M) break;
		sum = 0;
		flag = dfs(v, i, s, sum);
		if (flag)break;
		
	}
	if(flag==false){
		cout<<"No Solution"<<endl;
		return;
	}
	for (int i = 0; i <s.size(); ++i)
	{
		if(i!=s.size()-1)
			printf("%d ",s[i]);
		else
			printf("%d\n",s[i]);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &M);
	std::vector<int> v(N);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	find(v);
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