#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N, x, hobit;
vector<int> hobits[1002];
vector<int> v;
int findRoot(int x){
	while (v[x]>0){
		x = v[x];
	}
	return x;
}
void Union(int a, int b){
	int roota = findRoot(a);
	int rootb = findRoot(b);
	if (roota != rootb){
		v[roota] += v[rootb];//统计人数用负数如：-3  表示这组有3人！
		v[rootb] = roota;
	}
}
bool cmp(int a, int b){ return a>b; }
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	v.assign(N+1, -1);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d:", &x);
		for (int j = 0; j <x; ++j)
		{
			scanf("%d", &hobit);
			hobits[hobit].push_back(i);
		}
	}
	for (int i = 1; i <1002; ++i)
	{
		if (hobits[i].size()>0){
			vector<int> temp = hobits[i];
			int root = findRoot(temp[0]);
			for (int j = 1; j <temp.size(); ++j)
				Union(root, temp[j]);
		}
	}
	int group = 0;
	std::vector<int> res;
	for (int i = 1; i <= N; ++i)
	{
		if (v[i]<0){
			group++;
			res.push_back(-v[i]);
		}
	}
	sort(res.begin(), res.end(), cmp);
	cout << group << endl;
	for (int i = 0; i <res.size(); ++i)
	{
		if (i != 0)printf(" ");
		printf("%d", res[i]);
	}
	system("pause");
	return 0;
}