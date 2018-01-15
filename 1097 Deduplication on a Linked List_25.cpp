#include <iostream>
#include <vector>
#include <stdio.h>
#include<algorithm>
using namespace std;
int start, N, addd, keyy, nextt, cur;
struct Node
{
	int add, key, next;
	Node(int add, int key, int next) :add(add), key(key), next(next){}
};
int main(int argc, char const *argv[])
{
	scanf("%d%d", &start, &N);
	std::vector<Node> origin(100002, Node(0, 0, 0));
	std::vector<int> m(100001, 0);
	std::vector<Node> v;
	std::vector<Node> remain;
	for (int i = 0; i <N; ++i)
	{
		scanf("%d%d%d", &addd, &keyy, &nextt);
		origin[addd].add = addd;
		origin[addd].key = keyy;
		origin[addd].next = nextt;
	}
	cur = start;
	for (int i = 0; cur!=-1&&i <N; ++i)//不要落了cur!=-1!!!!
	{
		m[abs(origin[cur].key)]++;
		if (m[abs(origin[cur].key)]>1)
			remain.push_back(origin[cur]);
		else
			v.push_back(origin[cur]);
		cur = origin[cur].next;
	}
	
	for (int i = 0; i+1<v.size(); ++i)
	{
			printf("%05d %d %05d\n", v[i].add, v[i].key, v[i+1].add);
	}
	if(v.size()>=1)
	printf("%05d %d %d\n", v[v.size()-1].add, v[v.size()-1].key, -1);

	for (int i = 0; i+1 <remain.size(); ++i)
	{
			printf("%05d %d %05d\n", remain[i].add, remain[i].key, remain[i+1].add);//这种题尽量不要改指针next,用下一个节点的address代替即可！！
	}
	if(remain.size()>=1)
	printf("%05d %d %d\n", remain[remain.size()-1].add, remain[remain.size()-1].key, -1);
	getchar();
	system("pause");
	return 0;
}
