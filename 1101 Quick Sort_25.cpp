#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
int N;

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	std::vector<long int> v(N,0);
	std::vector<long int> MIN(N,0);
	std::vector<long int> MAX(N,0);
	std::vector<long int> res;
	for (int i =  0; i <N; ++i)
	{
		scanf("%d",&v[i]);
	}
	int i,j;
	MAX[0]=-1;
	MIN[N-1]=1000000001;
	long int maxx=-1,minn=1000000001;
	for (int i = 0; i+1<N; ++i)//N>=2
	{
		maxx=max(v[i],maxx);
		MAX[i+1]=maxx;

		minn=min(v[N-i-1],minn);
		MIN[N-i-2]=minn;
	}
	for (int i = 0; i <N; ++i)
	{
		if(v[i]>=MAX[i]&&v[i]<=MIN[i]){

			res.push_back(v[i]);
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n",res.size());
	for (int i = 0; i <res.size(); ++i)
	{
		if(i!=0)printf(" ");
		printf("%d", res[i]);
	}printf("\n");
	getchar();
	system("pause");
	return 0;
}