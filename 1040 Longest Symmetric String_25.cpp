#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
string s;
int Max=1;
bool dp[1000][1000];
int main(int argc, char const *argv[])
{
	getline(cin,s);
	int N=s.size();
	for (int i = 0; i+1<N; ++i)
	{
		dp[i][i]=true;
		if(s[i]==s[i+1])dp[i][i+1]=true;
	}
	dp[N-1][N-1]=true;
	for (int len = 3; len <=N; ++len){//以长度为单位动规！
		for (int j = 0; j+len-1 <N; ++j){
			if(s[j]==s[j+len-1]&&dp[j+1][j+len-2]){
				dp[j][j+len-1]=true;
				Max=max(Max,len);
			}
			else
				dp[j][j+len-1]=false;
		
		}
	}
	cout<<Max<<endl;
	system("pause");
	return 0;
}