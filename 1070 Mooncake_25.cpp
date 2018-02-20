#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node{
	double num,price;
};
int N,demand;
double x;
bool cmp(Node a,Node b){return a.price>b.price;}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&demand);
	vector<Node> v(N,Node());
	for (int i = 0; i <N; ++i)
		scanf("%lf",&v[i].num);
	
	for (int i = 0; i <N; ++i){
		scanf("%lf",&x);
		v[i].price=(double)x/v[i].num;
	}
	sort(v.begin(), v.end(),cmp);
	int cur=demand;
	double profit=0;
	for (int i = 0; i <v.size(); ++i){
		if(cur==0)break;
		if(cur>=v[i].num){
			profit+=v[i].price*v[i].num;
			cur=cur-v[i].num;
		}
		else{
			profit+=v[i].price*cur;
			cur=0;
		}
	}
	printf("%.2lf\n",profit);
	system("pause");
	return 0;
}