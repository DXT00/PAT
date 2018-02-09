#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
long long a, b;
string res, s;
int main(int argc, char const *argv[])
{
	scanf("%lld%lld", &a, &b);
	s = to_string(a + b);
	for (int i = s.size() - 1, cnt = 1; i >= 0; i--, cnt++){
		res = s[i] + res;
		if (cnt % 3 == 0 && i != 0 && s[i - 1] != '-')
			res = "," + res;
	}
	cout << res << endl;
	system("pause");
	return 0;
}
