#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Node
{
	long long id;
	int locate,score;
	int rank[2];//rank[0]local
};
int N,K;
vector<Node> v,res;
bool cmp(Node a,Node b){
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return a.id<b.id;
}
void RANK(vector<Node> &v,int x){
	v[0].rank[x]=1;
	for (int i = 1; i <v.size(); ++i){
		if(v[i].score==v[i-1].score)
			v[i].rank[x]=v[i-1].rank[x];
		else
			v[i].rank[x]=i+1;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 0; i <N; ++i){
		scanf("%d",&K);
		v.assign(K,Node());
		for (int j = 0; j <K; ++j){
			scanf("%lld%d",&v[j].id,&v[j].score);
			v[j].locate=i+1;
		}
		sort(v.begin(), v.end(),cmp);
		RANK(v,0);
		res.insert(res.end(),v.begin(), v.end());
	}
	sort(res.begin(), res.end(),cmp);
	RANK(res,1);
	printf("%d\n",res.size());
	for (int i = 0; i <res.size(); ++i){
		printf("%013lld %d %d %d\n",res[i].id,res[i].rank[1],res[i].locate,res[i].rank[0]);
	}
	                          
	system("pause");
	return 0;
}
