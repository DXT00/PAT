#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int N;
struct Node
{
	string name,ID;
	int score;
	Node(string name,string ID,int score):name(name),ID(ID),score(score){}
};
bool cmp(Node a,Node b){
	return a.score>b.score;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	std::vector<Node> v;
	std::vector<Node> res;
	int g1,g2,x;
	char na[11];
	char id[11];
	for (int i = 0; i <N; ++i)
	{
		scanf("%s%s%d",na,id,&x);
		v.push_back(Node(string(na),string(id),x));
	}
		scanf("%d%d",&g1,&g2);

	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i <v.size(); ++i)
	{
		if(v[i].score>=g1&&v[i].score<=g2){
			res.push_back(v[i]);
		}
	}
	if(res.size()==0)
		printf("NONE\n");
	else
	{	
		for (int i = 0; i <res.size(); ++i)
		{
			printf("%s %s\n",res[i].name.c_str(),res[i].ID.c_str());
		}
	}
	getchar();
	system("pause");
	return 0;
}