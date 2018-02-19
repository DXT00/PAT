#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
int K;
struct Node
{
	string s;
	int p, cnt, ex;
	string cof;
};
string s1, s2;
Node a = Node(), b = Node();
void change(Node &a){
	//找'.'的位置p！
	a.p=a.s.size();//默认在最后
	for (int i = 0; i <a.s.size(); ++i){
		if(a.s[i]=='.'){
			a.p=i;
			break;
		}
	}

	//找第一个非0数的位置cnt
	int i=0;
	while(a.s[i]=='0'||a.s[i]=='.')i++;
	a.cnt=i;

	//全0情况！
	if(a.cnt==a.s.size()){//-->就是0的情况，如0.00 0.0000 
		a.cof="0."+string(K,'0');//若K=2-->0.00*10^0
		a.ex=0;
		return;
	}

	//凑系数cof
	string co;
	int w = a.cnt;
	i=0;
	while(i<K){//K位有效数字
		if(a.s[w]!='.'){
			co+=(w<a.s.size())?a.s[w]:'0';
			i++;	
		}
		w++;
	}

	a.cof = "0." + co;
	a.ex =(a.cnt<a.p)? (a.p - a.cnt):(a.p - a.cnt+1);
}
int main(int argc, char const *argv[])
{
	scanf("%d", &K);
	cin >> a.s >> b.s;
	change(a);
	change(b);
	if (a.ex == b.ex&&a.cof == b.cof)
		printf("YES %s*10^%d\n", a.cof.c_str(), a.ex);
	else
		printf("NO %s*10^%d %s*10^%d",a.cof.c_str(), a.ex,b.cof.c_str(), b.ex);
		
	system("pause");
	return 0;
}
