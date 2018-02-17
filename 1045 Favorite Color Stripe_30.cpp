#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std; 
int N,M,K,x;
vector<int> pos(202,0);
vector<int> v;
std::vector<int> dp;
int main(int argc, char const *argv[])
{	
	scanf("%d%d",&N,&M);//N种颜色
	for (int i = 1; i <=M; ++i)
	{
		scanf("%d",&x);
		pos[x]=i;
	}
	scanf("%d",&K);
	for (int i = 0; i <K; ++i){
		scanf("%d",&x);
		if(pos[x]>0){
			v.push_back(pos[x]);
		}
	}
	int size=v.size();

	dp.assign(size,0);

	int MAX=0;
	for (int i = 0; i <size; ++i){
		dp[i]=1;
		for (int j = 0; j <i; ++j){
			if(v[i]>=v[j]){
				dp[i]=max(dp[i],dp[j]+1);			
			}
		}
		MAX=max(dp[i],MAX);
	}
	cout<<MAX<<endl;
	system("pause");
	return 0;
}