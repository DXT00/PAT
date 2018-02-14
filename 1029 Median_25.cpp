#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long  a[2000005];
long long  Tnum=0,num,k=0;
int main(int argc, char const *argv[])
{
	for (long long  i = 0; i <2; ++i){
		scanf("%lld",&num);
		for (long long  j = 0; j <num; ++j){
			scanf("%lld",&a[k++]);
		}
	}

	sort(a,a+k);
	printf("%lld\n",a[(k-1)/2]);
	system("pause");
	return 0;
}