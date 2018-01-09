#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int N,x,cnt=0,cnt1=0;
int already=0;
int judge(vector<int> &pos){
	int k=0,t;
	while(true){
		if(pos[0]!=0){
				t=pos[0];
				pos[0]=pos[t];
				pos[t]=t;
				cnt++;
				cnt1++;
		}
		else{
			//k=0;  //这里一定要注意！不要每次都重头开始找，会超时
					//每次交换后位置都是固定的，所以只要从上次的k开始向后找第一个pos[k]!=k的数即可！！
			if(cnt1+1+already==N)return cnt;
			while(pos[k]==k){
				k++;
			}
			if(k==N)return cnt;
			pos[0]=pos[k];
			pos[k]=0;
			cnt++;
		}	
	}
	return cnt;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	std::vector<int> pos(N);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d",&x);
		pos[x]=i;
		if(i==x)already++;
	}
	if (already==N)
	{
		printf("0\n");
	}
	else
		printf("%d\n",judge(pos) );
	
	getchar();
	system("pause"); 
	return 0;
}