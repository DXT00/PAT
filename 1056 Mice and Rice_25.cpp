#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int Np,Ng;
int MAX=-1,MAX_i;
vector<int> weight,Rank;
vector<int> order,v;
queue<int> q;
bool cmp(int a,int b){
	return weight[a]>weight[b];
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&Np,&Ng);
	int N=Np;
	weight.assign(N,0);
	order.assign(N,0);
	Rank.assign(N,0);
	for (int i = 0; i <Np; ++i)
		scanf("%d",&weight[i]);
	for (int i = 0; i <Np; ++i){
		scanf("%d",&order[i]);
		q.push(order[i]);
	}
	int currank=(Np%Ng==0)?(Np/Ng+1):(Np/Ng+2);
	int cnt=0,MAX=-1,MAX_i;
	while(!q.empty()){
		int w=q.front();
		Rank[w]=currank;
		if(weight[w]>MAX){
			MAX=weight[w];
			MAX_i=w;
		}
		q.pop();
		cnt++;
		if(cnt%Ng==0||cnt==Np){
			q.push(MAX_i);
			MAX=-1;
			if(cnt==Np){
				Np=q.size();
				if(Np==1){
					Rank[q.front()]=1;
					break;
				}
				currank=(Np%Ng==0)?(Np/Ng+1):(Np/Ng+2);
				cnt=0;
			}
		}
	}
	for (int i = 0; i <Rank.size(); ++i){
		if(i!=0)printf(" ");
		printf("%d",Rank[i] );
	}
	system("pause");
	return 0;
}
