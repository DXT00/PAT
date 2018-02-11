/*
要理解好题意！如：23 2
23的二进制为10111-->反转后为11101(即十进制的29)
因为23为素数，29也为素数-->Yes!


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int x, r;
int change(string s, int r){
	int ten = 1, res = 0;
	for (int i = s.size() - 1; i >= 0; i--){
		res += (s[i] - '0')*ten;
		ten *= r;
	}
	return res;
}
bool isPrime(int x){
	if (x == 1)return false;
	for (int i = 2; i < x; ++i)
	{
		if (x%i == 0)return false;
	}
	return true;
}
bool judge(int x, int r){
	int cur = x;
	string s;
	while (cur != 0){
		char c = (cur%r) + '0';
		s += c;
		cur = cur / r;
	}
	int y = change(s, r);
	return isPrime(x) && isPrime(y);
}
int main(int argc, char const *argv[])
{
	while (true){
		scanf("%d", &x);
		if (x >= 0){
			scanf("%d", &r);
			if (judge(x, r))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			break;
	}
	system("pause");
	return 0;
}