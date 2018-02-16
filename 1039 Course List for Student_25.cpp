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

/*
用char数组不会超时，用string超时！！
先把char[]映射成整数！

*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
using namespace std;
int K, N, index, num;
std::map<int, set<int> > m;
int change(char s[6]){
	int res=0;
	for (int i = 0; i < 3; ++i)
		res+=(s[i]-'A')*pow(26,2-i);
	
	res=res*10+(s[3]-'0');
	return res;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d", &K, &N);
	for (int i = 0; i <N; ++i){
		scanf("%d%d", &index, &num);
		getchar();		//记得要getchar()!!
		for (int j = 0; j <num; ++j){
			char na[6];
			scanf("%s", na);
			m[change(na)].insert(index);
		}
	}
	for (int i = 0; i <K; ++i){
		char na[6];
		scanf("%s", na);
		printf("%s %d", na, m[change(na)].size());
		set<int>::iterator it;
		for (it = m[change(na)].begin(); it != m[change(na)].end(); it++)
			printf(" %d", *it);
		
		printf("\n");
	}
	system("pause");
	return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <stdio.h>
// #include <map>
// #include <string>
// #include <math.h>
// using namespace std;
// int N, K;
// int getid(char name[4]){
// 	int id=0;
// 	for (int i = 0; i <3; ++i)
// 	{
// 		id+=(name[i]-'A')*pow(26,2-i);
// 	}
// 	id=id*10+name[3]-'0';
// 	return id;
// }
// int main(int argc, char const *argv[])
// {
// 	cin >> N >> K;
// 	int course, num;
	
// 	string sn;
// 	std::vector<int> cur;
// 	std::vector<vector<int> > m(200000,cur);
// 	for (int i = 0; i <K; ++i)
// 	{
// 		scanf("%d %d ", &course, &num);
// 		for (int i = 0; i <num; ++i)
// 		{
			
// 			char name[4];
// 			scanf("%s",name);
// 			int id=getid(name);
// 			m[id].push_back(course);
// 		}
// 	}
// 	for (int i = 0; i <N; ++i)
// 	{
// 		char name[4];
// 		scanf("%s", name);
// 		int qid=getid(name);
// 		sort(m[qid].begin(), m[qid].end());	//这里还可以用set!
// 		printf("%s %d", name, m[qid].size());
// 		for (int j = 0; j <m[qid].size(); ++j)
// 		{
// 			printf(" %d", m[qid][j]);
// 		}
// 		printf("\n");
// 	}
// 	system("pause");
// 	return 0;
// }
