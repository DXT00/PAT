#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;

int N,k,x,cnt=0;
double P,r,MIN=99999999;
std::vector<int> cur;
std::vector<vector<int> > v;
void dfs(int root,double price){
	if(v[root].size()==0){
		if(price<MIN){
			MIN=price;
			cnt=1;
		}
		else if(price==MIN){
			cnt++;
		}
	}
	for (int i = 0; i <v[root].size(); ++i)
		dfs(v[root][i],price*(1+0.01*r));
	
}
int main(int argc, char const *argv[])
{
	scanf("%d%lf%lf",&N,&P,&r);
	v.assign(N,cur);
	for (int i = 0; i <N; ++i){
		scanf("%d",&k);
		for (int j = 0; j <k; ++j){
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	dfs(0,P);
	printf("%.4lf %d\n",MIN,cnt);
	system("pause");
	return 0;
}
