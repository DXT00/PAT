#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
struct Node
{
	int data;
	int num;
	Node(int data,int num):data(data),num(num){}
	bool operator < (const Node &a)const{//set是把小的数自动放在前头，所以要重载Node的<号！
		if(num!=a.num)return num>a.num;
		else
			return data<a.data;
	}
};
int N,K;
std::vector<int> origin;
std::vector<int> existed(100000,0);


set<Node> s;
set<Node>::iterator it;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&K);
	origin.assign(N,0);
	for (int i = 0; i <N; ++i)
		scanf("%d",&origin[i]);

	
	existed[origin[0]]++;
	s.insert(Node(origin[0],existed[origin[0]]));
	for (int i = 1; i <N; ++i)
	{
			
		printf("%d:",origin[i]);

		int cnt=0;
		for (it=s.begin();cnt<K&&it!=s.end();cnt++,it++)
		{
			printf(" %d",*it);
		}printf("\n");
		
		set<Node>::iterator its;
		its=s.find(Node(origin[i],existed[origin[i]]));
		if(its!=s.end()){
			s.erase(its);
			existed[origin[i]]++;
			s.insert(Node(origin[i],existed[origin[i]]));
		}
		else{
			existed[origin[i]]++;
			s.insert(Node(origin[i],existed[origin[i]]));
		}

		
	
	}
	system("pause");
	return 0;
}

