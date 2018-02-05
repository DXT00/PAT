#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
string s1, s2;
int main(int argc, char const *argv[])
{
	cin >> s1;
	cin >> s2;
	std::map<char, int> m;
	std::map<char, int>::iterator it;
	for (int i = 0; i <s1.size(); ++i)
	{
		m[s1[i]]++;
	}
	int miss = 0;
	int remain = 0;
	for (int i = 0; i <s2.size(); ++i)
	{
		m[s2[i]]--;
		if (m[s2[i]]<0)miss++;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		if (it->second>0)
			remain+=it->second;
	}
	if (miss>0)
		printf("No %d\n", miss);
	else
		printf("Yes %d\n", remain);
	system("pause");
	return 0;
}