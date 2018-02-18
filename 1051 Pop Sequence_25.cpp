#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stack>
using namespace std;
int N, M, K, x,num,cnt;
bool flag;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d", &M, &N, &K);
	for (int i = 0; i <K; ++i){
		vector<int> v(N,0);
		stack<int>s;
		for (int j = 0; j <N; ++j)
			scanf("%d",&v[j]);
		num=1;
		flag=true;
		s.push(num);
		for (int j = 0; j <N; ++j){
			while(s.empty()||s.top()!=v[j]){
				if(!s.empty()&&s.top()>v[j]){
					flag=false;
					break;
				}
				num++;
				s.push(num);	
				if(s.size()>M){
					flag=false;
					break;
				}
			}
			if(!flag)break;
			s.pop();	
		}
		if(flag)printf("YES\n");	
		else printf("NO\n");
	}
	system("pause");
	return 0;
}