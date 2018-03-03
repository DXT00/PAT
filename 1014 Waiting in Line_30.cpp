#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <queue>
#define inf 99999999
using namespace std;
struct Node
{
	int topTime,endTime;
	queue<int> q;
	Node():topTime(0),endTime(0){}
};
int N,M,K,Q,x,index=1;;
std::vector<int> process;
std::vector<Node> windows;
std::vector<int> done;
std::vector<bool> sorry;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	process.assign(K+1,0);
	done.assign(K+1,0);
	sorry.assign(K+1,false);
	windows.assign(N+1,Node());
	for (int i = 1; i <=K; ++i)
		scanf("%d",&process[i]);

	for (int i = 1; i <=M; ++i)//一个window最多M人
	{
		for (int j = 1; j <=N; ++j)//N个windows
		{
			if(index<=K){
				if(windows[j].endTime>=540)
					sorry[index]=true;
				windows[j].q.push(process[index]);
				windows[j].endTime+=process[index];
				if(i==1){
					windows[j].topTime=windows[j].endTime;
				}
				done[index]=windows[j].endTime;
				index++;
			}
		}
	}
	//满了-->出队
	while(index<=K){
		int MIN=inf,MIN_i;
		for (int i = 1; i <=N; ++i)
		{
			if(windows[i].topTime<MIN){
				MIN=windows[i].topTime;
				MIN_i=i;
			}
		}
		windows[MIN_i].q.pop();//肯定是非空的
		windows[MIN_i].topTime+=windows[MIN_i].q.front();
		if(windows[MIN_i].endTime>=540)
			sorry[index]=true;
		windows[MIN_i].q.push(process[index]);
		windows[MIN_i].endTime+=process[index];

		done[index]=windows[MIN_i].endTime;
		index++;
	}
	for (int i = 0;i<Q; ++i)
	{
		scanf("%d",&x);
		if(sorry[x]==false)
			printf("%02d:%02d\n",(480+done[x])/60,(480+done[x])%60 );
		else
			printf("Sorry\n");
	}
	system("pause");
	return 0;
}
