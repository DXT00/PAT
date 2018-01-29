#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
using namespace std;
int P,M,N,grade;

struct Node
{
	string name;
	int Gp,Gmid,Gfinal,G;
	Node():Gp(-1),Gmid(-1),Gfinal(-1),G(-1){}
};
bool cmp(Node a,Node b){
	if(a.G!=b.G)return a.G>b.G;
	else
		return a.name<b.name;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&P,&M,&N);
	char na[20];
	std::map<string, Node> m;
	for (int i = 0; i <P; ++i){
		scanf("%s%d",na,&grade);
		m[string(na)].name=string(na);
		m[string(na)].Gp=grade;		
	}
	for (int i = 0; i <M; ++i)
	{
		scanf("%s%d",na,&grade);
		m[string(na)].name=string(na);
		m[string(na)].Gmid=grade;		
	}
	for (int i = 0; i <N; ++i)
	{
		scanf("%s%d",na,&grade);
		m[string(na)].name=string(na);
		m[string(na)].Gfinal=grade;	
	}
	std::map<string, Node>::iterator it;
	int curm,curf;
	std::vector<Node> res;
	for (it=m.begin();it!=m.end();it++)
	{
		if(it->second.Gp>=200){
			curm=(it->second.Gmid==-1)?0:it->second.Gmid;	
			curf=(it->second.Gfinal==-1)?0:it->second.Gfinal;	
			it->second.G=(it->second.Gmid>it->second.Gfinal)?(round(curm*0.4+curf*0.6)):it->second.Gfinal;
			if(it->second.G>=60)
			res.push_back(it->second);
		}
	}
	sort(res.begin(),res.end(),cmp);
	for (int i = 0; i <res.size(); ++i)
		printf("%s %d %d %d %d\n",res[i].name.c_str(),res[i].Gp,res[i].Gmid,res[i].Gfinal,res[i].G);

	getchar();
	system("pause");
	return 0;
}