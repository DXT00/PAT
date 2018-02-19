#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int N,x,y,Q;
vector<set<int> > s(52);
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 1; i <=N; ++i){
		scanf("%d",&x);
		for (int j = 0; j <x; ++j){
			scanf("%d",&y);
			s[i].insert(y);
		}
	}
	scanf("%d",&Q);
	int Nc,Nt;
	set<int>::iterator it,its;
	for (int i = 0; i <Q; ++i)
	{	
		Nc=0;
		Nt=0;
		scanf("%d%d",&x,&y);
		for (it=s[x].begin();it!=s[x].end();it++){
			its=s[y].find(*it);
			if(its!=s[y].end()){
				Nc++;
			}
		}
		Nt=s[y].size()+s[x].size()-Nc;
		printf("%.1lf%\n", (double)Nc/Nt*100.0);
	}
	system("pause");
	return 0;
}