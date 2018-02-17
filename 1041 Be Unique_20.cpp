#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int N;
bool flag=false;
vector<int> origin;
int m[10005];
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	origin.assign(N,0);
	for (int i = 0; i <N; ++i){
		scanf("%d",&origin[i]);
		m[origin[i]]++;
	}
	for (int i = 0; i <N; ++i){
		if(m[origin[i]]==1){
			cout<<origin[i]<<endl;
			flag=true;
			break;
		}
	}
	if(!flag)
		cout<<"None"<<endl;
	system("pause");
	return 0;
}