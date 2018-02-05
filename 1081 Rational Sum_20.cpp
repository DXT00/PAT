/*
求最大公约数的方法：（辗转相除法）
long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}
*/

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long N;
void process(long long &up, long long &down){//约分
	for (long long i = 2; i <= min(abs(up), abs(down));){
		if (up%i == 0 && down%i == 0){
			up = up / i;
			down = down / i;
		}
		else
			i++;
	}
}
int main(int argc, char const *argv[])
{
	long long mul = 1;//总分母
	cin >> N;
	long long up,down;
	string s;
	long long sum_up = 0;//总分子
	for (long long i = 0; i <N; ++i)
	{
		scanf("%lld/%lld", &up, &down);//注意此方法！
		
		if (i == 0){
			mul = down;
			sum_up = up;
		}
		else{		
			sum_up = sum_up*down + up*mul;
			mul *= down;
		}	
		process(sum_up, mul);//要一边加一边约分，否则sum_up会超出long long 范围！！-->浮点错误！（溢出）	
	}

	long long integer = sum_up / mul;
	long long res_up = sum_up%mul;
	long long res_down = mul;

	if (integer != 0 && res_up != 0)
		cout << integer << " " << res_up << "/" << res_down << endl;
	else if (integer == 0 && res_up != 0){
		cout << res_up << "/" << res_down << endl;
	}
	else if (integer != 0 && res_up == 0)
		cout << integer << endl;
	else
		cout << 0 << endl;

	system("pause");
	return 0;
}