#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
long long int x;
int N,L,H,v,t;
struct Node
{
	long long int num;
	int virtue;
	int talent;
	Node(long long int num,int virtue,int talent):num(num),virtue(virtue),talent(talent){}
};
bool cmp(Node a,Node b){
	if(a.virtue+a.talent!=b.virtue+b.talent)return(a.virtue+a.talent>b.virtue+b.talent);
	else
		if(a.virtue!=b.virtue)return a.virtue>b.virtue;
		else return a.num<b.num;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&L,&H);
	std::vector<Node> sage;
	std::vector<Node> notable;
	std::vector<Node> fool;
	std::vector<Node> other;

	for (int i = 0; i <N; ++i)
	{
		scanf("%lld%d%d",&x,&v,&t);
		if(v>=L&&t>=L){
			if(v>=H&&t>=H)
				sage.push_back(Node(x,v,t));
			else if(v>=H&&t<H)
				notable.push_back(Node(x,v,t));
			else if(t<H&&v<H&&v>=t)
				//if(v>=t)
					fool.push_back(Node(x,v,t));
			else
				other.push_back(Node(x,v,t));

		}
	}
	sort(sage.begin(), sage.end(),cmp);
	sort(notable.begin(), notable.end(),cmp);
	sort(fool.begin(), fool.end(),cmp);
	sort(other.begin(), other.end(),cmp);
	printf("%d\n",sage.size()+notable.size()+fool.size()+other.size());
	for (int i = 0; i <sage.size(); ++i)
	{
		printf("%lld %d %d\n",sage[i].num,sage[i].virtue,sage[i].talent );
	}
	for (int i = 0; i <notable.size(); ++i)
	{
		printf("%lld %d %d\n",notable[i].num,notable[i].virtue,notable[i].talent );
	}
	for (int i = 0; i <fool.size(); ++i)
	{
		printf("%lld %d %d\n",fool[i].num,fool[i].virtue,fool[i].talent );
	}
	for (int i = 0; i <other.size(); ++i)
	{
		printf("%lld %d %d\n",other[i].num,other[i].virtue,other[i].talent );
	}
	getchar();
	system("pause");
	return 0;
}