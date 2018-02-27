#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
int M,N,S;
std::vector<string> v(1005);
char name[25];
std::vector<string> res;
std::map<string, bool> m;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&M,&N,&S);
	for (int i = 1; i <=M; ++i)
	{
		scanf("%s",name);
		v[i]=string(name);
	}
	int cur=S;
	while(cur<=M){
		if(v[cur].size()!=0){
			if(m[v[cur]]==false){
				m[v[cur]]=true;
				res.push_back(v[cur]);
				cur=cur+N;
			}
			else
				cur++;
		}
	}
	if(res.size()==0)printf("Keep going...\n");
	else{
		for (int i = 0; i <res.size(); ++i)
		{
			printf("%s\n",res[i].c_str() );
		}
	}
	system("pause");
	return 0;
}