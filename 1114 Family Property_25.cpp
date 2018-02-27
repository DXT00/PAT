/*
统计集合个数有两种方法：
1、设置结构体，用一个num变量
2、用负数表示，但是若数不连续（如0~10000，只有其中的若干个如1111，2313，4432...），因为v[10000]初始化时全为-1，所以需要visited数组看哪些才是题目给出的数！

*/
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

/*
//第二次做的：
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <set>
using namespace std;
int N, me, father, mother, child, k,num1,total1;
int v[10000], total[10000], num[10000];
std::vector<int> res;
set<int> s;
int findRoot(int x){
	while (v[x] >= 0){
		x = v[x];
	}
	return x;
}
void Union(int a, int b){
	int roota = findRoot(a);
	int rootb = findRoot(b);
	
	if (roota != rootb){
		if (rootb<roota)
			swap(roota, rootb);

		v[roota] += v[rootb];
		v[rootb] = roota;

		total[roota] += total[rootb];
		total[rootb] = 0;

		num[roota] += num[rootb];
		num[rootb] = 0;

	}

}
bool cmp(int a, int b){
	if ((double)total[a] / (-v[a]) != (double)total[b] / (-v[b]))
		return (double)total[a] / (-v[a])>(double)total[b] / (-v[b]);
	else
		return a<b;
}
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	fill(v, v + 10000, -1);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d%d%d%d", &me, &father, &mother, &k);
		s.insert(me);
		vector<int> children(k);
		for (int i = 0; i <k; ++i){
			scanf("%d", &children[i]);
		}
		scanf("%d%d", &num1, &total1);

		if (father != -1){
			Union(me, father);
			s.insert(father);
		}
		if (mother != -1){
			Union(me, mother);
			s.insert(mother);
		}
		for (int i = 0; i <k; ++i){

			Union(me, children[i]);
			s.insert(children[i]);
		}
		int root = findRoot(me);//一行是一个家庭，重新找这个家庭的root,即最小i
		total[root] += total1;//把total1加进去
		num[root] += num1;//把num1加进去
	}
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++)//为了不遍历10000个数-->用了set
	{
		if (v[*it]<0){
			res.push_back(*it);
		}
	}
	printf("%d\n", res.size());
	sort(res.begin(), res.end(), cmp);
	for (int i = 0; i <res.size(); ++i)
	{
		
		printf("%04d %d %.3lf %.3lf\n", res[i], -v[res[i]], (double)num[res[i]] / (-v[res[i]]), (double)total[res[i]] / (-v[res[i]]));
	}
	system("pause");
	return 0;
}



*/
