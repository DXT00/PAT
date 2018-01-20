
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N,K,M,id,pro,sc,pre_sc;
std::vector<int> problem;

struct Node
{
	int id,sum,num;//num记录通过的题数
	bool pass;//记录是否有一题通过
	std::vector<int> score;//记录每题分数
	std::vector<int> full;//记录该题是否满分
	std::vector<bool> visited;//记录是否提交过该题
	Node():id(-1),sum(0),num(0),pass(false){
		score.assign(6,0);
		full.assign(6,0);
		visited.assign(6,false);
	}
};
std::vector<Node> v;
bool cmp(Node a,Node b){
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else{
		if(a.num!=b.num) return a.num>b.num;
		else{
			return a.id<b.id;
		}
	}
}
int main(int argc, char const *argv[])
{	scanf("%d%d%d",&N,&K,&M);
	problem.assign(K+1,0);
	v.assign(N+1,Node());
	int curs;
	for (int i = 1; i <=K; ++i)
		scanf("%d",&problem[i]);
	for (int i = 0; i <M; ++i)
	{
		scanf("%d%d%d",&id,&pro,&sc);
		
		v[id].id=id;
		v[id].visited[pro]=true;
		pre_sc=v[id].score[pro];
		v[id].sum-=pre_sc;
		if(sc!=-1){v[id].pass=true;}
		if(sc==-1){
			curs=0;
		}
		else
			curs=sc;
		
		v[id].score[pro]=max(v[id].score[pro],curs);
		if(v[id].score[pro]==problem[pro]&&v[id].full[pro]==0){v[id].num++;v[id].full[pro]++;}
		v[id].sum+=v[id].score[pro];
	}
	sort(v.begin(),v.end(),cmp);
	int rank=1;
	int cnt=0;
	int pre_sum=v[0].sum;
	for (int i = 0; i <v.size(); ++i)
	{
		if(v[i].id!=-1&&v[i].pass==true){
			cnt++;
			if(v[i].sum==pre_sum)
				printf("%d %05d %d",rank,v[i].id,v[i].sum);
			else{
				printf("%d %05d %d",cnt,v[i].id,v[i].sum);
				rank=cnt;
			}
			for (int j = 1; j <=K; ++j)
			{
				if(v[i].visited[j]==true)printf(" %d",v[i].score[j]);
				else printf(" -");
			}
			pre_sum=v[i].sum;
			printf("\n");
		}
	}
	getchar();
	system("pause");
	return 0;
}