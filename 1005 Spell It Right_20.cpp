/*
注意：输入的字符串会长过long long -->最大 101位数
加起来之后是不会超过 int的-->最大 9*101=909
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
string s,res;
vector<string>e={ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int main(int argc, char const *argv[])
{
	cin>>s;
	int sum=0;
	for (int i = 0; i <s.size(); ++i)
		sum+=(s[i]-'0');
	
	res=to_string(sum);
	for (int i = 0; i < res.size(); i++){
		if (i != 0)cout << " ";
		cout << e[res[i] - '0'];
	}

	system("pause");
	return 0;
}