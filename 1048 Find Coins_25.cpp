#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
using namespace std;
int N,sum,x;
bool flag=false;
vector<int> m(501,0);
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&sum);
	for (int i = 0; i <N; ++i){
		scanf("%d",&x);
		m[x]++;
	}
	for (int i = 1; i<sum&&i <=500; ++i){
		if(m[i]>0){
			m[i]--;
			if(sum-i<=500&&m[sum-i]>0&&i<=sum-i){
				cout<<i<<" "<<sum-i<<endl;
				flag=true;
				break;
			}
			else{
				m[i]++;
			}
		}
	}
	if(!flag)
		cout<<"No Solution"<<endl;
	system("pause");
	return 0;
}