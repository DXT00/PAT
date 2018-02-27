#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;
int N,sum;
string str;
set<int> s;
set<int>::iterator it;
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i = 0; i <N; ++i){
		cin>>str;
		sum=0;
		for (int j = 0; j <str.size(); ++j)
			sum+=str[j]-'0';
		
		s.insert(sum);
	}
	printf("%d\n",s.size() );
	for (it=s.begin();it!=s.end();it++)
	{
		if(it!=s.begin())printf(" ");
		printf("%d",*it);
	}
	system("pause");
	return 0;
}