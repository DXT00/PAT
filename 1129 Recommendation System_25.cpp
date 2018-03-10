
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
struct Node
{
	int num, data;
	Node(int data,int num) :data(data),num(num){}
	bool operator <(const Node &a)const{//set是把小的数自动放在前头，所以要重载Node的<号！
		if (num != a.num)return num>a.num;
		else{
			return data<a.data;
		}
	}
};
int N, K, x, k = 0;
std::vector<Node> v;
set<Node> s;
int main(int argc, char const *argv[])
{
	scanf("%d%d", &N, &K);

	v.assign(N + 1, Node(-1,0));
	for (int i = 0; i <N; ++i)
	{
		scanf("%d", &x);
		


		if (i != 0){
			printf("%d:", x);
			k = 0;
			set<Node>::iterator it, its;


			for (it = s.begin(); it != s.end() && k<K; it++)
			{
				printf(" %d", it->data);
				k++;
			}
			printf("\n");

			its = s.find(Node(x,v[x].num));
			if (its != s.end()){
				s.erase(its);
			}
		}
		v[x].data = x;
		v[x].num++;
		s.insert(v[x]);

	}

	system("pause");
	return 0;
}

// #include <vector>
// #include <stdio.h>
// #include <algorithm>
// #include <iostream>
// #include <set>
// using namespace std;
// struct Node
// {
// 	int data;
// 	int num;
// 	Node(int data,int num):data(data),num(num){}
// 	bool operator < (const Node &a)const{//set是把小的数自动放在前头，所以要重载Node的<号！
// 		if(num!=a.num)return num>a.num;
// 		else
// 			return data<a.data;
// 	}
// };
// int N,K;
// std::vector<int> origin;
// std::vector<int> existed(100000,0);


// set<Node> s;
// set<Node>::iterator it;

// int main(int argc, char const *argv[])
// {
// 	scanf("%d%d",&N,&K);
// 	origin.assign(N,0);
// 	for (int i = 0; i <N; ++i)
// 		scanf("%d",&origin[i]);

	
// 	existed[origin[0]]++;
// 	s.insert(Node(origin[0],existed[origin[0]]));
// 	for (int i = 1; i <N; ++i)
// 	{
			
// 		printf("%d:",origin[i]);

// 		int cnt=0;
// 		for (it=s.begin();cnt<K&&it!=s.end();cnt++,it++)
// 		{
// 			printf(" %d",*it);
// 		}printf("\n");
		
// 		set<Node>::iterator its;
// 		its=s.find(Node(origin[i],existed[origin[i]]));
// 		if(its!=s.end()){
// 			s.erase(its);
// 			existed[origin[i]]++;
// 			s.insert(Node(origin[i],existed[origin[i]]));
// 		}
// 		else{
// 			existed[origin[i]]++;
// 			s.insert(Node(origin[i],existed[origin[i]]));
// 		}

		
	
// 	}
// 	system("pause");
// 	return 0;
// }

