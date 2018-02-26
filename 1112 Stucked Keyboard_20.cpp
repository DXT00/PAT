#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
int K;
string s;
std::map<char, int> m;//0-未访问，1-坏的，2-好的
std::map<char, bool> exist;
int main(int argc, char const *argv[])
{
	scanf("%d", &K);
	cin >> s;
	for (int i = 0; i <s.size();){


		if (m[s[i]] == 0){//没被访问过
			if (s.substr(i, K) == string(K, s[i])){
				m[s[i]] = 1;
				i = i + K;
			}
			else{
				m[s[i]] = 2;
				i++;
			}
		}
		else{
			if (m[s[i]] == 1){
				if (s.substr(i, K) != string(K, s[i])){
					m[s[i]] = 2;
					i++;
				}
				else{
					i = i + K;
				}
			}
			else
				i++;		
		}
	}
	string del, res;
	for (int i = 0; i <s.size();)
	{
		if (m[s[i]] == 1){
			if (exist[s[i]] == false){
				del += s[i];
				exist[s[i]] = true;
			}
			res += s[i];
			i = i + K;
		}
		else{
			res += s[i];
			i++;
		}
	}
	cout << del << endl;
	cout << res << endl;
	system("pause");
	return 0;
}