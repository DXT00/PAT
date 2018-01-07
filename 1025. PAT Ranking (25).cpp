#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>



using namespace std;

struct Node
{
	string num;
	int score;
	int location;
	int local_rank;
	int total_rank;
	Node(string num,int score,int location):num(num),score(score),location(location),local_rank(0),total_rank(0){}
};
int N,K;
bool cmp(Node a,Node b){
	if(a.score!=b.score) return a.score>b.score;
	else
		return a.num<b.num;
}

void local_ranks(std::vector<Node> &v){
	int k=1;
	v[0].local_rank=k;
	for (int i = 1; i <v.size(); ++i)
	{
		if(v[i].score==v[i-1].score){
			v[i].local_rank=v[i-1].local_rank;
			k++;
		}
		else{
			k++;
			v[i].local_rank=k;
		}
	}
}
void total_ranks(std::vector<Node> &v){
	int k=1;
	v[0].total_rank=k;
	for (int i = 1; i <v.size(); ++i)
	{
		if(v[i].score==v[i-1].score){
			v[i].total_rank=v[i-1].total_rank;
			k++;
		}
		else{
			k++;
			v[i].total_rank=k;
		}
	}
}
int main(int argc, char const *argv[])
{
	cin>>N;
	std::vector<Node> v_total;
	int sum=0;
	for (int j = 0; j <N; ++j)
	{
		cin>>K;
		sum+=K;
		std::vector<Node> v_local(K,Node("",0,0));
		for (int i = 0; i <K; ++i)
		{
			string num;
			int score;
			cin>>num>>score;
			v_local[i].num=num;
			v_local[i].score=score;
			v_local[i].location=j+1;
			
		}
		sort(v_local.begin(), v_local.end(),cmp);
		local_ranks(v_local);
		for (int i = 0; i <v_local.size(); ++i)
		{
			v_total.push_back(v_local[i]);
		}


	}
	sort(v_total.begin(), v_total.end(),cmp);
	total_ranks(v_total);

	printf("%d\n",v_total.size());
	for (int i = 0; i <v_total.size(); ++i)
	{
		cout<<v_total[i].num;
		printf(" %d %d %d\n",v_total[i].total_rank,v_total[i].location,v_total[i].local_rank );
	}

	getchar();
	system("pause");
	return 0;
}