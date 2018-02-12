#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
int N, x, M;
string str;
vector<map<string, set<int> > > m(6);//1~5分别对应title, author, keywords, publisher, year
int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	for (int i = 0; i <N; ++i){
		scanf("%d", &x);
		getchar();
		for (int k = 1; k <= 5; ++k)
		{
			getline(cin, str);
			if (k != 3)
				m[k][str].insert(x);
			else{
				int pre_j = 0, j;
				for (j = 0; j <str.size(); ++j){
					if (str[j] == ' '){
						m[k][str.substr(pre_j, j - pre_j)].insert(x);
						pre_j = j + 1;
					}
				}m[k][str.substr(pre_j, j - pre_j)].insert(x);
			}
		}

	}
	scanf("%d", &M);
	getchar();
	map<string, set<int> >::iterator it;
	for (int i = 0; i <M; ++i){
		getline(cin, str);
		cout << str << endl;
		int index = str[0] - '0';
		string s = str.substr(3);
		it = m[index].find(s);
		if (it != m[index].end()){
			set<int> cur = it->second;
			set<int>::iterator sit;
			for (sit = cur.begin(); sit != cur.end(); sit++){
				printf("%07d\n", *sit);//注意id是7位的！
			}
		}
		else
			printf("Not Found\n");
	}

	system("pause");
	return 0;
}
