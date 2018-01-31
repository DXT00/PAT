#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int N;
struct Node//记录family
{
	int num, set, total, root,Min;//Min记录一个家庭的最小id
	Node() :num(1), set(0), total(0), root(-1),Min(100000){}
};
std::vector<Node> v(10001);
set<int> s;
set<int>::iterator it;
int findRoot(int x){
	while (v[x].root != -1){
		x = v[x].root;
	}
	return x;
}
void Union(int a, int b){
	int root1, root2;
	root1 = findRoot(a);
	root2 = findRoot(b);
	v[root1].Min = min(v[root1].Min, a);
	v[root2].Min = min(v[root2].Min, b);
	if (root1 != root2){
		v[root2].root = root1;
		v[root1].num += v[root2].num;
		v[root1].set += v[root2].set;
		v[root1].total += v[root2].total;
		v[root1].Min = min(v[root1].Min, v[root2].Min);
	}
}
bool cmp(int a, int b){
	if ((double)(v[a].total*1.0 / v[a].num) != (double)(v[b].total*1.0 / v[b].num))
		return (double)(v[a].total*1.0 / v[a].num)>(double)(v[b].total*1.0 / v[b].num);
	else
		return v[a].Min<v[b].Min;//注意：排序是以每个家庭的最小值排序！
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	int root, me, father, mather, k, x, sett, totall;
	for (int i = 0; i <N; ++i)
	{
		scanf("%d%d%d", &me, &father, &mather);
		v[me].Min=min(me,v[me].Min);
		root = findRoot(me);
		v[root].Min = min(me, v[root].Min);
		if (father != -1)
			Union(root, father);
			
		if (mather != -1)
			Union(root, mather);
		
		scanf("%d", &k);
		for (int i = 0; i <k; ++i)
		{
			scanf("%d", &x);
			Union(root, x);	
		}
		scanf("%d%d", &sett, &totall);
		v[root].set += sett;
		v[root].total += totall;
		s.insert(root);
	}
	std::vector<int> res;
	for (it = s.begin(); it != s.end(); it++)
	{
		if (v[*it].root == -1)
		res.push_back(*it);
	}
	sort(res.begin(), res.end(), cmp);
	printf("%d\n", res.size());
	for (int i = 0; i <res.size(); ++i)
			printf("%04d %d %.3lf %.3lf\n", v[res[i]].Min, v[res[i]].num, (double)(v[res[i]].set*1.0 / v[res[i]].num), (double)(v[res[i]].total*1.0 / v[res[i]].num));
	system("pause");
	return 0;
}