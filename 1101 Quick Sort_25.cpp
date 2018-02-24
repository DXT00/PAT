#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
long long N;
set<long long>s;
set<long long>::iterator it;
std::vector<long long> left_max,right_min,v;
int main(int argc, char const *argv[])
{
	scanf("%lld",&N);
	left_max.assign(N,0);
	right_min.assign(N,0);
	v.assign(N,0);
	for (long long i = 0; i <N; ++i)
		scanf("%lld",&v[i]);
	long long MAX=-1,MIN=10000000009;
	for (long long i = 0; i <N; ++i)
	{
		long long j=N-1-i;
		if(v[i]>MAX){
			MAX=v[i];
		}
		if(v[j]<MIN){
			MIN=v[j];
		}
		left_max[i]=MAX;
		right_min[j]=MIN;
	}
	for (long long i = 0; i < N; ++i)
	{
		if(v[i]>=left_max[i]&&v[i]<=right_min[i]){
			s.insert(v[i]);
		}
	}
	int size=s.size();
	printf("%d\n",size);
	for (it=s.begin();it!=s.end();it++)
	{
		if(it!=s.begin())printf(" ");
		printf("%lld",*it );
	}
	printf("\n");//不输出这个会格式错误！
	system("pause");
	return 0;
}
