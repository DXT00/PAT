#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
struct Node
{
	string name,s;
	Node(string name,string s):name(name),s(s){}
};
char origin[4]={'1','0','l','O'};
char change[4]={'@','%','L','o'};//1 0 l O
int N,num=0;
bool flag=false;
string na,str;
vector<Node> v;
int main(int argc, char const *argv[])
{
	cin>>N;
	for (int i = 0; i <N; ++i){
		cin>>na>>str;
		flag=false;
		for (int j = 0; j <str.size(); ++j){
			for (int k = 0; k <4; ++k){
				if(str[j]==origin[k]){
					str[j]=change[k];
					flag=true;
				}
			}
		}
		if (flag==true)
			v.push_back(Node(na,str));
	}
	if(v.size()>0){
		printf("%d\n",v.size());
		for (int i = 0; i <v.size(); ++i)
			printf("%s %s\n",v[i].name.c_str(),v[i].s.c_str());
	}
	else{
		if(N==1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n",N );
	}
	system("pause");
	return 0;
}