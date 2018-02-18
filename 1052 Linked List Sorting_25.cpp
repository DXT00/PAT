#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int N,start,x,da,ne;
struct Node{
	int add,next,data;
};
vector<Node> v(100002,Node());
vector<Node> res;
bool cmp(Node a,Node b){
	return a.data<b.data;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&start);
	for (int i = 0; i <N; ++i){
		scanf("%d%d%d",&x,&da,&ne);
		v[x].add=x;
		v[x].data=da;
		v[x].next=ne;
	}
	int cur=start;
	while(cur!=-1){
		res.push_back(v[cur]);
		cur=v[cur].next;
	}
	if(res.size()!=0){
		sort(res.begin(), res.end(),cmp);
		printf("%d %05d\n",res.size(),res[0].add);
		for (int i = 0; i+1 <res.size(); ++i)
		{
			printf("%05d %d %05d\n",res[i].add,res[i].data,res[i+1].add);
		}printf("%05d %d %d\n",res[res.size()-1].add,res[res.size()-1].data,-1);
	}
	else
		printf("%d %d\n",0,-1);//不要漏了！
	system("pause");
	return 0;
}