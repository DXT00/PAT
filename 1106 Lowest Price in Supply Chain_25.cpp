#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, MIN_level, k,x;
double P, r, MIN = 10000000002.0;
std::vector<int> level(100002, 0);
void dfs(vector<vector<int> > &v, int root, int le, double price){
	if (v[root].size() == 0){
		level[le]++;
		if (price<MIN){
			MIN = price;
			MIN_level = le;
		}
		return;
	}
	for (int i = 0; i <v[root].size(); ++i)
		dfs(v, v[root][i], le + 1, price*(1 + 0.01*r));
}
int main(int argc, char const *argv[])
{
	scanf("%d%lf%lf", &N, &P, &r);
	std::vector<int> cur;
	std::vector<vector<int> > v(N, cur);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d", &k);
		for (int j = 0; j <k; ++j)
		{
			scanf("%d", &x);
			v[i].push_back(x);
		}
	}

	dfs(v, 0, 0, P);
	printf("%.4lf %d\n", MIN, level[MIN_level]);
	getchar();
	system("pause");
	return 0;
}