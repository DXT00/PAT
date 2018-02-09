#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
long long a, b;
string res, s;
int main(int argc, char const *argv[])
{
	scanf_s("%lld%lld", &a, &b);
	long long c = a + b;
	s = to_string(c);
	for (int i = s.size() - 1, cnt = 1; i >= 0; i--, cnt++){
		res = s[i] + res;
		if (cnt % 3 == 0 && i != 0 && s[i - 1] != '-')
			res = "," + res;
	}
	cout << res << endl;
	system("pause");
	return 0;
}