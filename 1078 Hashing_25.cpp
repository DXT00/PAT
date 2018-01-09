#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
//------------------------------------
//注意！！1不是质数也不是合数！！
//二次探测时，跳步k只要检测到 k<表长，即while(k<TSize)即可
//--------------------------------------
int M,N,x,pos,k=1,poss,TSize;
std::vector<int> v;
bool prime(int M){
	if(M==1)return false;
	for(int i=2;i<M;i++){
		if(M%i==0)return false;
	}
	return true;
}
int find_prime(int M){
	if(prime(M))return M;
	else{
		for(int i=M+1;;i++){
			if(prime(i))return i;
		}
	}
}
int position(int x){
		k=1;
		pos=x%TSize;
		if(v[pos]==-1){v[pos]=x;return pos;}
		else{
			while(k<TSize){
				if(v[(pos+k*k)%TSize]==-1){
					v[(pos+k*k)%TSize]=x; return (pos+k*k)%TSize;
				}			
				k++;
			}
		}
		return -1;	
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&M,&N);
	TSize=find_prime(M);
	//cout<<TSize<<endl;
	v.assign(TSize,-1);
	for (int i = 0; i <N; ++i)
	{
		scanf("%d",&x);
		 poss=position(x);
		 if(poss==-1)printf("-");
		 else printf("%d",poss);
		 if(i!=N-1) printf(" ");
	}
	printf("\n");
	getchar();
	system("pause");
	return 0;
}