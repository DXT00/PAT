#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int N,K,sum=0,S,D;
std::vector<int> distTotal;
std::vector<int> dist;
int main(int argc, char const *argv[])
{
	cin>>N;
	dist.assign(N+1,0);
	distTotal.assign(N+1,0);
	for (int i = 1; i <=N; ++i){
		scanf("%d",&dist[i]);
		distTotal[i]=sum;
		sum+=dist[i];

	}
	scanf("%d",&K);
	int cur;
	for (int i = 0; i <K; ++i){
		cur=0;
		scanf("%d%d",&S,&D);
		if(D<S)
			swap(S,D);
		cur=distTotal[D]-distTotal[S];
		cout<<min(cur,sum-cur)<<endl;
	}
	system("pause");
	return 0;
}