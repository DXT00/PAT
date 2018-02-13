#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
struct Node
{
	int id,score;
	string name;
};
int N,C;
char na[10];
vector<Node> v;
bool cmp1(Node a,Node b){
	return a.id<b.id;
}
bool cmp2(Node a,Node b){
	if(a.name!=b.name)return a.name<b.name;
	else
		return a.id<b.id;
}
bool cmp3(Node a,Node b){
	if(a.score!=b.score)return a.score<b.score;
	else
		return a.id<b.id;
}
int main(int argc, char const *argv[])
{
	cin>>N>>C;
	v.assign(N,Node());
	for (int i = 0; i <N; ++i){
		scanf("%d%s%d",&v[i].id,na,&v[i].score);
		v[i].name=string(na);
	}
	if(C==1)
		sort(v.begin(), v.end(),cmp1);
	else if(C==2)
		sort(v.begin(), v.end(),cmp2);
	else
		sort(v.begin(), v.end(),cmp3);
	for (int i = 0; i <v.size(); ++i)
		printf("%06d %s %d\n",v[i].id,v[i].name.c_str(),v[i].score);
	
	system("pause");
	return 0;
}