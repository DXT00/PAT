/*
一定要用string处理，否则指数为9999时，若用double会溢出！！

*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
string s,res;
bool neg = false;
string cof, ex;
int main(int argc, char const *argv[])
{
	cin >> s;
	if (s[0] == '-')neg = true;
	for (int i = 1; i <s.size(); ++i){
		if (s[i] == 'E'){
			ex = s.substr(i + 1);
			break;
		}
		cof += s[i];
	}
	if (stoi(ex) < 0){
		res = "0." + string(-stoi(ex) - 1, '0') + cof[0] + cof.substr(2);
	}
	else{
		int wei = cof.substr(2).size();
		if (wei > stoi(ex))
			res = cof[0] + cof.substr(2, stoi(ex)) + '.' + cof.substr(2 + stoi(ex));
		else
			res = cof[0] + cof.substr(2) + string(stoi(ex) - wei, '0');
	}	
	if (neg)res = '-' + res;
	cout << res << endl;
	system("pause");
	return 0;
}
