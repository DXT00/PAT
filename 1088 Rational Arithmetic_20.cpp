/*
注意：输入的两个数分母也可能=0！！（一样要处理）
求最大公约数一定要用辗转相除法，否则超时！！
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
struct Node
{
	long long up, down;
	long long integer;
	bool inf;
	Node(long long up, long long down) :up(up), down(down), inf(false){}
};
long long gcd(long long a, long long b){
	return (b == 0) ? abs(a) : gcd(b, a%b);
}
std::vector<Node> v(2, Node(0, 0));

void process(Node &a){
	if(a.down==0){a.inf=true;return;}

	long long y = gcd(a.up, a.down);
	a.up = a.up / y;
	a.down = a.down /y;

	bool neg = false;
	if (a.up*a.down< 0) neg = true;
	a.integer = a.up / a.down;

	a.up = a.up%a.down;
	if (a.integer != 0){
		a.up = abs(a.up);
		a.down = abs(a.down);
	}
	else{
		if (neg == true){
			a.up = -(abs(a.up));
			a.down = abs(a.down);
		}

	}
}
Node add(Node a, Node b){
	long long res_down = a.down*b.down;
	long long res_up = a.up*b.down + b.up*a.down;
	Node c = Node(res_up, res_down);
	process(c);
	return c;
}
Node dif(Node a, Node b){
	long long res_down = a.down*b.down;
	long long res_up = a.up*b.down - b.up*a.down;
	Node c = Node(res_up, res_down);
	process(c);
	return c;
}
Node mul(Node a, Node b){
	long long res_down = a.down*b.down;
	long long res_up = a.up*b.up;
	Node c = Node(res_up, res_down);
	process(c);
	return c;
}
Node div(Node a, Node b){

	long long res_down = a.down*b.up;
	long long res_up = a.up*b.down;
	Node c = Node(res_up, res_down);
	process(c);
	return c;
}
char op[4] = { '+', '-', '*', '/' };

void print(int k, Node res){
	Node a = Node(0, 0);
	bool neg;
	for (int i = 0; i <3; ++i)
	{
		neg = false;
		a = (i == 2) ? res : v[i];
		if(a.inf == true){ printf("Inf"); }
		else{
			if (a.integer<0 || a.up<0) neg = true;
			if (neg == true)
				printf("(");
			if (a.integer != 0 || (a.integer == 0 && a.up == 0))
				printf("%lld", a.integer);
			if (a.integer != 0 && a.up != 0)
				printf(" ");
			if (a.up != 0)
				printf("%lld/%lld", a.up, a.down);
			if (neg == true)
				printf(")");
		}

		if (i == 0)printf(" %c ", op[k]);
		if (i == 1)printf(" = ");
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i <2; ++i)
		scanf("%lld/%lld", &v[i].up, &v[i].down);

	vector<Node> res(4, Node(0, 0));
	res[0] = add(v[0], v[1]);
	res[1] = dif(v[0], v[1]);
	res[2] = mul(v[0], v[1]);
	res[3] = div(v[0], v[1]);
	process(v[0]);
	process(v[1]);
	for (int i = 0; i < res.size(); i++){
		print(i, res[i]);
	}
	system("pause");
	return 0;
}

