#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
long long int N,p;
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&p);
	std::vector<long long int> v(N);
	for (int i = 0; i <N; ++i)
		scanf("%d",&v[i]);
	
	sort(v.begin(), v.end());
	long long int M,lo=0,or_lo=0,hi=N-1,res=0,Max=0;

	while(or_lo<N){
		lo=or_lo;//~最小的数固定，找最大的
		M=v[lo]*p;//分界数

		int l=lo,h=hi,mid;
	
		while(l<h){//二分查找
			mid=(l+h)/2;
			if(v[mid]>M){h=mid-1;}
			else if(v[mid]<M){l=mid+1;}
			else break;
		}
		if(l==h){mid=l;}
		if(v[mid]>M)mid--;

		res=mid-lo+1;
		Max=max(res,Max);
		
		or_lo++;
	}
	cout<<Max<<endl;
	getchar();
	system("pause");
	return 0;
}