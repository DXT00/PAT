#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
bool visited[1000000];
struct Node{
	int id, A, C, M, E;
};
char m[4] = { 'A', 'C', 'M', 'E' };
int N, K, q;
int res[1000000][4];
bool cmp1(Node a, Node b){ return a.A>b.A; }
bool cmp2(Node a, Node b){ return a.C>b.C; }
bool cmp3(Node a, Node b){ return a.M>b.M; }
bool cmp4(Node a, Node b){ return a.E>b.E; }
void Rank(vector<Node> v, int k){
	int r = -1, pre, cur;

	for (int i = 0; i <N; ++i){

		if (k == 0)cur = v[i].A;
		else if (k == 1)cur = v[i].C;
		else if (k == 2)cur = v[i].M;
		else cur = v[i].E;
		
		if (i == 0)
			res[v[i].id][k] = 1;
		else{
			if (cur == pre)res[v[i].id][k] = res[v[i - 1].id][k];
			else
				res[v[i].id][k] = i + 1;
		}
		pre = cur;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &K);
	vector<Node> v(N, Node());
	for (int i = 0; i <N; ++i){
		scanf("%d%d%d%d", &v[i].id, &v[i].C, &v[i].M, &v[i].E);
		v[i].A = (v[i].C + v[i].M + v[i].E) / 3;
		visited[v[i].id] = true;
	}
	sort(v.begin(), v.end(), cmp1);Rank(v, 0);	
	sort(v.begin(), v.end(), cmp2);Rank(v, 1);	
	sort(v.begin(), v.end(), cmp3);Rank(v, 2);	
	sort(v.begin(), v.end(), cmp4);Rank(v, 3);
	
	for (int i = 0; i <K; ++i){
		scanf("%d", &q);
		int MIN = 99999999, MIN_i;
		if (visited[q] == false)printf("N/A\n");
		else{
			for (int j = 0; j <4; ++j){
				if (res[q][j]<MIN){
					MIN = res[q][j];
					MIN_i = j;
				}
			}
			printf("%d %c\n", MIN, m[MIN_i]);
		}
	}
	system("pause");
	return 0;
}