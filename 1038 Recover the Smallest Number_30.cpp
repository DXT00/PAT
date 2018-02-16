/*
直接用sort函数！！
bool cmp(string a, string b){
	return a+b<b+a;
}
也是可以排序的！！！

32 321 3214就不用全排列判断哪个小了！
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int N;
vector<string> v;
string res;
bool cmp(string a, string b){
	return a+b<b+a;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &N);
	v.assign(N, "");
	for (int i = 0; i <N; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); ++i)
	{
		res+=v[i];
	}

	int z = 0;
	while (res[z] == '0')z++;
	if(z==res.size())
		cout << 0 << endl;
	else
	cout << res.substr(z) << endl;
	system("pause");
	return 0;
}