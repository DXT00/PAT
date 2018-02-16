#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int N,M,res=0;
vector<int> coin;
vector<int> product;
bool cmp(int a,int b){return a>b;}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	coin.assign(N,0);
	for (int i = 0; i <N; ++i)
		scanf("%d",&coin[i]);
	scanf("%d",&M);
	product.assign(M,0);
	for (int i = 0; i <M; ++i)
		scanf("%d",&product[i]);
	sort(coin.begin(), coin.end(),cmp);
	sort(product.begin(),product.end(),cmp);
	int c=0,p=0;
	while(c<N&&p<M&&coin[c]>0&&product[p]>0){
		res+=coin[c]*product[p];
		c++;p++;
	}
	
	 c=N-1,p=M-1;
	while(c>=0&&p>=0&&coin[c]<0&&product[p]<0){
		res+=coin[c]*product[p];
		c--;p--;
	}
	cout<<res<<endl;
	system("pause");
	return 0;
}