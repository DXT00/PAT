/*
字符串处理超时的话，就映射成int!
A->0
B->1
..
Z->25
所以可以采用26进制！
最后的数字0-9采用10进制！
ZOE1=((Z-A)*26^2+(O-A)*26^1+(E-A)*26^0)*10+1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
using namespace std;
int N, K;
int getid(char name[4]){
	int id=0;
	for (int i = 0; i <3; ++i)
	{
		id+=(name[i]-'A')*pow(26,2-i);
	}
	id=id*10+name[3]-'0';
	return id;
}
int main(int argc, char const *argv[])
{
	cin >> N >> K;
	int course, num;
	
	string sn;
	std::vector<int> cur;
	std::vector<vector<int> > m(200000,cur);
	for (int i = 0; i <K; ++i)
	{
		scanf("%d %d ", &course, &num);
		for (int i = 0; i <num; ++i)
		{
			
			char name[4];
			scanf("%s",name);
			int id=getid(name);
			m[id].push_back(course);
		}
	}
	for (int i = 0; i <N; ++i)
	{
		char name[4];
		scanf("%s", name);
		int qid=getid(name);
		sort(m[qid].begin(), m[qid].end());
		printf("%s %d", name, m[qid].size());
		for (int j = 0; j <m[qid].size(); ++j)
		{
			printf(" %d", m[qid][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}