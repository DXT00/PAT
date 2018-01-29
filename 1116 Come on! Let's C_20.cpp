#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int N,K,x,y;
std::vector<int> v(10001,0);
std::vector<bool> checked(10001,false);
bool isPrime(int x){
	if(x==1)return false;
	for (int i = 2; i <x ; ++i)
		if(x%i==0)return false;
	return true;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 1; i <=N; ++i)
	{
		scanf("%d",&x);
		v[x]=i;
	}
	scanf("%d",&K);
	for (int i = 0; i <K; ++i)
	{
		scanf("%d",&y);
		printf("%04d: ",y);
		if(v[y]==0)
			printf("Are you kidding?\n");
		else if(v[y]==1){
			if(checked[y]==false){
				printf("Mystery Award\n");
				checked[y]=true;
			}
			else
				printf("Checked\n");			
		}
		else if(isPrime(v[y])){
			if(checked[y]==false){
				printf("Minion\n");
				checked[y]=true;
			}
			else
				printf("Checked\n");			
		}
		else{
			if(checked[y]==false){
				printf("Chocolate\n");
				checked[y]=true;
			}
			else
				printf("Checked\n");		
		}
	}
	getchar();
	system("pause");
	return 0;
}