#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int N,K,hi;
struct Node
{
	string name;
	int height;
};
bool cmp(Node a,Node b){
	if(a.height!=b.height)return a.height>b.height;
	else
		return a.name<b.name;
}
int main(int argc, char const *argv[])
{	char na[10];
	scanf("%d%d",&N,&K);
	std::vector<Node> v(N);
	std::vector<vector<Node> > res;
	for (int i = 0; i <N; ++i)
	{
		scanf("%s%d",na,&hi);
		v[i].name=string(na);
		v[i].height=hi;
	}
	sort(v.begin(),v.end(),cmp);
	int index=0,d,n;
	for (int i = K-1; i>=0; i--)
	{
		d=1;
		std::vector<Node> cur;
		n=(i==K-1)?(N-(K-1)*(N/K)):N/K;

		cur.assign(n,Node());
		cur[n/2]=v[index++];

		while(true){
			if(n/2-d>=0){
				cur[n/2-d]=v[index++];
			}
			else break;
			if(n/2+d<n){
				cur[n/2+d]=v[index++];
			}
			else break;			
			d++;
		}
		res.push_back(cur);
	}
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			if(j!=0)cout<<" ";
			cout<<res[i][j].name;
		}
		printf("\n");
	}
	getchar();
	system("pause");
	return 0;
}