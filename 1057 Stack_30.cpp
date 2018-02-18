/*
需要采用树状数组+二分法

树状数组：能够在o(logn)的时间内进行对A[i]操作和统计A[0]+A[1]+A[2]+...A[i]的操作。

我们把A[i]记录为i的出现次数，那么统计sum=A[0]+A[1]+A[2]+...A[i]，就可以知道小于等于i的元素出现的次数。而PeekMedian操作中，是求n/2或者（n+1）/2的元素，即当sum等于n/2或者（n+1）/2时，i就是我们需要输出的元素

通过lowbit(i)把A[i]数组转化为C[i]数组求解

树状数组链接：
http://blog.csdn.net/jmlikun/article/details/50073925
https://www.cnblogs.com/hsd-/p/6139376.html
http://www.bubuko.com/infodetail-479552.html
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <set>
using namespace std;

#define manx 100005

int N,x;
stack<int> s;
int C[100005];//C[i]为i在stack s中的出现次数，s.push(i)-->C[i]+1,C[i+lowbit(i)]+1....C[maxn]+1
										//	s.pop()--->C[i]-1,C[i+lowbit(i)]-1....C[maxn]-1
										//只要C[i]变化，C[i]的所有父节点也会跟着变！-->即使用update()函数即可！
int lowbit(int i){return i&(-i);}
void update(int x,int add){
	for (int i = x; i < manx;i=i+lowbit(i))//i+lowbit(i)为i的父节点
	{
		C[i]+=add;
	}
}
int getsum(int x){//即求A[1]+A[2]+....+A[x]-->把A数组转化为C数组求和
	int res=0;
	for (int i = x;i>=1;i=i-lowbit(i))
		res+=C[i];
	
	return res;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 0; i <N; ++i)
	{
		char op[12];
		scanf("%s",op);
		if(op[1]=='o'){
			if(s.empty())printf("Invalid\n");
			else{
				printf("%d\n",s.top());
				update(s.top(),-1);
				s.pop();
			}
		}
		else if(op[1]=='u'){
			scanf("%d",&x);
			s.push(x);
			update(x,1);
		}
		else{//PeekMedian
			if(s.size()==0){
				printf("Invalid\n");
				continue;
			}
			int size=(s.size()%2==0)?s.size()/2:(s.size()+1)/2;
			int lo=1,hi=manx,mid;
			while(lo<hi){//二分法
				mid=(lo+hi)/2;
				int get=getsum(mid);
				
				if(get>=size)hi=mid;
				else{
					lo=mid+1;
				}
			}
			printf("%d\n",lo);
			
			
			
		}
	}
	system("pause");
	return 0;
}