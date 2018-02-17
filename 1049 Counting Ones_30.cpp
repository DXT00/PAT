#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <math.h>
using namespace std;
int res = 0;
string s;
int main(int argc, char const *argv[])
{
	cin >> s;
	for (int i = s.size() - 1; i >= 0; i--){
		
		if (s[i] - '0' == 0)
			res += ((s.substr(0, i) == "") ? 0 : stoi(s.substr(0, i)))*pow(10, s.size() - 1 - i);
		
		else if (s[i] - '0' == 1)
			res += ((s.substr(0, i) == "") ? 0 : stoi(s.substr(0, i)))*pow(10, s.size() - 1 - i) + ((s.substr(i + 1)=="")?0: stoi(s.substr(i + 1))) + 1;
	
		else
			res += (((s.substr(0, i) == "") ? 0 : stoi(s.substr(0, i))) + 1)*pow(10, s.size() - 1 - i);
	}
	cout << res << endl;
	system("pause");
	return 0;
}