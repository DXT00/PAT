#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std;

int N,K,x,y;
set<int>s;
set<int>::iterator it;
std::vector<bool> come(100002,false);
std::vector<int> v(100002,-1);
std::vector<int> query;
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 0; i <N; ++i){
		scanf("%d%d",&x,&y);
		v[x]=y;
		v[y]=x;
	}
	scanf("%d",&K);
	query.assign(K,0);
	for (int i = 0; i <K; ++i)
	{
		scanf("%d",&query[i]);
		come[query[i]]=true;
	}
	for (int i = 0; i <K; ++i)
	{
		if(v[query[i]]==-1)s.insert(query[i]);
		else{
			if(come[v[query[i]]]==false)s.insert(query[i]);
		}
	}
	printf("%d\n",s.size());
	for(it=s.begin();it!=s.end();it++){
		if(it!=s.begin())printf(" ");
		printf("%05d",*it );
	}
	system("pause");
	return 0;
}