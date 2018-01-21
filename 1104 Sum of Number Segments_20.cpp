#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[])
{
	double res=0.0;
	int N;
	cin>>N;
	double v[100001];
	// for (int i = 0; i <N; ++i)
	// 	scanf("%lf",&v[i]);
	
	for (int i = 1; i <=N; ++i)
	{	
			cin>>v[i];
			res=res+(double)i*(N-i+1)*v[i];//!!!坑啊-->必须加上double
			//或者写成v[i]*i*(N-i+1)-->应该是根据第一个数，此处为v[i]来决定类型！！
	}
	printf("%.2f",res);
	getchar();
	system("pause");
	return 0;
}