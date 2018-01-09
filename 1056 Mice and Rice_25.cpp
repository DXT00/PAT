#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
//-----------------------------
//用队列
// 可以分为group组
// 每组选一个
// 则剩下的老鼠排名=group+1
//注意：不要漏了Np<Ng的情形！
//------------------------------
struct Node
{
	int weight;
	int rank;
	int th;//记录第几只老鼠
	Node(){}
};
int Np, Ng;
std::vector<Node> v;

int main(int argc, char const *argv[])
{
	queue<Node> q;
	scanf("%d%d", &Np, &Ng);
	v.assign(Np, Node());
	for (int i = 0; i < Np; ++i)
	{
		scanf("%d", &v[i].weight);
		v[i].th = i;
	}
	//ranking
	int group = ceil((double)Np / Ng);//ceil向上取整

	int g_rank = group + 1;
	int Max = -1, Max_i = -1;
	int seq;
	for (int i = 0; i < Np; ++i)
	{
		if (i != 0 && i%Ng == 0){
			q.push(v[Max_i]);
			Max = -1; Max_i = -1;
		}
		scanf("%d", &seq);
		v[seq].rank = g_rank;

		if (v[seq].weight>Max){
			Max = v[seq].weight;
			Max_i = seq;
		}

	}
	q.push(v[Max_i]);
	
	int q_size = q.size();
	group = ceil((double)group / Ng);
	g_rank = group + 1;
	Max = -1;
	Max_i = -1;
	int ii = 0;
	while (!q.empty()){
		Node w = q.front();
		q.pop();
		ii++;
		if (q_size == 1){ v[w.th].rank = 1; break; }//只剩下一个时，rank=1
		v[w.th].rank = g_rank;
		if (w.weight>Max){ Max = w.weight; Max_i = w.th; }
		if (ii%Ng == 0 && ii<q_size){ q.push(v[Max_i]); Max = -1; Max_i = -1; }
		if (ii == q_size&&q_size != 1){
			q.push(v[Max_i]);
			Max = -1;
			Max_i = -1;
			q_size = q.size();
			ii = 0;
			group = ceil((double)group / Ng);
			g_rank = group + 1;
		}
	}
	for (int i = 0; i <Np; ++i)
	{
		if(i!=Np-1)
		cout << v[i].rank << " ";
		else
			cout << v[i].rank <<endl;
	}
	getchar();
	system("pause");
	return 0;
}

