#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stdio.h>
using namespace std;
int N,M;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	std::vector<int> res(100,0);//记录每一层的叶子结点数
	std::vector<int> level(N,0);//记录每个节点所在的层数
	std::vector<vector<int> > v(100);
	int node,k,x,maxlevel=-1;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d%d",&node,&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&x);
			v[node].push_back(x);		
		}
	}
	cout<<v[1][0]<<endl;
	//bfs
	queue<int> q;
	level[1]=0;
	q.push(1);
	while(!q.empty()){
		int w=q.front();
		q.pop();
		maxlevel=max(maxlevel,level[w]);
		if(v[w].size()==0){res[level[w]]++;}
		else{
			for (int j = 0; j <v[w].size(); ++j)
			{
				q.push(v[w][j]);
				level[v[w][j]]=level[w]+1;
			}
		}
	}
	cout<<res[0];
	for (int i = 1; i <=maxlevel; ++i)
	{
		cout<<" "<<res[i];
	}cout<<endl;
	getchar();
	system("pause");
	return 0;
}




// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;
// struct Node
// {
// 	//int data;
// 	int child;
// 	int next;
// 	Node():child(0),next(0){}
// };
// int N,M;
// int main(int argc, char const *argv[])
// {	int first,K,x,pre;
	
// 	scanf("%d%d",&N,&M);
// 	std::vector<Node> v(N+1,Node());
// 	for (int i = 0; i <M; ++i)
// 	{
// 		scanf("%d",&first);
// 		//cout<<"f"<<v[1].child<<endl;
// 		scanf("%d",&K);
// 		for (int j = 0; j < K; ++j)
// 		{
// 			scanf("%d",&x);
// 			if(j==0){
// 				v[first].child=x;
// 				pre=x;
// 			}
// 			else{
// 				v[pre].next=x;
// 				pre=x;
// 			}
// 		}
// 	}
// 	//cout<<v[1].next<<endl;
// 	//count
// 	int le=0,leaves=0,root=1,end=1;
// 	std::vector<int> level(100,0);
// 	queue<int> q;
// 	q.push(1);
// 	while(!q.empty()){
// 		int w=q.front();
// 		q.pop();
// 		//cout<<w<<endl;
// 		if(v[w].child==0){level[le]++;}
// 		else{
// 			q.push(v[w].child);
// 			int cur=v[w].child;
// 			while(v[cur].next!=0){
// 				q.push(v[cur].next);
// 				cur=v[cur].next;
// 			}
// 			if(w==end){
// 				end=cur;
// 				le++;
// 			}
// 		}//else		
// 	}//while
	
// 	for (int i = 0; i <=le; ++i)
// 	{
// 		if(i==0){
// 			cout<<level[i];
// 		}
// 		else
// 		cout<<" "<<level[i];
// 	}
// 	cout<<endl;
// 	getchar();
// 	system("pause");
// 	return 0;
// }
