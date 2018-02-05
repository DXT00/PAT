/*
参考柳婼题解~https://www.liuchuo.net/archives/2110
使用阶乘逐个判断！！
好题！

*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N;
std::vector<vector<int> > res;
bool cmp(vector<int> a,vector<int> b){
	return a<b;
}

void find2(int N){
	for (int len = 12; len >=1; len--)//最长为12的阶乘，也即12个数相乘！（N<=2^31）
	{
		for (int start= 2; start<sqrt(N); start++)//最短两个数相乘，此时的start为sqrt(N),所以start最大值为sqrt(N)!!
		{
			int ans=1;
			for (int i = start; i <=start+len-1; ++i)
			{
				ans*=i;
			}
			if(N%ans==0){
				printf("%d\n%d",len,start);
				for (int j = start+1; j <=start+len-1; ++j)
				{
					printf("*%d",j);
				}
				return;
			}
		}
	}
	printf("1\n%d",N);//此数为质数时是它本身！！
}
int main(int argc, char const *argv[])
{
	cin>>N;

	find2(N);
	system("pause");
	return 0;
}


// void find(int N){
// 	int m=N;
// 	int MAX=0;
// 	int cnt_consecutive;
// 	for (int i = 2; i <N; ++i)
// 	{
// 		vector<int> cur;
// 		int pre_j=-1;
// 		cnt_consecutive=0;
// 		m=N;
// 		for (int j = i; j <=N; ++j)
// 		{
// 			if(m/j==0)break;
// 			if(m%j==0){
// 				m=m/j;
// 				cur.push_back(j);

// 				if(j==pre_j+1)
// 					cnt_consecutive++;
// 				pre_j=j;
// 			}
// 		}
// 		if(m!=1) cur.push_back(m);
// 		if(cnt_consecutive>MAX){
// 			MAX=cnt_consecutive;
// 			res.clear();
// 			res.push_back(cur);
// 		}	
// 		else if(cnt_consecutive==MAX)
// 			res.push_back(cur);
// 	}

// 	cout<<MAX+1<<endl;
// 	sort(res.begin(), res.end(),cmp);
// 	for (int i = 0; i <res.size(); ++i)
// 	{
// 		for (int j = 0; j <res[i].size(); ++j)
// 		{
// 			cout<<res[i][j]<<" ";
// 		}
// 		cout<<endl;
// 	}
// 	int cnt=0;
// 	for (int i = 1; i <res[0].size(); ++i)
// 	{
// 		if(res[0][i]=res[0][i-1]+1){
// 			if(cnt!=0)
// 				cout<<"*"<<res[0][i-1];
// 			else{
// 				cout<<res[0][i-1];
// 				cnt++;
// 			}
			
// 		}
// 	}
// }