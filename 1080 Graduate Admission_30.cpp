#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
int N,M,K,x,school;
std::vector<int> quota;
struct Node
{
	int GE,GI,num,rank;
	vector<int> choices;	
	Node(){}
};
std::vector<Node> v;
std::vector<int> cur;
std::vector<vector<int> > admit;
bool cmp(Node a,Node b){
	if(a.GE+a.GI!=b.GE+b.GI)return a.GE+a.GI>b.GE+b.GI;
	else return a.GE>b.GE;
}
bool cmp1(int a,int b){
	return v[a].num<v[b].num;
}
int main(int argc, char const *argv[])
{	
	scanf("%d%d%d",&N,&M,&K);
	quota.assign(M,0);
	v.assign(N,Node());
	admit.assign(M,cur);
	for (int i = 0; i <M; ++i)
	{
		scanf("%d",&quota[i]);
	}
	for (int i = 0; i <N; ++i)
	{
		scanf("%d%d",&v[i].GE,&v[i].GI);
		v[i].num=i;
		for (int j = 0; j <K; ++j)
		{
			scanf("%d",&x);
			v[i].choices.push_back(x);
		}
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i <v.size(); ++i)
	{
		//v[i].rank=i;
		for(int j=0;j<K;j++){
			school=v[i].choices[j];
			if(admit[school].size()<quota[school]){
				admit[school].push_back(i);
				break;
			}
			else{
				Node last=v[admit[school].back()];
				if(last.GE+last.GI==v[i].GE+v[i].GI&&last.GE==v[i].GE){
					admit[school].push_back(i);
					break;
				}
			}
		}
	}
	for (int i = 0; i <M; ++i)
	{
		sort(admit[i].begin(),admit[i].end(),cmp1);
		for (int j = 0; j <admit[i].size() ; ++j)
		{
			if(j==0)
				printf("%d",v[admit[i][j]].num);
			else{
				printf(" %d",v[admit[i][j]].num);
			}
		}
		printf("\n");
	}
	getchar();
	system("pause");
	return 0;
}