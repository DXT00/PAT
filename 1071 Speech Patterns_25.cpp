#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
string s, cur;
std::map<string, int> m;
std::map<string, int>::iterator it;
int main(int argc, char const *argv[])
{
	getline(cin, s);
	for (int i = 0; i <s.size(); ++i){
		if (isalnum(s[i])){
			s[i] = tolower(s[i]);
			cur += s[i];
		}
		if (!isalnum(s[i])||i==s.size()-1){
			if (cur.size() != 0){
				m[cur]++;
				cur = "";
			}
		}
	}
	int MAX = -1;
	string res;
	for (it = m.begin(); it != m.end(); it++){
		if (it->second>MAX){
			MAX = it->second;
			res = it->first;
		}
	}
	cout << res << " " << MAX << endl;
	system("pause");
	return 0;
}