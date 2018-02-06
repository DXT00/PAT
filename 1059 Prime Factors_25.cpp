#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
long long N;
set<long long> s;
std::map<long long,long long> m;
bool isPrime(long long x){
	if(x==1)return false;
	for (long long i = 2; i<x; ++i)
		if(x%i==0)return false;
	return true;
}
std::vector<long long> res;
int main(int argc, char const *argv[])
{
	scanf("%lld",&N);
	long long x=N;

	for (long long i = 2; i <=N;)
	{
		if(isPrime(i)&&x%i==0){
			s.insert(i);
			m[i]++;
			x/=i;
			if(x==1)break;
		}
		else
			i++;
			
	}
	set<long long>::iterator it;
	printf("%lld=",N);
	if(N==1)printf("1");//一定不要漏了N=1的情况！
	else{
		for (it=s.begin();it!=s.end();it++)
		{	
			if(it!=s.begin())printf("*");
			printf("%lld",*it);
			if(m[*it]>1)
				printf("^%lld",m[*it]);
		}
	}
	
	system("pause");
	return 0;
}