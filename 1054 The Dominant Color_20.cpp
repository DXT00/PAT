#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int M,N;
long long x;
std::map<long long, long long> m;
set<long long>s;
set<long long>::iterator it;
int main(int argc, char const *argv[])
{
	scanf("%d%d",&M,&N);
	for (int i = 0; i <N; ++i){
		for (int j = 0; j < M; ++j){
			scanf("%lld",&x);
			s.insert(x);
			m[x]++;
		}
	}
	int MAX=-1,res;
	for (it=s.begin();it!=s.end();it++){
		if(m[*it]>M*N/2){
			if(m[*it]>MAX){
				MAX=m[*it];
				res=*it;
			}
		}
	}
	cout<<res<<endl;
	system("pause");
	return 0;
}