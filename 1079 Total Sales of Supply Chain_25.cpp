#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int N,k,x;
double P,r,sum=0;
std::vector<int> v[100005];
std::vector<int> weight(100005);
void dfs(int x,double price){
	if(v[x].size()==0){//customers
		sum+=price*weight[x];
		return;
	}
	for (int i = 0; i <v[x].size(); ++i){
		dfs(v[x][i],(1+r*0.01)*price);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%lf%lf",&N,&P,&r);
	for (int i = 0; i <N; ++i){
		scanf("%d",&k);
		if(k==0){
			scanf("%d",&weight[i]);
		}
		for (int j = 0; j <k; ++j){
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	dfs(0,P);
	printf("%.1lf\n",sum);
	system("pause");
	return 0;
}
