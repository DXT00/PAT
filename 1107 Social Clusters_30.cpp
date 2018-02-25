#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int N, k, x;
std::vector<int> hobby[1002];
std::vector<int> v;
int findRoot(int x){
	int cur = x;
	while (v[cur] >=0)
		cur = v[cur];
	return cur;
}
void Union(int a, int b){
	int roota = findRoot(a);
	int rootb = findRoot(b);
	if(roota!=rootb){
		v[roota] = v[roota] + v[rootb];////统计人数用负数如：-3  表示这组有3人！
		v[rootb] = roota;
	}
	
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	v.assign(N + 1, -1);
	for (int i = 1; i <= N; ++i){
		scanf("%d:", &k);
		for (int j = 0; j <k; ++j){
			scanf("%d", &x);
			hobby[x].push_back(i);
		}
	}
	int root, w;
	for (int i = 1; i < 1002; ++i)
	{
		if (hobby[i].size() != 0){
			vector<int> cur = hobby[i];
			for (int j = 1; j <cur.size(); ++j)
				Union(cur[0], cur[j]);		
		}
	}
	int cnt = 0;
	std::vector<int> res;
	for (int i = 1; i <= N; ++i)
	{
		if (v[i]<0){
			cnt++;
			res.push_back(v[i]);
		}
	}
	sort(res.begin(),res.end());
	printf("%d\n", cnt);
	for (int i=0;i<res.size();i++)
	{
		if (i!=0)printf(" ");
		printf("%d", -res[i]);
	}
	system("pause");
	return 0;
}
