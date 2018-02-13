#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
string s,res;
map<char, int>m;
bool add(string s){
	int cur, forward = 0;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		m[s[i]]++;
		cur = 2 * (s[i] - '0') + forward;
		forward = cur / 10;
		res = to_string(cur % 10) + res;
		cur = cur / 10;
	}
	if (forward != 0)res = to_string(forward) + res;
	for (int i = 0; i < res.size(); i++){
		m[res[i]]--;
		if (m[res[i]] < 0)return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	cin >> s;
	if (add(s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << res << endl;
	system("pause");

	return 0;
}