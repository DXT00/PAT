/*
求最大公约数的方法：（辗转相除法）
long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
long long N;
struct Node
{
	long long up, down;
};

std::vector<Node> v;
long long gcd(long long a, long long b){
	return (b == 0) ? a : gcd(b, a%b);
}
int main(int argc, char const *argv[])
{
	scanf("%lld", &N);
	v.assign(N, Node());
	for (long long i = 0; i <N; ++i){
		scanf("%lld/%lld", &v[i].up, &v[i].down);
	}
	long long res_up = v[0].up, res_down = v[0].down;
	for (long long i = 1; i <N; ++i)
	{
		res_up = res_up*v[i].down + v[i].up*res_down;
		res_down = res_down*v[i].down;
		long long w = (abs(res_up)>abs(res_down)) ? gcd(abs(res_up), abs(res_down)) : gcd(abs(res_down), abs(res_up));
		res_up /= w;
		res_down /= w;
	}
	long long cof = res_up / res_down;
	if (cof != 0){
		printf("%lld", cof);
		if (res_up%res_down != 0)
			printf(" %lld/%lld\n", abs(res_up%res_down), res_down);
	}
	else{
		if (res_up%res_down != 0)
			printf("%lld/%lld\n", res_up%res_down, res_down);
		else
			printf("0\n");
	}
	system("pause");
	return 0;
}
