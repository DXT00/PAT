#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
int N,P,k,x,y,root,MaxBird=-1;
std::vector<int> v(10002,-1);
int findRoot(int x){
	while(v[x]!=-1){
		x=v[x];
	}
	return x;
}
void Union(int a,int b){
	int Roota=findRoot(a);
	int Rootb=findRoot(b);
	if(a!=b){
		v[Rootb]=Roota;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);

	for (int i = 0; i <N; ++i){
		scanf("%d",&k);
		for (int j = 0; j <k; ++j){

			scanf("%d",&x);
			MaxBird=max(MaxBird,x);
			if(j==0)root=x;
			else{
				Union(root,x);
			}
		}
	}
	int Tree=0;
	for (int i = 1; i <=MaxBird; ++i)
	{
		if(v[i]<0)Tree++;
	}
	printf("%d %d\n",Tree,MaxBird);
	scanf("%d",&P);
	for (int i = 0; i <P; ++i)
	{
		scanf("%d %d",&x,&y);
		if(findRoot(x)==findRoot(y))
			printf("Yes\n");
		else
			printf("No\n");
	}
	system("pause");
	return 0;
}