#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;
int N,base;
std::vector<int> res;
bool flag=true;
int main(int argc, char const *argv[])
{
	cin>>N>>base;
	int cur=N;
	while(cur!=0){
		res.push_back(cur%base);
		cur=cur/base;
	}
	int i=0,j=res.size()-1;
	while(i<=j){
		if(res[i]!=res[j]){
			flag=false;
			break;
		}else{
			i++;j--;
		}
	}
	if(flag){
		cout<<"Yes"<<endl;
		for (int i = 0; i <res.size(); ++i){
			if(i!=0)printf(" ");
			printf("%d",res[i]);
		}
		if(res.size()==0)
			printf("0\n");
	}
	else{
		cout<<"No"<<endl;
		for (int i = res.size()-1; i>=0;i--){
			if(i!=res.size()-1)printf(" ");
			printf("%d",res[i]);
		}
	}
	system("pause");
	return 0;
}