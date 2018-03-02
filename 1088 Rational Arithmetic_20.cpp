/*
先用分数算加减乘除，如：-120/70
算完后，先上下约分 --> -12/7
通过分子分母相乘判断正负 ---> -12*7<0 ,所以neg=true;
之后把分子分母都加绝对值（因为已经知道正负了，输出只要判断标记neg就行，分子分母可以直接用正数）-->12/7 (neg=true)
求系数cof-->12/7=1 up=12%7=5 down=7
最后根据标记为neg、zero、inf输出

*/

#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
struct Node
{
	long long int up,down,cof;
	bool neg,zero,inf;
	Node():neg(false),zero(false),inf(false){}
};
Node a=Node();
Node b=Node();
long long int gcd(long long int a,long long int b){
	return (b==0)?abs(a):gcd(b,a%b);
}
std::vector<Node> v(4,Node());
char op[4]={'+','-','*','/'};
void process(Node &a){
	long long int w=gcd(a.up,a.down);//必须先约分了，再去用a.up*a.down相乘来判断正负！！否则会溢出！
	if(w!=0){//			测试用例：99999999/88888888 -999/2
		a.up/=w;
		a.down/=w;
	}
	
	if(a.up*a.down!=0){
		if(a.up*a.down<0)a.neg=true;
		else if(a.up*a.down>0)a.neg=false;

		
		a.up=abs(a.up);
		a.down=abs(a.down);
		a.cof=a.up/a.down;
		a.up=a.up%a.down;
	}
	else{
		if(a.down==0){
			a.inf=true;
		}
		else{//a.down!=0
			
			if(a.up==0)
				a.zero=true;
		}
	}
}
void add(Node a,Node b){
	v[0].up=a.up*b.down+b.up*a.down;
	v[0].down=a.down*b.down;
}
void dif(Node a,Node b){
	v[1].up=a.up*b.down-b.up*a.down;
	v[1].down=a.down*b.down;
}
void mul(Node a,Node b){
	v[2].up=a.up*b.up;
	v[2].down=a.down*b.down;
}
void div(Node a,Node b){
	v[3].up=a.up*b.down;
	v[3].down=a.down*b.up;
}
void print(Node a){//每次判断一个条件，一个一个来就不会乱了！
	if(a.inf==true){
		printf("Inf");
	}
	else{
		if(a.zero==true)
			printf("0");
		else{
			if(a.neg==true)printf("(-");
			if(a.cof!=0){
				printf("%lld",a.cof);
				if(a.up!=0){
					printf(" %lld/%lld",a.up,a.down);
				}
			}
			else{
				if(a.up!=0)
				printf("%lld/%lld",a.up,a.down );
			}
			if(a.neg==true)printf(")");
		}
	}
}
int main(int argc, char const *argv[])
{

	scanf("%lld/%lld",&a.up,&a.down);
	scanf("%lld/%lld",&b.up,&b.down);

	add(a,b);
	dif(a,b);
	mul(a,b);
	div(a,b);
	
	for (int i = 0; i <v.size(); ++i)
	{
		process(v[i]);
	}
	process(a);
	process(b);
	
	for (int i = 0; i <4; ++i)
	{
		print(a);
		printf(" %c ",op[i]);
		print(b);
		printf(" = ");
		print(v[i]);
		printf("\n");
	}
	system("pause");
	return 0;
}

/*
99999999/88888888 -999/2

*/
// #include <iostream>
// #include <vector>
// #include <stdio.h>
// #include <algorithm>
// #include <math.h>
// using namespace std;
// struct Node
// {
// 	long long up, down;
// 	long long integer;
// 	bool inf;
// 	Node(long long up, long long down) :up(up), down(down), inf(false){}
// };
// long long gcd(long long a, long long b){
// 	return (b == 0) ? abs(a) : gcd(b, a%b);
// }
// std::vector<Node> v(2, Node(0, 0));

// void process(Node &a){
// 	if(a.down==0){a.inf=true;return;}

// 	long long y = gcd(a.up, a.down);
// 	a.up = a.up / y;
// 	a.down = a.down /y;

// 	bool neg = false;
// 	if (a.up*a.down< 0) neg = true;
// 	a.integer = a.up / a.down;

// 	a.up = a.up%a.down;
// 	if (a.integer != 0){
// 		a.up = abs(a.up);
// 		a.down = abs(a.down);
// 	}
// 	else{
// 		if (neg == true){
// 			a.up = -(abs(a.up));
// 			a.down = abs(a.down);
// 		}

// 	}
// }
// Node add(Node a, Node b){
// 	long long res_down = a.down*b.down;
// 	long long res_up = a.up*b.down + b.up*a.down;
// 	Node c = Node(res_up, res_down);
// 	process(c);
// 	return c;
// }
// Node dif(Node a, Node b){
// 	long long res_down = a.down*b.down;
// 	long long res_up = a.up*b.down - b.up*a.down;
// 	Node c = Node(res_up, res_down);
// 	process(c);
// 	return c;
// }
// Node mul(Node a, Node b){
// 	long long res_down = a.down*b.down;
// 	long long res_up = a.up*b.up;
// 	Node c = Node(res_up, res_down);
// 	process(c);
// 	return c;
// }
// Node div(Node a, Node b){

// 	long long res_down = a.down*b.up;
// 	long long res_up = a.up*b.down;
// 	Node c = Node(res_up, res_down);
// 	process(c);
// 	return c;
// }
// char op[4] = { '+', '-', '*', '/' };

// void print(int k, Node res){
// 	Node a = Node(0, 0);
// 	bool neg;
// 	for (int i = 0; i <3; ++i)
// 	{
// 		neg = false;
// 		a = (i == 2) ? res : v[i];
// 		if(a.inf == true){ printf("Inf"); }
// 		else{
// 			if (a.integer<0 || a.up<0) neg = true;
// 			if (neg == true)
// 				printf("(");
// 			if (a.integer != 0 || (a.integer == 0 && a.up == 0))
// 				printf("%lld", a.integer);
// 			if (a.integer != 0 && a.up != 0)
// 				printf(" ");
// 			if (a.up != 0)
// 				printf("%lld/%lld", a.up, a.down);
// 			if (neg == true)
// 				printf(")");
// 		}

// 		if (i == 0)printf(" %c ", op[k]);
// 		if (i == 1)printf(" = ");
// 	}
// 	printf("\n");
// }
// int main(int argc, char const *argv[])
// {
// 	for (int i = 0; i <2; ++i)
// 		scanf("%lld/%lld", &v[i].up, &v[i].down);

// 	vector<Node> res(4, Node(0, 0));
// 	res[0] = add(v[0], v[1]);
// 	res[1] = dif(v[0], v[1]);
// 	res[2] = mul(v[0], v[1]);
// 	res[3] = div(v[0], v[1]);
// 	process(v[0]);
// 	process(v[1]);
// 	for (int i = 0; i < res.size(); i++){
// 		print(i, res[i]);
// 	}
// 	system("pause");
// 	return 0;
// }

