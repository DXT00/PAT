#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
int start,N,x,y,z;
struct Node
{
	int add,data,next;	
};
std::vector<Node> v(100002);
vector<Node> res,remain,del;
std::map<int, int> m;
int main(int argc, char const *argv[])
{
	scanf("%d%d",&start,&N);
	for (int i = 0; i <N; ++i){
		scanf("%d%d%d",&x,&y,&z);
		v[x].add=x;
		v[x].data=y;
		v[x].next=z;
	}
	int cur=start;
	while(cur!=-1){
		res.push_back(v[cur]);
		cur=v[cur].next;
	}
	for (int i = 0; i <res.size(); ++i){
		m[abs(res[i].data)]++;
		if(m[abs(res[i].data)]==1)remain.push_back(res[i]);
		else if(m[abs(res[i].data)]>1){
			del.push_back(res[i]);		
		}
	}	
	for (int i = 0; i+1 < remain.size(); ++i)
		printf("%05d %d %05d\n",remain[i].add,remain[i].data,remain[i+1].add );
	if(remain.size()>0)
		printf("%05d %d %d\n",remain[remain.size()-1].add,remain[remain.size()-1].data,-1 );
	
	for (int i = 0; i+1 < del.size(); ++i)
		printf("%05d %d %05d\n",del[i].add,del[i].data,del[i+1].add );	
	if(del.size()>0)//注意一定要判断del是否为空！否则段错误！
		printf("%05d %d %d\n",del[del.size()-1].add,del[del.size()-1].data,-1 );
	system("pause");
	return 0;
}

