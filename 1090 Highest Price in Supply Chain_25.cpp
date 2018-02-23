#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int N,root,x,cnt=0;
double P,r,res=-1;
std::vector<int> v[100005];
void dfs(int root,double price){
	if(price>res){
		res=price;
		cnt=1;
	}
	else if(price==res){
		cnt++;
	}
	for (int i = 0; i <v[root].size(); ++i)
		dfs(v[root][i],price*(1+0.01*r));
}
int main(int argc, char const *argv[])
{
	scanf("%d%lf%lf",&N,&P,&r);
	for (int i = 0; i <N; ++i){
		scanf("%d",&x);
		if(x==-1)root=i;
		else
		v[x].push_back(i);
	}
	dfs(root,P);
	printf("%.2lf %d\n",res,cnt);
	system("pause");
	return 0;
}