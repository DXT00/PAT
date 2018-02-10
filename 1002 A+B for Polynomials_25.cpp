/*
使用了map,当然也可以用vector只是时间会长点
*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>
using namespace std;
int K, ex;
double cof;
std::map<int, double> m;
std::map<int, double>::iterator it;
int main(int argc, char const *argv[])
{
	for (int j = 0; j <2; ++j){
		scanf("%d", &K);
		for (int i = 0; i < K; ++i){
			scanf("%d%lf", &ex, &cof);
			m[ex] += cof;
			if (m[ex] == 0){ it = m.find(ex); m.erase(it); }
		}
	}
	cout << m.size();
	if (m.size() != 0){
		it = m.end(); it--;	
		for (; it != m.begin(); it--){
			if (it->second != 0)
				printf(" %d %.1lf", it->first, it->second);
		}
		it = m.begin();
		if (it->second != 0)
			printf(" %d %.1lf\n", it->first, it->second);			
	}
	system("pause");
	return 0;
}
