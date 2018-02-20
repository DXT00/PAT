#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
struct Node{
	int id,perfect,sum,rank;
	vector<int>score;
	bool submit;
	Node():submit(false),perfect(0),sum(0){
		score.assign(6,-2);//-2表示没提交！
	}
};
int N,K,M,x,y,z;
int full[6];
vector<Node> v(10005),res;
bool cmp(Node a,Node b){
	if(a.sum!=b.sum)return a.sum>b.sum;
	else{
		if(a.perfect!=b.perfect)return a.perfect>b.perfect;
		else
			return a.id<b.id;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&K,&M);
	for (int i = 1; i <=K; ++i)
		scanf("%d",&full[i]);
	for (int i = 0; i <M; ++i){
		scanf("%d%d%d",&x,&y,&z);
		v[x].id=x;
		if(z>=0)v[x].submit=true;//>=0说明提交过编译通过~可以rank
		v[x].score[y]=max(v[x].score[y],z);
	}
	for (int i = 1; i <=N; ++i){//计算sum perfect
		if(v[i].submit){
			for (int j = 1; j <=K; ++j){
				v[i].sum+=(v[i].score[j]<0)?0:v[i].score[j];
				if(v[i].score[j]==full[j])v[i].perfect++;
			}
			res.push_back(v[i]);
		}
	}
	sort(res.begin(), res.end(),cmp);
	int cur;
	for (int i = 0; i <res.size(); ++i){
		if(i==0)res[i].rank=1;
		else{
			if(res[i].sum==res[i-1].sum)res[i].rank=res[i-1].rank;
			else res[i].rank=i+1;
		}
		printf("%d %05d %d",res[i].rank,res[i].id,res[i].sum);
		for (int j = 1; j <=K; ++j)
		{
			if(res[i].score[j]==-2)printf(" -");
			else if(res[i].score[j]==-1)printf(" 0");
			else printf(" %d",res[i].score[j] );
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
