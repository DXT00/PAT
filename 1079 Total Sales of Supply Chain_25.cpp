#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N,k,x;
double P,r,sum=0;
std::vector<int> cur;
std::vector<vector<int> > v;
void dfs(vector<vector<int> > &v,int root,double curP){
	if(v[root][0]==0){
		sum+=v[root][1]*curP;
		return;
	}
	else{
		for (int i = 0; i <v[root].size(); ++i)
		{
			dfs(v,v[root][i],curP*(1+r*0.01));
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%lf%lf",&N,&P,&r);	
	v.assign(N,cur);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d",&k);
		if(k==0){
			v[i].push_back(0);
			k=1;
		}
		for (int j = 0; j <k; ++j)
		{
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}

		dfs(v,0,P);
		printf("%.1lf\n", sum);
	




	getchar();
	system("pause");
	return 0;
}