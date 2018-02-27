#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <math.h>
using namespace std;
int N;
std::vector<double> v;
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	v.assign(N,0);
	for (int i = 0; i <N; ++i){
		scanf("%lf",&v[i]);
	}
	sort(v.begin(), v.end());
	int i=2;
	double len=(v[0]+v[1])/2;
	
	while(i<N){
		len=(len+v[i])/2;
		i++;
	}
	cout<<int(len);
	system("pause");
	return 0;
}