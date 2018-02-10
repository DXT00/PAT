/*
遍历一遍就好了，压根就不用排序= =！！（尽管排序也可以通过）
*/
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int M,h1,m1,s1,h2,m2,s2;
char na[20];
struct Node
{
	string name;
	int in,out;
};
int MINin=90000,MAXout=-1,MIN_i,MAX_i;
int main(int argc, char const *argv[]){
	scanf("%d",&M);
	std::vector<Node> v(M,Node());
	for (int i = 0; i <M; ++i){
		scanf("%s%d:%d:%d%d:%d:%d",na,&h1,&m1,&s1,&h2,&m2,&s2);
		v[i].name=string(na);
		v[i].in=3600*h1+60*m1+s1;
		v[i].out=3600*h2+60*m2+s2;
		if(v[i].in<MINin){
			MINin=v[i].in;
			MIN_i=i;
		}
		if(v[i].out>MAXout){
			MAXout=v[i].out;
			MAX_i=i;
		}
	}
	cout<<v[MIN_i].name<<" "<<v[MAX_i].name<<endl;
	
	system("pause");
	return 0;
}


/*
方法二：排序（下策）
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int M,h1,m1,s1,h2,m2,s2;
char na[20];
struct Node
{
	string name;
	int in,out;
};
bool cmp1(Node a,Node b){return a.in<b.in;}
bool cmp2(Node a,Node b){return a.out>b.out;}
int main(int argc, char const *argv[]){
	scanf("%d",&M);
	std::vector<Node> v(M,Node());
	for (int i = 0; i <M; ++i){
		scanf("%s%d:%d:%d%d:%d:%d",na,&h1,&m1,&s1,&h2,&m2,&s2);
		v[i].name=string(na);
		v[i].in=3600*h1+60*m1+s1;
		v[i].out=3600*h2+60*m2+s2;
	}
	sort(v.begin(), v.end(),cmp1);
	cout<<v[0].name<<" ";
	sort(v.begin(), v.end(),cmp2);
	cout<<v[0].name<<endl;
	system("pause");
	return 0;
}
*/
