#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;
int N,res_n;
long int S1=0,S2=0;
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	std::vector<long int> v(N);
	for (int i = 0; i <N; ++i)
		scanf("%d",&v[i]);
	
	sort(v.begin(),v.end());
	res_n=(N%2==0)?0:1;
	for (int i = 0; i <N/2; ++i)
	{
		S1+=v[i];
	}
	for (int i = N/2; i <N; ++i)
	{
		S2+=v[i];
	}
	cout<<res_n<<" "<<S2-S1<<endl;
	getchar();
	system("pause");
	return 0;
}